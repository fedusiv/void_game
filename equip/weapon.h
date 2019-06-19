#ifndef WEAPON_H
#define WEAPON_H

#include "equip.h"

class Weapon : public Equip
{
public:
    Weapon(int level);
    Weapon(QString name);
    Weapon(QString name, int level);
    ~Weapon();
};

#endif // WEAPON_H
