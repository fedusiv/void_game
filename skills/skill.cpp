#include "skill.h"

/*
 * Creating new skill
 * cost goes as qstring cause it is converted from json, and in constructor it converts to array
 */
Skill::Skill(QString name, QString desc, SkillTypes type, int id, QString cost) :
    _Name(name), _Desc(desc), _Type(type), _Id(id), _Binded(nullptr)
{
    _CostStr.append("Cost: ");
    for ( int i = 0; i < 4; i++ )
    {
       _Cost[i] =  cost.at(i).unicode() - 0x30;
       if ( _Cost[i] > 0)
       {
        QString at;
        switch (i) {
        case 0 :
        at = "S";
        break;
        case 1 :
        at = "A";
        break;
        case 2 :
        at = "E";
        break;
        case 3 :
        at = "V";
        break;
        }
        _CostStr.append(at + ":" + QString::number(_Cost[i]) + " " );
       }
    }
}

Skill *Skill::getBinded()
{
    return _Binded;
}
