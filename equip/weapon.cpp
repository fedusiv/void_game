#include "weapon.h"

Weapon::Weapon(int level) : Equip(level)
{
    if( level == 0)
    {
        setName("Wood Stick");
        _Info = "Mage stick";
        _Desc = "Stinky Stick of old fart";
    }

}

Weapon::Weapon(QString name):  Equip(name)
{

}

Weapon::~Weapon()
{
    delete this;
}
