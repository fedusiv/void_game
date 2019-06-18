#include "playerinventory.h"
#include "player/paramscounting.h"

PlayerInventory::PlayerInventory() : _InventorySize_max(8), _InventorySize(0)
{
    _Inv_status.max = &_InventorySize_max;
    _Inv_status.size = &_InventorySize;
}

void PlayerInventory::recalculateInventorySize(int level)
{
    _InventorySize_max = ParamsCounting::inventorySizeCount(level);
}

inventoryStatus *  PlayerInventory::getInventoryStatus()
{
    return &_Inv_status;
}
