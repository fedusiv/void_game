#include "cloth.h"

Cloth::Cloth(int level) : Equip ( level )
{
    if( level == 0)
    {
        setName("Old mage robe");
        _Info = "Bad defence, just hide your shame";
        _Desc = "Oh, dat smell";
        _Type = EquipType::Cloth;
        _ClothType = EquipClothType::Body;
        _Level = 0;
    }
}

EquipClothType Cloth::getClothType()
{
    return _ClothType;
}
