#include "equipfactory.h"
#include <QSharedPointer>

EquipFactory * EquipFactory::instance = nullptr;

/* desc: Create Equip object
 *  @param: type of Equipment
 *  @param level of equipment
 *  @return pointer to Equip
*/
Equip *EquipFactory::createEquip(EquipType type, int level)
{
    Equip * equip = nullptr;
    switch(type)
    {
    case EquipType::Weapon:
        equip = new Weapon(level);
        break;
    case EquipType::Components:

        break;
    case EquipType::Cloth:
        break;
    case EquipType::Usable:
        break;
    }

    return equip;
}
