#ifndef EQUIPFACTORY_H
#define EQUIPFACTORY_H

#include "equip.h"
#include "weapon.h"
#include "cloth.h"
#include "memory"
/*
 *
 * Factory pattern class to create Equipment, this class communicate with other stuff
 *  Singleton
 */
class EquipFactory
{
private:
    static EquipFactory * instance;
    EquipFactory(){}
public:
    static EquipFactory * getInstance()
    {
        if( instance == nullptr)
        {
            instance = new EquipFactory();
        }
        return instance;
    }

    // create equip
    Equip * createEquip(EquipType type, int level);

};



#endif // EQUIPFACTORY_H