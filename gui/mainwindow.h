#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTabWidget>

#include "playerstatswidget.h"
#include "playerinventorywidget.h"
#include "player/playerinventory.h"
#include "common_types.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
   explicit  MainWindow(QWidget * parent = nullptr);
    void startGame();   // do all stuff do be ready for game UI
    void updatePlayerInfo(MainPlayerStats *stats, int level,  QString raceName, int step, float health, float energy);
    void updateInventoryInfo(inventoryStatus * status);
    void updateInventoryElementInfo(QSharedPointer<EquipStatus> equip);
signals:
    void startButtonSignal();
    void inventoryElementSelected(int id);      // id of selected item
    void inventoreItemEquipTakeoff(int id);
    void inventoryItemRemove(int id);
private :
    void startUiSetup();    // init and run start Ui;
    void mainUiSetup();     // init and run main Ui



    // UI elements of Main Menu
    // UI elements of enter window
    QPushButton * button_Start;
    QPushButton * button_Score;
    QLabel * label_welcome;
    //UI elements in main window
    QTabWidget * tabWidget;     // tabWidget, which stores other widgets.
    PlayerStatsWidget *playerStatsWidget;   // widget of player stats
    PlayerInventoryWidget * playerInventoryWidget; // widget of all inventory stuff
private slots:
    void onButton_StartClicked();
    void onInventoryItemSelected(int id);
    void onInventoryItemEquipTakeoff(int id);
    void onInventoryItemRemove(int id);

};

#endif // MAINWINDOW_H
