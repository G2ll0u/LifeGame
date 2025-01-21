#include "cell.h"
#include <iostream>

using namespace std;

int main()
{
    /*Test Constructeurs*/
    Cell cell1(0, 0, true, false);
    Cell cell2(1, 0, false, true);
    
    if (cell1.getAlive() == false && cell2.getAlive() == true)
    {
        cout << "[OK] État bien attribué." << endl;
    }
    else
    {
        cout << "[FAIL] État mal attribué." << endl;
    }
    if(cell1.getObstacle() == true && cell2.getObstacle() == false){
        cout << "[OK] Obstacle bien attribué." << endl;
    }
    else{
        cout << "[FAIL] Obstacle mal attribué." << endl;
    }
    /*Test de vérification de passage de la cellule*/
    cell2.ChangeCheck();
    if (cell2.getCheck() == true)
    {
        cout << "[OK] Cellule vérifiée." << endl;
    }
    else
    {
        cout << "[FAIL] Vérification de la cellule impossible." << endl;
    }
    /*Test Changement d'état*/
    cell2.PrepareChange();
    if (cell2.getChange() == true)
    {
        cout << "[OK] Changement d'état préparé." << endl;
    }
    else
    {
        cout << "[FAIL] Changement d'état non préparé." << endl;
    }
    cell2.ChangeStatement();
    if (cell2.getAlive() == false)
    {
        cout << "[OK] Changement d'état effectué." << endl;
    }
    else
    {
        cout << "[FAIL] Changement d'état non effectué." << endl;
    }
}
