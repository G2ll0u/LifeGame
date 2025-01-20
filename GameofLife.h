#include "gestion_creation_fichier.h"
#include "grid.h"
#include "affichage.h"


class GameofLife{
    private:
    int iteration;
    int temps;
    bool mode;
    string lien_fichier;
    string nom_dossier;
    string lien_dossier;
    int cellSize;
    public:
    GameofLife(int iteration, bool mode, string lien_fichier, string lien_dossier, string nom_dossier);
    GameofLife(int iteration, int temps, bool mode, string lien_fichier, int cellSize);
    void runGame();
};