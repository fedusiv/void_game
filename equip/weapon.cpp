#include "weapon.h"

Weapon::Weapon(QString name, int level, QString desc, int hands, float size, MainPlayerStats * req, float dmg) :
    Equip(name, desc, req, level, EquipType::Weapon, size) ,
    _Hands(hands), _Damage(dmg)
{

}

Weapon::Weapon(QString name, int level, QString desc, int hands, float size, MainPlayerStats * req, float dmg, Skill * skill) :
    Equip(name, desc, req, level, EquipType::Weapon, skill, size ) ,
    _Hands(hands), _Damage(dmg)
{

}

Weapon::~Weapon()
{
    qDebug() << "Weapon deleted " + _Name ;
}

QString Weapon::getStringType()
{
    return "Weapon";
}
