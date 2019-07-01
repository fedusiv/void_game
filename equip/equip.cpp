#include "equip.h"

Equip::Equip(QString name, QString desc, MainPlayerStats * req, int level, EquipType type,  float size) :
    _Level(level), _Name(name),
    _Size(size), _Desc(desc),
    _Equipped(false), _RequiredPoints(req),
    _Type(type)
{

    _Skill = nullptr;
    delete []  req;
}

// constructor with skill initilize
Equip::Equip(QString name, QString desc, MainPlayerStats * req, int level, EquipType type, Skill * skill,  float size) :
    _Level(level), _Name(name),
    _Size(size), _Desc(desc),
    _Equipped(false), _RequiredPoints(req),
    _Type(type), _Skill(skill)

{

    delete []  req;
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
/*
 * desc : checking if player can equip this item
 * @param : player_level
 * @param : information about player's Main Stats
 * @return : result code
 */
EquipReturnCode Equip::checkRequirments(int player_level, MainPlayerStats * type_points)
{
    // equipment need to be equipped
    if ( player_level <  _Level )
        return EquipReturnCode::LEVEL_ERROR; // not enough level

    if ( ! type_points->check(_RequiredPoints) )
        return  EquipReturnCode::POINTS_ERROR;

    return EquipReturnCode::SUCCESS;
}

MainPlayerStats *Equip::getRequirments()
{
    return _RequiredPoints;
}

// return pointer to skill of equip
Skill *Equip::getSkill()
{
    return _Skill;
}




