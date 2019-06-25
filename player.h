#ifndef PLAYER_H
#define PLAYER_H

#include "player/playerstats.h"
#include "player/playerrace.h"
#include "player/playerclass.h"
#include "player/playerinventory.h"
#include "equip/equip.h"
#include "returncodes.h"

#include <QDebug>


class Player
{
public:
    Player();


    int ** getPlayerStats();
    int getPlayerLevel();
    float getPlayerCurrentHealth();
    QString getPlayerRaceName();
    QString getPlayerClassName();
    int getPlayerStep();
    inventoryStatus * getInventory();
    // returns string information about equipment
    QSharedPointer<EquipStatus> getGivenEquipInformation(int id);
    // equip or disequip choosen element
    EquipReturnCode equipEquipmentElement( int id );
    // remove given equipment from inventory
    void inventoryRemoveEquip( int id);

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
