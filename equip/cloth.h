#ifndef CLOTH_H
#define CLOTH_H

#include "equip.h"

class Cloth : public Equip
{
public:
    Cloth(int level);
    // return current cloth equip type
    EquipClothType getClothType() override;
protected:
    EquipClothType _ClothType;
};

#endif // CLOTH_H
