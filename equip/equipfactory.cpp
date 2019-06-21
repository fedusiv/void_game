#include "equipfactory.h"
#include <QSharedPointer>

EquipFactory * EquipFactory::instance = nullptr;


Equip * EquipFactory::createWeapon(int level)
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
                static_cast<float>(obj["size"].toDouble()),
                obj["req"].toString()
                );

}
/*
 * desc : create cloth with choosen cloth type
 * @param : equipment cloth type,
 * @param: int level
 * @return: pointer to crated equip cloth
 */
Equip *EquipFactory::createCloth(EquipClothType type, int level)
{
    QJsonObject obj;


    obj = JsonReader::getInstance()->clothBodyRead(type, level);

    int size = obj["size"].toInt();
    int id = ParamsCounting::randomSimpleCount(size);
    QJsonArray array = obj["cloth"].toArray();
    QJsonValue val = array.at(id);
    obj = val.toObject();

    return new Cloth(
                obj["name"].toString(),
                obj["level"].toInt(),
                obj["desc"].toString(),
                static_cast<float>(obj["armor"].toDouble()),
                static_cast<float>(obj["size"].toDouble()),
                obj["req"].toString(),
                type
                );




}

Equip *EquipFactory::createCloth(int level)
{
    //int type = ParamsCounting::randomSimpleCount(EquipClothType::NotCloth);
    int type = 1;   // temporary, commonly must be used line upper
    return createCloth(static_cast<EquipClothType>(type), level);
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
        equip = createCloth(level);
        break;
    case EquipType::Usable:
        break;
    }

    return equip;
}

Equip *EquipFactory::createClothEquip(EquipClothType type, int level)
{
    return createCloth(type, level);
}
