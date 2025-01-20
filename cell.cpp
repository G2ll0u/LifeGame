#include "cell.h"
#include <iostream>
using namespace std;

Cell::Cell(int x, int y, bool Obstacle, bool Alive){
    this->x=x;
    this->y=y;
    Check=false;
    Change=false;
    this->Alive=Alive;
    this->Obstacle=Obstacle;
    
}

bool Cell::PrepareChange(){
    Change = true;
    return true;
}

void Cell::ChangeStatement(){
    Change = false;
    setAlive();
}
bool Cell::getObstacle(){
    return Obstacle;
}

bool Cell::getAlive(){
    return Alive;
}

void Cell::setAlive(){
    Alive=!Alive;
}

bool Cell::getChange(){
    return Change;
}

void Cell::ChangeCheck(){
    Check=!Check;
}

bool Cell::getCheck(){
    return Check;
}

// Méthode pour vérifier les voisins de la cellule
bool Cell::CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur) {
    int aliveNeighbours = 0;

    // On parcout les voisins de la cellule
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0)) { // Ignore sa propre position
                int nx = (x + j + longueur) % longueur; // Coordonnée x du voisin
                int ny = (y + i + largeur) % largeur;   // Coordonnée y du voisin

                // Vérifie si le voisin est une cellule vivante
                if ((Cells[ny][nx])->getAlive()) {
                    aliveNeighbours++;
                }
            else {
            }
            }
        }
    }
    ChangeCheck();
    // Si la cellule vivante a moins de 2 voisins vivants ou plus de 3 voisins vivants --> cellule morte
    if (getAlive() && (aliveNeighbours < 2 || aliveNeighbours > 3)) {
        return PrepareChange();
    }
    // Si la cellule morte a exactement 3 voisins vivants --> cellule vivante
    else if (!getAlive() && aliveNeighbours == 3) {
        return PrepareChange();
    } else {
        return false;
    }
}
