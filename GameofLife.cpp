#include "GameofLife.h"
#include "affichage.h"
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <ctime>
#include <cstdlib>


using namespace std;

GameofLife::GameofLife(int iteration, bool mode, string lien_fichier, string lien_dossier, string nom_dossier){
    this->iteration=iteration;
    this->mode=mode;
    this->lien_fichier=lien_fichier;
    this->lien_dossier=lien_dossier;
    this->nom_dossier=nom_dossier;
}
GameofLife::GameofLife(int iteration, int temps, bool mode, string lien_fichier, int cellSize){
    this->iteration=iteration;
    this->temps=temps;
    this->mode=mode;
    this->lien_fichier=lien_fichier;
    this->cellSize=cellSize;
}

void GameofLife::runGame(){
    
    Grid Grille(lien_fichier);

    if (mode) {
// Mode graphique.
        Affichage fenetre(Grille, cellSize);      
        fenetre.renderGrid();
        while (fenetre.windowIsOpen() && iteration > 0) {
            fenetre.FermetureManuelle();

            if (iteration > 0) {
                    if (!Grille.Iteration()){
                        iteration = 1; // Arrêt si aucune cellule n'a changé.
                    }
                    fenetre.renderGrid(); // Actualisation de l'affichage.
                    iteration--;
                    if (iteration == 0){
                        cout << "End" << endl; // Fin de la simulation.
                    }
                    sf::sleep(sf::milliseconds(temps)); // Attente entre chaque itération pour laisser le temps de voir.
                
            }
            
        }
    } else {
// Mode console.
        GestionCreationFichier gestion(lien_dossier, nom_dossier, Grille);
        int etape=0;
        while (etape < iteration) {
            etape++;
            bool change = Grille.Iteration(); 
            gestion.createandwritefile(etape); // Création du fichier et écriture de la grille.
            if (!change){
                        etape = iteration; // Arrêt si aucune cellule n'a changé.
                    }
            if (etape == iteration){
                        cout << "End" << endl; // Fin de la simulation.
            }
        }
    }
}
    