#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <QString>

class PlayerStats
{
public:
    // Main constructor
    PlayerStats(int str = 1, int agil = 1, int ener = 1, int vital = 1);
    // send array of pointers to main 4 params
    int **  getStats();
    // send current level of player
    int getLevel();

    int Health(){return _Health;}


private:
    // Main 4 parameters, that influence to other stuff
    int _Strength;
    int _Agility;
    int _Energy;
    int _Vitality;

    int _Level;

    int _Health_max; // maximum health
    int _Health;     // current Player's Health

    // array of pointers to main 4 params, to easily send to another objects
    int * _statsArray[4];
};

#endif // PLAYERSTATS_H
