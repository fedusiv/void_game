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

#include "player/playerinventory.h"
#include "returncodes.h"


class SkillInfoWidget : public QWidget
{
      public:
      SkillInfoWidget(QWidget * parent, QString name, QString desc) : QWidget(parent)
      {
           QLabel * n = new QLabel(this);
           n->setGeometry(0,0,140,20);
           n->setText(name);
           n->setWordWrap(true);

           QLabel * d = new QLabel(this);
           d->setGeometry(0,20,140,190);
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
    void updateFullPlayerInfo(int ** stats, int level,  QString raceName, QString className, int step, int health);
    // update health
    void updateHealths(int health);
    //update inventory size status
    void updateInventory(inventoryStatus * status);
    //update information about selected equip
    void updateInfoElement(QSharedPointer<EquipStatus> equip);
    //update skills inofrmation in skills tabwidget
    void updateSkillInfo(Skill * skill);
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
    void enterUiSetup(); // enter  Ui initilize
    void enterUiHide();  // hide enter ui
    void gameUiSetup();  // game Ui window initilize
    void gameUiSetup_playerInfo();  // for info labels game Ui window initilize
    void gameUiSetup_inv(); // for invenroty setup Ui window initilize
    void gameUiSetup_info();// for information box Ui window initilize
    void gameUiSetup_skills();// for skills inforamtion box initilize
    void connectInit();    // if need initilize connections except gui connections,
                           // cause not all gui elements created at start


    // UI elements of enter window
    QPushButton * button_Start;
    QPushButton * button_Score;

    // UI elements of Game window
    // c label with constant information
    // info gui elements
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
    // inventory gui elements
    QListWidget* inventoryBrowser;
    QLabel * label_inventory_c;
    QLabel * label_inventory;
    QFrame * inventoryManagment_Frame;      // frame that holds button to managment inventory
    QPushButton * inventoryRemoveButton;    // button removes equipment from inventory
    QPushButton * inventoryEquipButton;     // button equip or disequip equipment
    //information box
    QGroupBox * infoGroupBox;
    QLabel * label_infoInfo;  // shows information
    QLabel * label_infoDesc;  // shows description
    // skills information box
    QTabWidget * skillTabWidget;


private slots:
    // reacting when start button clicked
    void button_StartClicked();

    // reacting when was clicked on inventory equip name
    void onInventoryItemSelected(QListWidgetItem *item);
    // reacting when was clicked on equip or take off button in inventory
    void onInventoryEquipButton();
    // reacting when was clicked to remove equip from inventory
    void onInventoryRemoveEquipButton();
};

#endif // GUI_H
