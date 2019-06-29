#include "gamemanager.h"
#include <QDebug>

GameManager::GameManager(QObject * parent) : QObject(parent)
{
    gui = new Gui();
    connectInit();
}

GameManager::~GameManager()
{
    qDebug() << " Game Manager deleted";
}

void GameManager::connectInit()
{
    connect(gui, SIGNAL(startSignal()), this, SLOT(startGame()));
    connect(gui, &Gui::inventoryElementSelected,this, &GameManager::onGuiInventoryEquipSelected);
    connect(gui, &Gui::inventoryEquipElement, this, &GameManager::onGuiInventoryEquipElement);
    connect(gui, &Gui::inventoryRemoveElement, this, &GameManager::onGuiInventoryRemoveEquip);
}

void GameManager::startGame()
{
    // create Player
    player = new Player();
    // prepare gui for Game start
    gui->startGame();
    // updating on gui player information
    gui->updatePlayerInfo(player->getPlayerStats(), player->getPlayerLevel(),
                              player->getPlayerRaceName(),
                              player->getPlayerStep(), player->getPlayerCurrentHealth(),
                          player->getPlayerCurrentEnergy()) ;
    // updating on gui player inventory information;
    gui->updateInventory(player->getInventory());

}

/*
 * desc: called when gui emit signal of inventory selected item
 *       and shows info on info box
 *
 */
void GameManager::onGuiInventoryEquipSelected(int order_id)
{
    QSharedPointer<EquipStatus> pnt = player->getGivenEquipInformation( order_id );
    gui->updateInfoElement(pnt);
}

/*
 * desc: slots react on gui signal to equip or disequip(take off) equipment form inventory
 *  gamemanager send request to player object to procced this and return to gui updated info about element
 * @param : id in order of element in inventory list
 */
void GameManager::onGuiInventoryEquipElement(int order_id)
{
    EquipReturnCode err =  player->equipEquipmentElement( order_id );
    if ( err == EquipReturnCode::SUCCESS)
    {
        QSharedPointer<EquipStatus> pnt = player->getGivenEquipInformation( order_id );
        gui->updateInfoElement(pnt);
    }
    else
    {
        gui->showWarningMessage(err);
    }
}

void GameManager::onGuiInventoryRemoveEquip(int order_id)
{
    player->inventoryRemoveEquip( order_id );
    gui->updateInventory(player->getInventory());
}
