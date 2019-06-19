#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>

#include "gui.h"
#include "player.h"


class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager(QObject *parent = nullptr);
    ~GameManager();

private:
   Gui * gui;   // gui class
   Player * player; // player class responsible for all operations with player
   void connectInit();


private slots:
   void startGame();    // main method to start game, make all inits
   void onGuiInventoryEquipSelected( int order_id); // reacting on gui signal when equip in inventory selected
};

#endif // GAMEMANAGER_H
