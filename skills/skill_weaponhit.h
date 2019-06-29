#ifndef WEAPONHIT_H
#define WEAPONHIT_H

#include "skill.h"
#include "skill_types.h"
#include <QVector>

class SkillWeaponHit : public Skill
{
public:
    // init for all types
    SkillWeaponHit(QString desc,  int id, int * cost,
              bool *  skill_wht,
              float scaling_procent, int * scale_attributes);
protected:
    float _Scaling_procent;
    // scale attributes, shows the id nubmers of main stats, on which damage depends
    int _Scale_attributes[2];
    bool _Skill_Types[Skill_WeaponHitTypes::Count];  // array of bools, that stores data about weapon skill types

private :
    void addDescriptionAboutScaling();



};

#endif // WEAPONHIT_H
