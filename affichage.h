#include <SFML/Graphics.hpp>
#include "grid.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <filesystem>

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

class Affichage{
    private:
    int cellSize;
    Grid &grille;
    sf::RenderWindow* window;
    public:
    Affichage(Grid &grille, int cellSize);
    bool windowIsOpen();
    void FermetureManuelle();
    void renderGrid();
};
#endif