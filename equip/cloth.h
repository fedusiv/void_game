#ifndef CLOTH_H
#define CLOTH_H

#include "equip.h"

class Cloth : public Equip
{
public:

    Cloth(QString name, int level, QString desc, float armor, float size, MainPlayerStats * req, EquipClothType type);
    ~Cloth()override;
    // return current cloth equip type
    EquipClothType getClothType() override;
    QString getStringType() override;       // return for gui equip type
    float getArmor() override;              // return armor value
protected:
    EquipClothType _ClothType;
    float _Armor; // Armor parametr of Cloth
};

#endif // CLOTH_H
