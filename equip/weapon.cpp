#include "weapon.h"

Weapon::Weapon(int level) : Equip(level)
{
    if( level == 0)
    {
        setName("Wood Stick");
        _Info = "Mage stick";
        _Desc = "Stinky Stick of old fart";
        _Type = EquipType::Weapon;
        _Hands = 1;
        _Level = 0;
    }

}

Weapon::Weapon(QString name):  Equip(name)
{

}

Weapon::~Weapon()
{
    qDebug() << "Weapon deleted " + _Name ;
}
