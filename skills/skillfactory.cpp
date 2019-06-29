#include "skillfactory.h"

SkillFactory * SkillFactory::instance = nullptr;

Skill *SkillFactory::createSkill(QJsonObject obj)
{
    // read st skill type and decide what skill will be created
    SkillTypes type = static_cast<SkillTypes>(obj["type"].toInt()) ;
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

    // get amount of all ability variations of this weapon
    int abil_amount = obj["abil"].toObject()["size"].toInt();
    // get random number for choose skill
    int abil_num = ParamsCounting::randomSimpleCount(abil_amount);

    // read and parse string of weapon hit skill type
    QString type = obj["abil"].toObject()["types"].toArray().at(abil_num).toString();
    // QVector of all weapon hit abilities
    bool swht[Skill_WeaponHitTypes::Count];    // skill weapon hits types, array stores data about that ability is on weapon skill
    memset(swht, false, Skill_WeaponHitTypes::Count);
    QString desc;       // description of the skill
    float scaling_procent = 0;
    int scaling_array[2]; // it is array for scaling ability in skill
    int id = _Id++;         // set id of spell and also increase the main id counter for all spells 
    for ( int i = 0; i < type.size(); i++)
    {
        Skill_WeaponHitTypes abil_num = static_cast<Skill_WeaponHitTypes>( type.at(i).unicode() - 0x30);
        swht[abil_num] = true;
        QStringList list = JsonReader::getInstance()->skillWeaponHitsDescRead(abil_num);
        desc.append(list.at(0) + '\n');


        scaling_procent = ParamsCounting::skillWeaponCalculateScalingProcent(obj["scale_procent"].toArray()[0].toDouble(), obj["scale_procent"].toArray()[1].toDouble() );
        scaling_array[0] = obj["scale_attribute"].toArray()[0].toInt();
        scaling_array[1] = obj["scale_attribute"].toArray()[1].toInt();

    }
    int cost_array[2];
    cost_array[0] = obj["cost"].toArray().at(0).toInt();
    cost_array[1] = obj["cost"].toArray().at(1).toInt();


    return new SkillWeaponHit(desc,id,cost_array,swht,scaling_procent,scaling_array);
}
