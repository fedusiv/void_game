#include "equip.h"

Equip::Equip(int level) :  _Level(level), _Name("nameless"), _Size(1), _Equipped(false)
{

}

Equip::Equip(QString name) : _Name(name), _Size(1), _Equipped(false)
{

}

int Equip::getLevel()
{
    return _Level;
}

int Equip::getSize()
{
    return _Size;
}

QString Equip::getName()
{
    return _Name;
}

void Equip::setName(QString name)
{
    _Name = name;
}

QString Equip::getInfo()
{
    return _Info;
}

QString Equip::getDesc()
{
    return _Desc;
}

bool Equip::isEquipped()
{
    return _Equipped;
}




