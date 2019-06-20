#ifndef RETURNCODES_H
#define RETURNCODES_H

/*
 *  Header that holds enum or smth like with return code status
 */


// enum of return code, when received requst to equip equipment
enum class EquipReturnCode
{
    SUCCESS,        // success, equip or tke off equip
    LEVEL_ERROR,    // can not equip, level isnt enough
    POINTS_ERROR    // can not equip, points isnt enough
};


#endif // RETURNCODES_H
