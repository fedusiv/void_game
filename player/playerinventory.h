#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include <QList>
#include <QString>
#include <QSharedPointer>

#include "equip/equip.h"
#include "returncodes.h"

typedef struct inventoryStatus{
    int * max;
    int  * size;
    QList<QString> * list;
}inventoryStatus;


class EquipStatus{
    public:
    EquipStatus(Equip * equip)
    {
        name = equip->getName();
        desc = equip->getDesc();
        size = equip->getSize();
        equiped = equip->isEquipped();
        level = equip->getLevel();
    }
    ~EquipStatus(){}
    QString desc;
    QString name;
    int size;
    int level;
    bool equiped;
};

class Equipped
{
public:
    Equipped(){}
    // using qlist needs cause player could wear a few in a time
    QList<Equip *>  _weapon;
    QList<Equip *>  _head;
    QList<Equip *>  _body;
    QList<Equip *>  _arms;
    QList<Equip *>  _legs;
    QList<Equip *>  _feet;
    QList<Equip *>  _accesorize;
    // better to change this method, cause it is brute force
    bool takeOffEquip ( Equip * equip);// take off equip

};

class PlayerInventory
{
public:
    PlayerInventory();
    void recalculateInventorySize(int level);
    // return information to gui about current inventory status and condition
    inventoryStatus * getInventoryStatus();
    // add element to inventory
    void addToInventory(Equip * equip);
    // returns all info about choosen equip
    QSharedPointer<EquipStatus>  getEquipmentInfo(int id);
    // equip inventory element or disequip
    EquipReturnCode equipEquipmentElement(int player_level, int ** type_array, int id);
    // remove equipment from inventory
    void removeFromInventory( int id );


private:
   Equipped * equipped;                         // object manipulate with equipped stuff
   int _InventorySize_max;
   int _InventorySize;
   inventoryStatus _Inv_status;
   QList<Equip *> currentInventoryList;         // qlist stored pointers to  equipment
   QList<QString> currentInventoryNameList;     // qlist stored names of equipment for easily access of names to gui


   void equipWeapon(Equip * equip);             // equip given weapon
   void equipCloth (Equip * cloth);             // equip given cloth
   void equipClothBody( Equip * cloth );        // equip given body cloth


};

#endif // PLAYERINVENTORY_H
