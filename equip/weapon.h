#ifndef WEAPON_H
#define WEAPON_H

#include "equip.h"

class Weapon : public Equip
{
public:
    Weapon(int level);
    Weapon(QString name);
    Weapon(QString name, int level);
    Weapon(QString name, int level, QString desc, int hands, float size, QString req);
    ~Weapon() override;

    int getHands() override { return _Hands;}
    QString getStringType() override;       // return for gui equip type

protected:
    int _Hands; // shows how many hands require for using this weapon
};

#endif // WEAPON_H
