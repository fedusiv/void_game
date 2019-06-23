#ifndef WEAPON_H
#define WEAPON_H

#include "equip.h"

class Weapon : public Equip
{
public:
    Weapon(int level);
    Weapon(QString name);
    Weapon(QString name, int level);
    Weapon(QString name, int level, QString desc, int hands, float size, QString req, float dmg);
    Weapon(QString name, int level, QString desc, int hands, float size, QString req, float dmg, Skill * skill);
    ~Weapon() override;

    int getHands() override { return _Hands;}
    QString getStringType() override;       // return for gui equip type
    float getDamage() override { return _Damage;}

protected:
    int _Hands; // shows how many hands require for using this weapon
    float _Damage; // damage of current weapon
};

#endif // WEAPON_H
