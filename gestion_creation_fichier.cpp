#include "gestion_creation_fichier.h"

GestionCreationFichier::GestionCreationFichier(string lien_dossier, string nom_dossier, Grid &grille) 
    : lien_dossier(lien_dossier), nom_dossier(nom_dossier), grille(grille) {
    if (mkdir((lien_dossier+nom_dossier).c_str(),0777)==0){ // Création du dossier. (0777 représente les permissions de lire, écrire et exécuter.)
        cout << "Dossier créé" << endl;
    }
    else{
        cerr << "Erreur lors de la création du dossier" << endl; // Erreur si le dossier n'a pas pu être créé.
    }
}
void GestionCreationFichier::createandwritefile(int etape){
// Fonction permettant de créer un fichier et d'y écrire la grille.

    string filename=to_string(etape);
    ofstream file(lien_dossier+nom_dossier + "/" + nom_dossier + "_out_" + filename+".txt" );
    if (file.is_open()) { 
    auto& cells = grille.getCells();
    for (int y = 0; y < grille.getHeight(); ++y) {
// Parcours de ligne en ligne.
        for (int x = 0; x < grille.getWidth(); ++x) {
// Parcours de case en case dans la ligne actuelle.
            if ((cells[y][x])->getAlive()) { 
                if ((cells[y][x]->getObstacle())){
                    file << "3 "; // Obstacle Vivant.
                }
                else{
                    file << "1 "; // Cellule Vivante.
                }
            } else {
                if ((cells[y][x]->getObstacle())){
                    file << "2 "; // Obstacle Mort.
                }
                else{
                    file << "0 "; // Cellule Morte.
                }
            }
        }
        file << endl; // Passage à la ligne suivante.
    }
        file.close();
    } else {
        cerr << "Erreur lors de la création du fichier." << endl; // Erreur si le fichier n'a pas pu être créé.
    }
}