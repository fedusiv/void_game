#ifndef EQUIP_H
#define EQUIP_H

#include <QString>
#include <QDebug>
#include "returncodes.h"
#include "skills/skill.h"

#define AMOUNT_OF_MAIN_STATS 3
/*
 * Types of all equipments
 */
enum class EquipType{
    Weapon,
    Components,
    Cloth,
    Usable
};

/*
 * Types of only cloth equipment
 */
enum  EquipClothType{
    Head,
    Body,
    Arms,
    Legs,
    Feet,
    Accessorize,
    NotCloth
};

class Equip
{
public:
    Equip(int level);
    Equip(QString name);
    Equip(QString name, QString desc, QString req,int level, EquipType type,  float size = 1 );
    Equip(QString name, QString desc, QString req,int level, EquipType type,  Skill * skill, float size = 1 );
    virtual ~Equip(){ qDebug() << "Equip deleted " + _Name; }

    int getLevel(); // returns equipment level
    float getSize();  // returns equipment size
    QString getName();// returns name of equipment
    void setName(QString name);
    QString getInfo();    // return string info about equip
    QString getDesc();    // return string about desc
    bool isEquipped();    // return flag of equipped status
    void setEquipped(bool status);  // set equipped or useless equip
    EquipType getEquipType();
    EquipReturnCode checkRequirments( int player_level, int ** type_points);  // return true if player can equip this element
    int * getRequirments();     // return pointer to array with requirments values for main stats
    Skill * getSkill();         // return pointer to skill of equip

    // virtual methods for children class
    virtual int getHands() { return 0;} // virtual method for weapon returns count of required hands
    virtual EquipClothType getClothType() { return EquipClothType::NotCloth;} // virtual method for get type of cloth equipment
    virtual QString getStringType() { return "Equip";}                          // virtual method for printing that is it equipment
    virtual float getDamage(){return 0.0;}                    // virtual method for weapon children, it return damage parametr
    virtual float getArmor(){return 0.0;}                    // virtual method for cloth children, returns armor of cloth
protected:
    int _Level;     // level of equipment
    QString _Name;  // name of equipment
    float _Size;      // size in inventory of current inventory
    QString _Desc;  // lore description of equip
    QString _Info;  // some information about equipment
    bool _Equipped;  // flag shows is equipment equipped
    int _RequiredPoints[3]; // array that represent requirmet points of 3 types ( str, agil, intelligence)

    EquipType  _Type;// type of equipment

    Skill * _Skill; // pointer to skill, that is in equipment

};


#endif // EQUIP_H
