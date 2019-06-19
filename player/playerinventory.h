#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include <QList>
#include <QString>
#include <QSharedPointer>

#include "equip/equip.h"

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
        info = equip->getInfo();
        desc = equip->getDesc();
        size = equip->getSize();
        equiped = equip->isEquipped();

    }
    //~EquipStatus(){delete this;}
    QString info;
    QString desc;
    QString name;
    int size;
    bool equiped;
};

class PlayerInventory
{
public:
    PlayerInventory();
    void recalculateInventorySize(int level);
    inventoryStatus * getInventoryStatus();

    void addToInventory(Equip * equip);
    // returns all info about equiped
    QSharedPointer<EquipStatus>  getEquipmentInfo(int id);

private:
   int _InventorySize_max;
   int _InventorySize;
   inventoryStatus _Inv_status;
   QList<Equip *> currentInventoryList;         // qlist stored pointers to  equipment
   QList<QString> currentInventoryNameList;     // qlist stored names of equipment for easily access of names to gui


};

#endif // PLAYERINVENTORY_H
