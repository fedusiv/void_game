#include "skill_weaponhit.h"

// init for simple or cleave attack
SkillWeaponHit::SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost, QVector<Skill_WeaponHitTypes> skill_wht) :
    Skill (name, desc, type, id, cost),
    _Scaling_procent(0), _Charge_procent(0), _Scaling(false), _Charged(false) , _ScalingOr(false), _ScalingTwo(false)
{
    for ( auto t : skill_wht)
    {
        if ( t == Skill_WeaponHitTypes::Cleave) _Cleave = true;
    }
}


// init for all types
SkillWeaponHit::SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost,
                     QVector<Skill_WeaponHitTypes> skill_wht, float scaling_procent,
                     float charge_procent, int *scale_attributes, QString s_charge_cost, float s_charge_procent) :
    Skill (name, desc, type, id, cost),
    _Scaling_procent(scaling_procent), _Charge_procent(charge_procent), _SuperCharge_procent(s_charge_procent),
    _Scaling(false), _Charged(false),  _ScalingOr(false), _ScalingTwo(false)
{
    // write information about scaling attributes
    _Scale_attributes[0] = *scale_attributes++;
    _Scale_attributes[1] = *scale_attributes;

    // fill flags
    for ( auto t : skill_wht)
    {
        if ( t == Skill_WeaponHitTypes::Cleave) _Cleave = true;
        if ( t == Skill_WeaponHitTypes::Charged) _Charged = true;
        if ( t == Skill_WeaponHitTypes::SuperCharged) _SuperCharged = true;
        if ( t == Skill_WeaponHitTypes::Scaling) _Scaling = true;
        if ( t == Skill_WeaponHitTypes::ScalingOr) _ScalingOr = true;
        if ( t == Skill_WeaponHitTypes::ScalingTwo) _ScalingTwo = true;
    }

    addDescriptionAboutScaling();


}

// init for simple or cleave with scale
SkillWeaponHit::SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost,
                     QVector<Skill_WeaponHitTypes> skill_wht, float scaling_procent, int *scale_attributes) :
       Skill (name, desc, type, id, cost),
       _Scaling_procent(scaling_procent), _Charge_procent(0), _Scaling(false), _Charged(false),  _ScalingOr(false), _ScalingTwo(false)
{
    _Scale_attributes[0] = *scale_attributes++;
    _Scale_attributes[1] = *scale_attributes;
    for ( auto t : skill_wht)
    {
        if ( t == Skill_WeaponHitTypes::Cleave) _Cleave = true;
        if ( t == Skill_WeaponHitTypes::Scaling) _Scaling = true;
        if ( t == Skill_WeaponHitTypes::ScalingOr) _ScalingOr = true;
        if ( t == Skill_WeaponHitTypes::ScalingTwo) _ScalingTwo = true;
    }

    addDescriptionAboutScaling();

}
// init for simple pr cleave with charged
SkillWeaponHit::SkillWeaponHit(QString name, QString desc, SkillTypes type, int id, QString cost, QVector<Skill_WeaponHitTypes> skill_wht,
                     float charge_procent, QString s_charge_cost, float s_charge_procent):
    Skill (name, desc, type, id, cost),
    _Scaling_procent(0), _Charge_procent(charge_procent), _Scaling(false), _Charged(false),  _ScalingOr(false), _ScalingTwo(false), _SuperCharge_procent(s_charge_procent)
{
    for ( auto t : skill_wht)
    {
        if ( t == Skill_WeaponHitTypes::Cleave) _Cleave = true;
        if ( t == Skill_WeaponHitTypes::Charged) _Charged = true;
        if ( t == Skill_WeaponHitTypes::SuperCharged) _SuperCharged = true;
    }

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
        case 1 :void SkillWeaponHit::bindFromCharge()
            {

            }

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



