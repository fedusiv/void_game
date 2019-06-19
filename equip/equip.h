#ifndef EQUIP_H
#define EQUIP_H

#include <QString>

enum class EquipType{
    Weapon,
    Components,
    Cloth,
    Usable
};


class Equip
{
public:
    Equip(int level);
    Equip(QString name);

    int getLevel(); // returns equipment level
    int getSize();  // returns equipment size
    QString getName();// returns name of equipment
    void setName(QString name);
    QString getInfo();    // return string info about equip
    QString getDesc();    // return string about desc
    bool isEquipped();    // return flag of equipped status

protected:
    int _Level;     // level of equipment
    QString _Name;  // name of equipment
    int _Size;      // size in inventory of current inventory
    QString _Desc;  // lore description of equip
    QString _Info;  // some information about equipment
    bool _Equipped;  // flag shows is equipment equipped


};


#endif // EQUIP_H
