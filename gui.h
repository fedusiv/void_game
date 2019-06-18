#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QTextBrowser>

#include "player/playerinventory.h"

class Gui : public QWidget
{
    Q_OBJECT
public:
    explicit Gui(QWidget *parent = nullptr);
    // update full player information
    void updateFullPlayerInfo(int ** stats, int level,  QString raceName, QString className, int step, int health);
    // update health
    void updateHealths(int health);
    //update inventory size status
    void updateInventorySizeStatus(inventoryStatus * status);
    // method to change gui to Game Gui
    void startGame();

signals:
    void startSignal();         // signal to start game


public slots:

private:
    void enterUiSetup(); // enter  Ui initilize
    void enterUiHide();  // hide enter ui
    void gameUiSetup();  // game Ui window initilize
    void gameUiSetup_if();  // for info labels game Ui window initilize
    void gameUiSetup_inv(); // for invenroty setup Ui window initilize
    void connectInit();    // all connects initilize


    // UI elements of enter window
    QPushButton * button_Start;
    QPushButton * button_Score;

    // UI elements of Game window
    // c label with constant information
    QLabel * label_level_c;
    QLabel * label_level;
    QLabel * label_strength_c;
    QLabel * label_strength;
    QLabel * label_agility_c;
    QLabel * label_agility;
    QLabel * label_energy_c;
    QLabel * label_energy;
    QLabel * label_vitality_c;
    QLabel * label_vitality;
    QLabel * label_step_c;
    QLabel * label_step;
    QLabel * label_race_c;
    QLabel * label_race;
    QLabel * label_class_c;
    QLabel * label_class;
    QProgressBar * healthBar;
    QTextBrowser * inventoryBrowser;
    QLabel * label_inventory_c;
    QLabel * label_inventory;





private slots:
    void button_StartClicked();
};

#endif // GUI_H
