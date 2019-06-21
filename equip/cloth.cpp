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

Cloth::Cloth(QString name, int level, QString desc, int armor, int size, QString req) :
    Equip(name, desc, req, level, EquipType::Cloth, size) ,
    _Armor(armor)
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
