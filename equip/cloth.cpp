#include "cloth.h"
#include <QDebug>


Cloth::Cloth(QString name, int level, QString desc, float armor, float size, MainPlayerStats *req, EquipClothType type) :
    Equip(name, desc, req, level, EquipType::Cloth, size) ,
    _ClothType(type), _Armor(armor)
{

}

Cloth::~Cloth()
{
    qDebug() << "Cloth deleted " + _Name;
}

EquipClothType Cloth::getClothType()
{
    return _ClothType;
}

QString Cloth::getStringType()
{
    QString s;
    switch ( _ClothType ) {
    case EquipClothType::Head :
    s = "Head";
    break;

    case EquipClothType::Body :
     s = "Body";
    break;

    case EquipClothType::Arms :
     s = "Arms";
    break;

    case EquipClothType::Legs :
     s = "Legs";
    break;

    case EquipClothType::Feet :
     s = "Feet";
    break;

    case EquipClothType::Accessorize :
     s = "Accessorize";
    break;
    }
    return s;
}

float Cloth::getArmor()
{
    return  _Armor;
}
