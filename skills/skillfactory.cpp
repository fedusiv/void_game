#include "skillfactory.h"

SkillFactory * SkillFactory::instance = nullptr;

Skill *SkillFactory::createSkill(QJsonObject obj)
{
    // read st skill type and decide what skill will be created
    SkillTypes type = static_cast<SkillTypes>(obj["st"].toInt()) ;
    Skill * new_skill;
    switch ( type ) {
        case SkillTypes::WeaponHit :
            new_skill = createWeaponHit(obj);
            break;
    case SkillTypes::MagicBall :
        new_skill = createWeaponHit(obj);
        break;
    }

    return new_skill;
}

SkillFactory::SkillFactory() : _Id(0)
{

}

Skill * SkillFactory::createWeaponHit(QJsonObject obj)
{
    // parsing size of given weapon skill
    int var_size = obj["type"].toObject()["size"].toInt();
    // get random number for choose skill
    int type_num = ParamsCounting::randomSimpleCount(var_size);
    // read and parse string of weapon hit skill type
    QString type = obj["type"].toObject()["types"].toArray().at(type_num).toString();
    // QVector of all weapon hit abilities
    QVector<Skill_WeaponHitTypes>  swht;    // skill weapon hits types, vector stores data about that ability is on weapon skill
    QString name;       // name of new weapon hit skill
    QString desc;       // description of the skill
    QString super_charge_cost;
    float scaling_procent = 0;
    float charge_procent = 0;
    float super_charge_procent = 0;
    int stats_array[2]; // it is array for scaling ability in skill
    int id = _Id;

    for ( int i = 0; i < type.size(); i++)
    {
        Skill_WeaponHitTypes abil = static_cast<Skill_WeaponHitTypes>( type.at(i).unicode() - 0x30);
        swht.append(  abil );
        QStringList list = JsonReader::getInstance()->skillWeaponHitsDescRead(abil - 1);
        desc.append(list.at(0) + '\n');
        name.append(list.at(1) + " ");

        // if have scaling ability set parametrs of it
        if ( abil == Skill_WeaponHitTypes::Scaling ||  abil == Skill_WeaponHitTypes::ScalingOr || abil == Skill_WeaponHitTypes::ScalingTwo )
        {
            scaling_procent = ParamsCounting::skillWeaponCalculateScalingProcent(obj["scale_procent"].toArray()[0].toDouble(), obj["scale_procent"].toArray()[1].toDouble() );
            stats_array[0] = obj["scale_attribute"].toArray()[0].toInt();
            stats_array[1] = obj["scale_attribute"].toArray()[1].toInt();
        }
        // if have charge ability
        if ( abil == Skill_WeaponHitTypes::Charged )
        {
            charge_procent = static_cast<float>(obj["charge"].toDouble());
            _Id++;
        }
        // if have super charge ability
        if ( abil == Skill_WeaponHitTypes::SuperCharged )
        {
            super_charge_procent = static_cast<float>(obj["s_charge"].toObject()["charge"].toDouble());
            super_charge_cost = obj["s_charge"].toObject()["cost"].toString();
            _Id++;
        }
        // Why added _Id++? Cause charge and super charge it is additional skills, which binded with main,
        // but for realization it is different spells, cause player may choose which attack use
    }
    name.append("Hit");
    QString cost = obj["cost"].toString();

    if ( scaling_procent == 0  && charge_procent == 0)
    {
        return new SkillWeaponHit(name,desc,SkillTypes::WeaponHit,id,cost,swht);
    }

    if ( scaling_procent == 0)
    {
        return new SkillWeaponHit(name,desc,SkillTypes::WeaponHit,id,cost,swht,charge_procent,super_charge_cost,super_charge_procent);
    }

    if ( charge_procent == 0)
    {
        return new SkillWeaponHit(name,desc,SkillTypes::WeaponHit,id,cost,swht,scaling_procent,stats_array);
    }

    return new SkillWeaponHit(name,desc,SkillTypes::WeaponHit,id,cost,swht,scaling_procent,charge_procent,stats_array,super_charge_cost,super_charge_procent);



}
