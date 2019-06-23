#ifndef SKILL_H
#define SKILL_H

#include <QString>
#include "skill_types.h"

class Skill
{
public:
    Skill(QString name, QString desc, SkillTypes type, int id, QString cost);
    Skill * getBinded();    // return skill, that binded with this skill
    QString getName(){return _Name;}
    QString getDesc(){return _Desc;}
    QString getCostStr(){return _CostStr;}
protected:
    QString _Name;      // name of skill
    QString _Desc;      // description of skill that it do
    QString _CostStr;   // Cost in string type for gui
    SkillTypes _Type;   // type of skill
    int _Id;            // id in game for skill, each skill has own id
    int _Cost[4];          // cost of spell, written like for parameters value's
    Skill * _Binded;     // pointer to binded skills
};

#endif // SKILL_H
