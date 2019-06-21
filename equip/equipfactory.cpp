#include "equipfactory.h"
#include <QSharedPointer>

EquipFactory * EquipFactory::instance = nullptr;


Equip *EquipFactory::createWeapon(int level)
{
    QJsonObject obj =  JsonReader::getInstance()->weaponRead(level);
    int size = obj["size"].toInt();
    int id = ParamsCounting::randomSimpleCount(size);
    QJsonArray array = obj["weapon"].toArray();
    QJsonValue val = array.at(id);
    obj = val.toObject();

    return new Weapon(
                obj["name"].toString(),
                obj["level"].toInt(),
                obj["desc"].toString(),
                obj["hands"].toInt(),
                obj["size"].toInt(),
                obj["req"].toString()
                );

}

Equip *EquipFactory::createCloth(int level)
{

}


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
        equip = createWeapon(level);
        break;
    case EquipType::Components:
        break;
    case EquipType::Cloth:
        equip = new Cloth(level);
        break;
    case EquipType::Usable:
        break;
    }

    return equip;
}
