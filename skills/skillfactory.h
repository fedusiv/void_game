#ifndef SKILLFACTORY_H
#define SKILLFACTORY_H

#include "skill.h"
#include "skill_types.h"
#include "skill_weaponhit.h"
#include <QJsonObject>
#include <QJsonArray>
#include "player/paramscounting.h"
#include "json_reader.h"
/*
 * Signleton, that create skill objects
 */
class SkillFactory
{
public:

    static SkillFactory * getInstance()
    {
        if( instance == nullptr )
        {
            instance = new SkillFactory();
        }
        return instance;
    }

    Skill * createSkill(QJsonObject obj);
    Skill * createWeaponHit(QJsonObject obj);

private:
    SkillFactory();


    static SkillFactory * instance;
    int _Id;     // id for skills.

};

#endif // SKILLFACTORY_H
