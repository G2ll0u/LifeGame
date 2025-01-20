#include "grid.h"
#include <filesystem>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sys/stat.h>
#include <string>

#ifndef FICHIER
#define FICHIER

class GestionCreationFichier{
    private:
    string lien_dossier;
    string nom_dossier;
    Grid& grille;
    public:
    GestionCreationFichier(string lien_dossier, string nom_dossier, Grid &grille);
    void createandwritefile(int etape);
};
#endif