#include "skill_weaponhit.h"
// init for all types
SkillWeaponHit::SkillWeaponHit(QString desc, int id, int *cost,
                     bool *skill_wht, float scaling_procent, int *scale_attributes) :
    Skill ("Hit", desc, SkillTypes::WeaponHit, id, cost),
    _Scaling_procent(scaling_procent)
{
    // write information about scaling attributes
    _Scale_attributes[0] = *scale_attributes++;
    _Scale_attributes[1] = *scale_attributes;
    // copy data to array, now in array we now that types are inside
    memcpy(_Skill_Types, skill_wht, Skill_WeaponHitTypes::Count);

    addDescriptionAboutScaling();
    _Desc.append("\nCost : " + _CostStr);

}

/*
 * add description about scaling hit in weapon
 */
void SkillWeaponHit::addDescriptionAboutScaling()
{
    if ( _Skill_Types[Skill_WeaponHitTypes::Scaling] )
    {
        QString at;
        switch (_Scale_attributes[0] ) {
        case 0 :
        at = "Str";
        break;
        case 1 :
        at = "Agil";
        break;
        case 2 :
        at = "Enrg";
        break;
        case 3 :
        at = "Vital";
        break;
        }
        _Desc.append( "Dmg + " + QString::number(static_cast<double>(_Scaling_procent)) + " * " + at);
    }

    if (_Skill_Types[Skill_WeaponHitTypes::ScalingTwo] || _Skill_Types[Skill_WeaponHitTypes::ScalingOr])
    {
        QString at;
        QString at1;
        switch (_Scale_attributes[0] ) {
        case 0 :
        at = "Str";
        break;
        case 1 :
        at = "Agil";
        break;
        case 2 :
        at = "Enrg";
        break;
        case 3 :
        at = "Vital";
        break;
        }
        switch (_Scale_attributes[1] ) {
        case 0 :
        at1 = "Str";
        break;
        case 1 :
        at1 = "Agil";
        break;
        case 2 :
        at1 = "Enrg";
        break;
        case 3 :
        at1 = "Vital";
        break;
        }
        if( _Skill_Types[Skill_WeaponHitTypes::ScalingOr])
        _Desc.append( "Dmg + " + QString::number(static_cast<double>(_Scaling_procent)) + " * " + at +
                      " / " +  QString::number(static_cast<double>(_Scaling_procent)) + " * " + at1);
        if( _Skill_Types[Skill_WeaponHitTypes::ScalingTwo])
        _Desc.append( "Dmg + " + QString::number(static_cast<double>(_Scaling_procent)) + " * " + at +
                      " + " +  QString::number(static_cast<double>(_Scaling_procent)) + " * " + at1);
    }
}



