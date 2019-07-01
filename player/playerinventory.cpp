#include "playerinventory.h"
#include "player/paramscounting.h"

PlayerInventory::PlayerInventory() : _InventorySize_max(8), _InventorySize(0), _InventoryCount(0)
{
    _Inv_status.max = &_InventorySize_max;
    _Inv_status.size = &_InventorySize;
    _Inv_status.list = &currentInventoryNameList;
    _Inv_status.count = &_InventoryCount;

    equipped = new Equipped();
}

/*
 * desc : recalculate and change Inventory Max Size
 * @param: level of player
 */
void PlayerInventory::recalculateInventorySize(int level)
{
    _InventorySize_max = ParamsCounting::inventorySizeCount(level);
}


/*
 * desc : return Inventory status struct
 * @return: pointer to inventoryStatus pointer
 */
inventoryStatus *  PlayerInventory::getInventoryStatus()
{
    return &_Inv_status;
}


/*
 * desc : add Equip to inventory list
 * @param: pointer to equipment that must be added to inventory
 */
void PlayerInventory::addToInventory(Equip *equip)
{
    if ( _InventorySize + equip->getSize() > _InventorySize_max)
    {
        // cannot add equipmnent to inventory
        return;
    }

    currentInventoryList.append(equip);
    currentInventoryNameList.append(equip->getName());
    _InventorySize+= equip->getSize();
    _InventoryCount++;
}

/*
 * desc : return string information about equipment
 * info and desc devided by '@' symbol
 * @param : id order of equipment in gui implementation. It must be the same as in inventory
 * @return : shared pointer of EquipStatus
 */
QSharedPointer<EquipStatus> PlayerInventory::getEquipmentInfo(int id)
{
    Equip * equip = currentInventoryList.at(id);
    QSharedPointer<EquipStatus> pnt = QSharedPointer<EquipStatus>(new EquipStatus(equip));

    return pnt;
}

/*
 * desc : remove equipment element from inventory
 * @param : id of equip, that must be removed
 */
void PlayerInventory::removeFromInventory(int id )
{
    Equip * equip = currentInventoryList.at(id);
    if ( equip->isEquipped() )
    {// disequip at first
        equipped->takeOffEquip( equip );
        equip->setEquipped(false);
    }
    _InventorySize-=equip->getSize();
    _InventoryCount--;
    currentInventoryList.removeAt(id);
    currentInventoryNameList.removeAt(id);
    delete equip;
}
/*
 * desc : trying to equip or disequip given element
 * @param: value of current player level
 * @param: array of types, to check if all requirments will be done
 * @return: code of method execution status
 */
EquipReturnCode PlayerInventory::equipEquipmentElement(int player_level, MainPlayerStats *type_array, int id)
{
    EquipReturnCode err = EquipReturnCode::SUCCESS;

    Equip * equip = currentInventoryList.at(id);

    if ( equip->isEquipped() )
    {
        // if equipped need to takeoff.
        if ( equipped->takeOffEquip(equip) )
        {   // it was found and deleted
            return err;
        }
    }else
    {
        // equip must be take on
        err = equip->checkRequirments(player_level, type_array);
        if( err != EquipReturnCode::SUCCESS)
            return err; // error, cant be equipped
        switch( equip->getEquipType() )
        {
            case EquipType::Weapon:
             equipWeapon(equip);
             break;
            case EquipType::Cloth:
             equipCloth(equip);
            break;
            case EquipType::Components:
            break;
            case EquipType::Usable:
            break;
        }
    }

    return err;
}

/*
 * desc : equip new weapon
 * it stores in equipped object, important! if it two handed, it stores as two equipped
 * @param: new weapon
 */
void PlayerInventory::equipWeapon(Equip *equip)
{
    // check size of current equipment weapon type
    if ( equipped->_weapon.size() == 0 )
    {
        // nothing equipped can take everything
        equipped->_weapon.append(equip);
    }else
    {
        // if something equipped
        if ( equip->getHands() == 1)
        {
            // if weapon is one handed
            if ( equipped->_weapon.size() == 1)
            {
                // only one equipped
                equipped->_weapon.append(equip);
            }else
            {
                // in both hands equipped
                if ( equipped->_weapon.at(0)->getHands() == 2 )
                {
                    // if it is double handed equipped
                    equipped->_weapon.at(0)->setEquipped(false);    // set false equipped for weapon
                    equipped->_weapon.replace(0,equip);             // replace 0 weapon with
                    equipped->_weapon.replace(1,equip);             // copy pointer cause need to hold as twp handed
                }else
                {
                    // if it is just two one handed equipped
                    // replace the last added
                    equipped->_weapon.at(0)->setEquipped(false);    // set false equipped for weapon
                    equipped->_weapon.replace(0,equip);             // replace 0 weapon with
                }
            }
        }
    }

    equip->setEquipped(true);                       // set equipped for new weapon
    // TODO : skills add

}

void PlayerInventory::equipCloth(Equip *cloth)
{
    EquipClothType type = cloth->getClothType();
    if ( type == EquipClothType::NotCloth ) return;

    switch (type)
    {
    case EquipClothType::Arms:
        break;

    case EquipClothType::Body:
        equipClothBody(cloth);
        break;

    }


}

void PlayerInventory::equipClothBody(Equip * cloth)
{
    if ( equipped->_body.size() == 0 )
    {
        equipped->_body.append(cloth);
    }else
    {
        equipped->_body.at(0)->setEquipped(false);
        equipped->_body.replace(0,cloth);
    }
    cloth->setEquipped(true);
}

/*
 * desc: method of Equipped class
 * it finds what is given equip and make it disequip, take off
 * @param: equip, that must be taken off
 * @return if it was found and took off
 */
bool Equipped::takeOffEquip(Equip * equip )
{
    if ( _weapon.indexOf(equip) != -1 )
    {
        int index = _weapon.indexOf(equip);
        _weapon.at(index)->setEquipped(false);
        if ( equip->getHands() == 1 )
        {   // if it is one handed
            _weapon.removeAt(index);
        }else
        {// if it is two handed
            _weapon.removeAll( equip );
        }
        return true;
    }
    if ( _head.indexOf(equip) != -1)
    {
        int index = _head.indexOf(equip);
        _head.at(index)->setEquipped(false);
        _head.removeAt(index);
        return true;
    }
    if ( _body.indexOf(equip) != -1 )
    {
        int index = _body.indexOf(equip);
        _body.at(index)->setEquipped(false);
        _body.removeAt(index);
        return true;
    }
    if ( _arms.indexOf(equip) != -1)
    {
        int index = _arms.indexOf(equip);
        _arms.at(index)->setEquipped(false);
        _arms.removeAt(index);
        return true;
    }

    if ( _legs.indexOf(equip) != -1 )
    {
        int index = _legs.indexOf(equip);
        _legs.at(index)->setEquipped(false);
        _legs.removeAt(index);
        return true;
    }
    if ( _feet.indexOf(equip) != -1)
    {
        int index = _feet.indexOf(equip);
        _feet.at(index)->setEquipped(false);
        _feet.removeAt(index);
        return true;
    }

    if ( _accesorize.indexOf(equip) != -1)
    {
        int index = _accesorize.indexOf(equip);
        _accesorize.at(index)->setEquipped(false);
        _accesorize.removeAt(index);
        return true;
    }

    return false;
}
