#include "skill_weaponhit.h"
// init for all types
SkillWeaponHit::SkillWeaponHit(QString desc, int id, QString cost,
                     QVector<Skill_WeaponHitTypes> skill_wht, float scaling_procent, int *scale_attributes) :
    Skill ("Hit", desc, SkillTypes::WeaponHit, id, cost),
    _Scaling_procent(scaling_procent),
    _Scaling(false), _ScalingOr(false), _ScalingTwo(false)
{
    // write information about scaling attributes
    _Scale_attributes[0] = *scale_attributes++;
    _Scale_attributes[1] = *scale_attributes;

    // fill flags
    for ( auto t : skill_wht)
    {
        if ( t == Skill_WeaponHitTypes::Cleave) _Cleave = true;
        if ( t == Skill_WeaponHitTypes::Scaling) _Scaling = true;
        if ( t == Skill_WeaponHitTypes::ScalingOr) _ScalingOr = true;
        if ( t == Skill_WeaponHitTypes::ScalingTwo) _ScalingTwo = true;
    }

    addDescriptionAboutScaling();


}

/*
 * add description about scaling hit in weapon
 */
void SkillWeaponHit::addDescriptionAboutScaling()
{
    if (_Scaling)
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
        _Desc.append( "\nDmg + " + QString::number(static_cast<double>(_Scaling_procent)) + " * " + at);
    }

    if (_ScalingOr || _ScalingTwo)
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
        if( _ScalingOr)
        _Desc.append( "\nDmg + " + QString::number(static_cast<double>(_Scaling_procent)) + " * " + at +
                      " / " +  QString::number(static_cast<double>(_Scaling_procent)) + " * " + at1);
        if( _ScalingTwo)
        _Desc.append( "\nDmg + " + QString::number(static_cast<double>(_Scaling_procent)) + " * " + at +
                      " + " +  QString::number(static_cast<double>(_Scaling_procent)) + " * " + at1);
    }
}



