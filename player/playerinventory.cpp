#include "playerinventory.h"
#include "player/paramscounting.h"

PlayerInventory::PlayerInventory() : _InventorySize_max(8), _InventorySize(0)
{
    _Inv_status.max = &_InventorySize_max;
    _Inv_status.size = &_InventorySize;
    _Inv_status.list = &currentInventoryNameList;
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
