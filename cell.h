#include <vector>
#ifndef CELL
#define CELL


class Cell{
    private:
    int x;
    int y;
    bool Change;
    bool Check;
    bool Alive;
    bool Obstacle;
    
    public:
    Cell(int x, int y, bool Obstacle, bool Alive);
    bool getObstacle();
    bool getChange();
    bool PrepareChange();
    bool getAlive();
    void setAlive();
    void ChangeStatement();
    void ChangeCheck();
    bool getCheck();
    bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur);

};

#endif
