#ifndef PLAYERINVENTORYWIDGET_H
#define PLAYERINVENTORYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QGroupBox>
#include <QListWidget>

#include "player/playerinventory.h"

class PlayerInventoryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerInventoryWidget(QWidget *parent = nullptr);

    void updateInventory(inventoryStatus * status);
    void updateInfoElement(QSharedPointer<EquipStatus> equip);

signals:
    void inventoryElementSelected(int id);      // id of selected item
    void inventoryEquipElement(int id);         // equip of take off element
    void inventoryRemoveElement(int id);        //remove from inventory element

public slots:


private:
    void initUI();
    void inventoryElementInitUI();

    // inventory gui elements
    QListWidget* inventoryBrowser;
    QLabel * label_inventory_c;
    QLabel * label_inventory;
    QFrame * inventoryManagment_Frame;      // frame that holds button to managment inventory
    QPushButton * inventoryRemoveButton;    // button removes equipment from inventory
    QPushButton * inventoryEquipButton;     // button equip or disequip equipment
    //information element box
    QGroupBox * infoGroupBox;
    QLabel * label_elementType;
    QLabel * label_elementWeight;
    QLabel * label_elementSpec;                // shows armor or damage
    QLabel * label_elementLevel;
    QLabel * label_elementEquipped;
    QLabel * label_elementDesc;
    QLabel * label_elementAbilityName;
    QLabel * label_elementAbilityDesc;


private slots:
    void onInventoryItemSelected(QListWidgetItem *item);    // reacts when item was selected
    void onInvenrotyEquipButtonPressed();                   // reacts when pressing buttom to equip/takeoff weapon
    void onInventoryRemoveItemButtonPressed();              // reacts when push button for remove item
};

#endif // PLAYERINVENTORYWIDGET_H
