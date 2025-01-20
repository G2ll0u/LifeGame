#include "affichage.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Affichage::Affichage(Grid &grille, int cellSize)
: grille(grille), cellSize(cellSize) {
    window = new sf::RenderWindow(sf::VideoMode(grille.getWidth() * cellSize, grille.getHeight() * cellSize), "Game of Life");
}

bool Affichage::windowIsOpen(){
    return window->isOpen();
}

void Affichage::FermetureManuelle(){
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) // Fermeture de la fenêtre si l'utilisateur clique sur la croix.
            window->close();
    }
}

void Affichage::renderGrid() {
// Fonction permettant de colorier les cases sur la grille en fonction de l'état d'une cellule.

    int x, y;
    window->clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    auto& cells = grille.getCells();
    for (y = 0; y < grille.getHeight() ; ++y) {
// Parcours de ligne en ligne.
        for (x = 0; x < grille.getWidth(); ++x) {
// Parcours de case en case dans la ligne actuelle.    
            if ((cells[y][x])->getAlive()) {
                cell.setPosition(x * cellSize, y * cellSize); // Position de la cellule.
                if ((cells[y][x]->getObstacle())){
                    cell.setFillColor(sf::Color::Green); // Obstacle Vivant
                    window->draw(cell);
                }
                else{
                    cell.setFillColor(sf::Color::White); // Cellule Vivante
                    window->draw(cell);
                }
            }
            else{

                cell.setPosition(x * cellSize, y * cellSize); // Position de la cellule.
                if ((cells[y][x]->getObstacle())){
                    cell.setFillColor(sf::Color::Red); // Obstacle Mort
                    window->draw(cell);
                }

                 
            }
            // Affichage de la cellule.
            
        }
    }window->display();
}
