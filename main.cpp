#include <SFML/Graphics.hpp>
#include "GameofLife.h"
#include "grid.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <filesystem>

using namespace std;


int main() {
    string nom_fichier;
    cout << "Entrez le nom de votre fichier .txt (sans l'extension)" << endl;
    cin >> nom_fichier;
    nom_fichier += ".txt"; // Ajout de l'extension .txt.
    ifstream fichier(nom_fichier);
    if (!fichier.is_open()) { // Vérification si le fichier existe.
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        return 1;
    }

    int choix;
    cout << "Mode console (0) ou graphique (1) ?" << endl;
    cin >> choix;
    if (choix != 0 && choix != 1) { 
        cerr << "Erreur : Choix invalide." << endl; // Erreur si le choix n'est pas 0 ou 1.
        return 1;
    }
    int NbIterations;

    cout << "Nombre d'itérations (minimum 1) : " << endl;
    cin >> NbIterations;
    if (NbIterations < 1){
        cerr << "Erreur : Le nombre d'itération doit être plus élevé que 0." << endl; // Erreur si le nombre d'itérations est inférieur à 1.
        return 1;
    }

    if (choix == 1) {
// Mode graphique.
        int temps;
        cout << "Temps (en ms) entre les itérations : " << endl;
        cin >> temps;
        if (temps < 0){
            cerr << "Erreur : Le temps doit être positif." << endl; // Erreur si le temps est négatif.
            return 1;
        }
        int cellSize;
        cout << "Taille d'une cellule (minimum 2) : " << endl; // Une taille de 1 marche en théorie, mais est trop petite pour être visible.
        cin >> cellSize;
        if (cellSize < 2){
            cerr << "Erreur : La taille d'une cellule doit être plus élevé que 1." << endl;
            return 1;
            }
        GameofLife game(NbIterations, temps, true, nom_fichier, cellSize);
        game.runGame();
        }
    else {
// Mode console.
        string nom_dossier, lien_dossier;
        cout << "Entrez le nom du dossier que vous voulez créer" << endl;
        cin >> nom_dossier;
        cout << "Voulez-vous créer un dossier dans le dossier courant (0) ou un autre (1) ?" << endl;
        cin >> choix;
        if (choix == 0) {
            lien_dossier = "";
        } else {
            cout << "Entrez le lien du dossier que vous voulez créer" << endl;
            cin >> lien_dossier;
        }
        GameofLife game(NbIterations, false, nom_fichier, lien_dossier, nom_dossier);
        game.runGame();
        }
    return 0;}
