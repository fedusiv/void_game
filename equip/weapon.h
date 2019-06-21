#ifndef WEAPON_H
#define WEAPON_H

#include "equip.h"

class Weapon : public Equip
{
public:
    Weapon(int level);
    Weapon(QString name);
    Weapon(QString name, int level);
    Weapon(QString name, int level, QString desc, int hands, int size, QString req);
    ~Weapon() override;

    int getHands() override { return _Hands;}

protected:
    int _Hands; // shows how many hands require for using this weapon
};

#endif // WEAPON_H
