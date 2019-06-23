#ifndef WEAPONHIT_H
#define WEAPONHIT_H

#include "skill.h"
#include "skill_types.h"
#include <QVector>

class SkillWeaponHit : public Skill
{
public:
    // init for all types
    SkillWeaponHit(QString desc,  int id, QString cost,
              QVector<Skill_WeaponHitTypes> skill_wht,
              float scaling_procent, int * scale_attributes);
protected:
    float _Scaling_procent;
    // scale attributes, shows the id nubmers of main stats, on which damage depends
    int _Scale_attributes[2];
    // flags shows additional abilities of skill
    bool _Scaling , _Cleave;
    bool _ScalingOr, _ScalingTwo;

private :
    void addDescriptionAboutScaling();



};

#endif // WEAPONHIT_H
