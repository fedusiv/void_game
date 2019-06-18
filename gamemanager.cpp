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
}

void GameManager::startGame()
{
    qDebug() << " starting Game ";
    // create Player
    player = new Player();
    // prepare gui for Game start
    gui->startGame();
    gui->updateFullPlayerInfo(player->getPlayerStats(), player->getPlayerLevel(),
                              player->getPlayerRaceName(), player->getPlayerClassName(),
                              player->getPlayerStep(), player->getPlayerCurrentHealth()) ;

    gui->updateInventorySizeStatus(player->getInventoryStatus());

}
