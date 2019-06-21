#ifndef EQUIPFACTORY_H
#define EQUIPFACTORY_H

#include "equip.h"
#include "weapon.h"
#include "cloth.h"
#include "memory"
#include "json_reader.h"
#include "player/paramscounting.h"

/*
 *
 * Factory pattern class to create Equipment, this class communicate with other stuff
 *  Singleton
 */
class EquipFactory
{
private:
    static EquipFactory * instance;
    Equip * createWeapon(int level);    // creating weapon with exactly given level
    Equip * createCloth(int level);     // creating cloth with exactly given level
    Equip * createCloth(EquipClothType type, int level); // create exactly given type of cloth
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
    // create exactly given type of cloth
    Equip * createClothEquip(EquipClothType type, int level);

};



#endif // EQUIPFACTORY_H
