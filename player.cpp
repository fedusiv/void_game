#include "player.h"
#include "equip/equipfactory.h"

Player::Player() : _Step(0)
{
    Stats = new PlayerStats();
    Race = new PlayerRace();
    Class = new PlayerClass();
    Inventory = new PlayerInventory();

    // set inventory size
    Inventory->recalculateInventorySize(Stats->getLevel());
    // When created new player must be added simple weapon such as wooden stick
    EquipFactory * ef_instance =  EquipFactory::getInstance();
    Inventory->addToInventory(ef_instance->createEquip(EquipType::Weapon,0));
    Inventory->addToInventory(ef_instance->createClothEquip(EquipClothType::Body,0));

}

int ** Player::getPlayerStats()
{
    return Stats->getStats();
}

int Player::getPlayerLevel()
{
    return Stats->getLevel();
}

int Player::getPlayerCurrentHealth()
{
    return Stats->Health();
}

QString Player::getPlayerRaceName()
{
    return Race->getName();
}

QString Player::getPlayerClassName()
{
    return Class->getName();
}

int Player::getPlayerStep()
{
    return _Step;
}

inventoryStatus *Player::getInventory()
{
    return Inventory->getInventoryStatus();
}

/*
 * desc : return string information about equipment
 * info and desc devided by '@' symbol
 * @param : id order of equipment in gui implementation. It must be the same as in inventory
 * @return : QString with info and desc information.
 */
QSharedPointer<EquipStatus> Player::getGivenEquipInformation( int id )
{
    return Inventory->getEquipmentInfo( id );
}

/*
 * desc : equip choosen in gui inventory equipment element
 * @param : id in list of gui elemnts, it must be same as in inventory elemets list
 * @return : error status of operation
 */
EquipReturnCode Player::equipEquipmentElement(int id)
{
    return Inventory->equipEquipmentElement(Stats->getLevel(), Stats->getStats(), id);
}

void Player::inventoryRemoveEquip(int id)
{
    Inventory->removeFromInventory( id );
}
