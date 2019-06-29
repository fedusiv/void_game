#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <QString>

class PlayerStats
{
public:
    // Main constructor
    PlayerStats();
    // send array of pointers to main 4 params
    int **  getStats();
    // send current level of player
    int getLevel();

    float Health(){return _Health;}
    float Energy(){return _Energy;}


private:
    // Main 3 parameters, that influence to other stuff
    int _Strength;
    int _Agility;
    int _Intelligence;

    int _Level;

    float _Health_max; // maximum health
    float _Health;     // current Player's Health

    float _Energy_max;// maxium energy points
    float _Energy;    //currenrt Player's Energy

    // array of pointers to main 3 params, to easily send to another objects
    int * _statsArray[3];
};

#endif // PLAYERSTATS_H
