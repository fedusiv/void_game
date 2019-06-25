#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QListWidget>
#include <QGroupBox>
#include <QFrame>
#include <QMessageBox>
#include <QTabWidget>

#include "gui/mainwindow.h"
#include "player/playerinventory.h"
#include "returncodes.h"


class SkillInfoWidget : public QWidget
{
      public:
      SkillInfoWidget(QWidget * parent,  QString desc) : QWidget(parent)
      {
           QLabel * d = new QLabel(this);
           d->setGeometry(0,0,140,210);
           d->setText(desc);
           d->setWordWrap(true);
           d->setAlignment( Qt::AlignLeft | Qt::AlignTop );
           d->setStyleSheet("font-size : 10pt");

      }
      ~SkillInfoWidget(){}
};

class Gui : public QWidget
{
    Q_OBJECT
public:
    explicit Gui(QWidget *parent = nullptr);
    // update full player information
    void updatePlayerInfo(int ** stats, int level,  QString raceName, QString className, int step, float health);
    // update health
    void updateHealths(int health);
    //update inventory size status
    void updateInventory(inventoryStatus * status);
    //update information about selected equip
    void updateInfoElement(QSharedPointer<EquipStatus> equip);
    // method to change gui to Game Gui
    void startGame();

    // shows messages if some problems appears with equipment proccess
    void showWarningMessage( EquipReturnCode err);

signals:
    void startSignal();         // signal to start game
    void inventoryElementSelected(int order_id);    // signal said, that equipment was selected in inventory browser
    void inventoryEquipElement( int order_id);      // signal, that need to equip or take off element from inventory
    void inventoryRemoveElement( int orded_id );    // signal, that said to remove from inventory choosen element


public slots:

private:
    void gameUiSetup();  // game Ui window initilize
    void gameUiSetup_info();// for information box Ui window initilize
    void gameUiSetup_skills();// for skills inforamtion box initilize
    void connectInit();    // if need initilize connections except gui connections,
                           // cause not all gui elements created at start


    MainWindow * mainWindow;


private slots:
    // reacting when start button clicked
    void button_StartClicked();

    // reacting when was clicked on inventory equip name
    void onInventoryItemSelected(int id);
    // reacting when was clicked on equip or take off button in inventory
    void onInventoryEquipButton(int id);
    // reacting when was clicked to remove equip from inventory
    void onInventoryRemoveEquipButton(int id);
};

#endif // GUI_H
