#ifndef PLAYER_H
#define PLAYER_H

#include "player/playerstats.h"
#include "player/playerrace.h"
#include "player/playerclass.h"
#include "player/playerinventory.h"

#include <QDebug>


class Player
{
public:
    Player();


    int ** getPlayerStats();
    int getPlayerLevel();
    int getPlayerCurrentHealth();
    QString getPlayerRaceName();
    QString getPlayerClassName();
    int getPlayerStep();
    inventoryStatus * getInventoryStatus();

private:
    // private classes for main params of player
    PlayerStats * Stats;
    PlayerRace * Race;
    PlayerClass * Class;

    // player inventory class
    PlayerInventory * Inventory;
    // counter of step how far away player from start
    int _Step;
};

#endif // PLAYER_H
