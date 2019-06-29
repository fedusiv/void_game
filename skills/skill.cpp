#include "skill.h"

/*
 * Creating new skill
 * cost goes as qstring cause it is converted from json, and in constructor it converts to array
 */
Skill::Skill(QString name, QString desc, SkillTypes type, int id, int * cost) :
    _Name(name), _Desc(desc), _Type(type), _Id(id), _Binded(nullptr)
{

    _Cost[0] = cost[0];_Cost[1] = cost[1];
    if ( _Cost[0] == 0 && _Cost[1] == 0)
    {
        _CostStr.append("No");
    }else
    {
        if ( _Cost[0] != 0)
        {
            _CostStr.append(QString::number(_Cost[0]) + "Energy points  ");
        }
        if ( _Cost[1] != 0)
        {
            _CostStr.append(QString::number(_Cost[1]) + "Health points");
        }

    }

}

Skill *Skill::getBinded()
{
    return _Binded;
}
