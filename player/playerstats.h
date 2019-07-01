#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <QString>
#include "common_types.h"

class PlayerStats
{
public:
    // Main constructor
    PlayerStats();
    // send array of pointers to main 4 params
    MainPlayerStats *  getStats();
    // send current level of player
    int getLevel();

    float Health(){return _Health;}
    float Energy(){return _Energy;}


private:

    MainPlayerStats *  mainStats;

    int _Level;

    float _Health_max; // maximum health
    float _Health;     // current Player's Health

    float _Energy_max;// maxium energy points
    float _Energy;    //currenrt Player's Energy
};

#endif // PLAYERSTATS_H
