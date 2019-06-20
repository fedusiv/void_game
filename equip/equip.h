#ifndef EQUIP_H
#define EQUIP_H

#include <QString>
#include <QDebug>
#include "returncodes.h"

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
enum class EquipClothType{
    Head,
    Body,
    Arms,
    Legs,
    Feet,
    NotCloth
};

class Equip
{
public:
    Equip(int level);
    Equip(QString name);
    virtual ~Equip(){ qDebug() << "Equip deleted " + _Name; }

    int getLevel(); // returns equipment level
    int getSize();  // returns equipment size
    QString getName();// returns name of equipment
    void setName(QString name);
    QString getInfo();    // return string info about equip
    QString getDesc();    // return string about desc
    bool isEquipped();    // return flag of equipped status
    void setEquipped(bool status);  // set equipped or useless equip
    EquipType getEquipType();
    EquipReturnCode checkRequirments( int player_level, int ** type_points);  // return true if player can equip this element


    // virtual methods for children class
    virtual int getHands() { return 0;} // virtual method for weapon returns count of required hands
    virtual EquipClothType getClothType() { return EquipClothType::NotCloth;} // virtual method for get type of cloth equipment

protected:
    int _Level;     // level of equipment
    QString _Name;  // name of equipment
    int _Size;      // size in inventory of current inventory
    QString _Desc;  // lore description of equip
    QString _Info;  // some information about equipment
    bool _Equipped;  // flag shows is equipment equipped
    int _RequiredPoints[4]; // array that represent requirmet points of 4 types ( str, agil, energy, vital)

    EquipType  _Type;// type of equipment


};


#endif // EQUIP_H