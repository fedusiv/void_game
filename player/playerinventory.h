#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

typedef struct inventoryStatus{
    int * max;
    int  * size;
}inventoryStatus;

class PlayerInventory
{
public:
    PlayerInventory();
    void recalculateInventorySize(int level);
    inventoryStatus * getInventoryStatus();

private:
   int _InventorySize_max;
   int _InventorySize;
   inventoryStatus _Inv_status;
};

#endif // PLAYERINVENTORY_H
