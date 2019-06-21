#include "equip.h"

Equip::Equip(int level) :  _Level(level), _Name("nameless"), _Size(1.0), _Equipped(false)
{
    // set required points to zero
    for ( int i = 0; i < 4; i++) _RequiredPoints[i] = 0 ;
}

Equip::Equip(QString name) : _Name(name), _Size(1.0), _Equipped(false)
{
    // set required points to zero
    for ( int i = 0; i < 4; i++) _RequiredPoints[i] = 0 ;
}

Equip::Equip(QString name, QString desc, QString req, int level, EquipType type,  float size) :
    _Level(level), _Name(name),
    _Size(size), _Desc(desc),
    _Equipped(false), _Type(type)
{
    // convert qsrting requirments type note to int array
    for ( int i = 0; i < 4; i++)
    {
        _RequiredPoints[i] = req.at(i).unicode() - 0x30;    // 0x30 '0' symbol in ascii
    }
}

int Equip::getLevel()
{
    return _Level;
}

float Equip::getSize()
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

void Equip::setEquipped(bool status)
{
    _Equipped = status;
}

EquipType Equip::getEquipType()
{
    return _Type;
}

EquipReturnCode Equip::checkRequirments(int player_level, int **type_points)
{
    // equipment need to be equipped
    if ( player_level <  _Level )
        return EquipReturnCode::LEVEL_ERROR; // not enough level

    for ( int i = 0; i < 4; i++)
    {
        if( *(type_points[i]) < _RequiredPoints[i] ) return EquipReturnCode::POINTS_ERROR;
    }

    return EquipReturnCode::SUCCESS;
}




