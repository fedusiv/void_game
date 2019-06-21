#ifndef CLOTH_H
#define CLOTH_H

#include "equip.h"

class Cloth : public Equip
{
public:
    Cloth(int level);
    Cloth(QString name, int level, QString desc, int armor, int size, QString req);
    ~Cloth()override;
    // return current cloth equip type
    EquipClothType getClothType() override;
protected:
    EquipClothType _ClothType;
    int _Armor; // Armor parametr of Cloth
};

#endif // CLOTH_H
