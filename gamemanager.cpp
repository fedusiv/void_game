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
}

void GameManager::startGame()
{
    qDebug() << " starting Game ";
    // create Player
    player = new Player();
    // prepare gui for Game start
    gui->startGame();
    // updating on gui player information
    gui->updateFullPlayerInfo(player->getPlayerStats(), player->getPlayerLevel(),
                              player->getPlayerRaceName(), player->getPlayerClassName(),
                              player->getPlayerStep(), player->getPlayerCurrentHealth()) ;
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
