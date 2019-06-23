#ifndef WEAPONHIT_H
#define WEAPONHIT_H

#include "skill.h"
#include "skill_types.h"
#include <QVector>

class SkillWeaponHit : public Skill
{
public:
    // init for simple or cleave attack
    SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost,
              QVector<Skill_WeaponHitTypes> skill_wht);

    // init for all types
    SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost,
              QVector<Skill_WeaponHitTypes> skill_wht,
              float scaling_procent, float charge_procent,int * scale_attributes,
              QString s_charge_cost, float s_charge_procent);

    // init for simple pr cleave with scale
    SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost,
              QVector<Skill_WeaponHitTypes> skill_wht,
              float scaling_procent, int * scale_attributes);

    // init for simple pr cleave with charged
    SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost,
              QVector<Skill_WeaponHitTypes> skill_wht,
              float charge_procent,
              QString s_charge_cost, float s_charge_procent);


protected:
    float _Scaling_procent;
    float _Charge_procent;
    // scale attributes, shows the id nubmers of main stats, on which damage depends
    int _Scale_attributes[2];
    // flags shows additional abilities of skill
    bool _Scaling; bool _Charged;
    bool _SuperCharged; bool _Cleave;
    bool _ScalingOr, _ScalingTwo;

    int _ChargeCost[4];
    int _SuperChargeCost[4];
    float _SuperCharge_procent;

private :
    void addDescriptionAboutScaling();
    void bindFromCharge();          //create new spell binded with main spell but without charge
    void bindFromSuperCharge();     //create new spell binded with main spell without supercharge


};

#endif // WEAPONHIT_H
