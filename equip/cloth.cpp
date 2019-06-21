#include "cloth.h"
#include <QDebug>

Cloth::Cloth(int level) : Equip ( level )
{
    if( level == 0)
    {
        setName("Old mage robe");
        _Desc = "Oh, dat smell";
        _Type = EquipType::Cloth;
        _ClothType = EquipClothType::Body;
        _Level = 0;
    }
}

Cloth::Cloth(QString name, int level, QString desc, float armor, float size, QString req, EquipClothType type) :
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
