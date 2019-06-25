#include "playerinventorywidget.h"

PlayerInventoryWidget::PlayerInventoryWidget(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void PlayerInventoryWidget::updateInventory(inventoryStatus *status)
{
    inventoryBrowser->clear();
    label_inventory->setText( QString::number( static_cast<double>(*(status->size)) ) + " / " + QString::number( static_cast<double>(*(status->max) )));
    for( int i = 0; i < *(status->count); i++)
        inventoryBrowser->addItem(status->list->at(i));
}

void PlayerInventoryWidget::onInventoryItemSelected(QListWidgetItem *item)
{
    Q_UNUSED(item);
    emit inventoryElementSelected(inventoryBrowser->currentRow());
}

void PlayerInventoryWidget::onInvenrotyEquipButtonPressed()
{
    emit inventoryEquipElement(inventoryBrowser->currentRow());
}

void PlayerInventoryWidget::onInventoryRemoveItemButtonPressed()
{
    emit inventoryRemoveElement(inventoryBrowser->currentRow());
}
/*
 * desc : show information about selected element in inventory
 */
void PlayerInventoryWidget::updateInfoElement(QSharedPointer<EquipStatus> equip)
{
    infoGroupBox->setTitle(equip->name);
    label_elementType->setText(equip->type);
    label_elementWeight->setText("Weight : " + QString::number(static_cast<double>(equip->size)));
    if ( equip->damage > 0)
    {
        label_elementSpec->setText("Damage : " + QString::number(static_cast<double>(equip->damage)));
    }else
    {
        label_elementSpec->setText("Armor : " + QString::number(static_cast<double>(equip->armor)));
    }
    label_elementLevel->setText("Equip level : " + QString::number(equip->level));
    if( equip->equiped )
    {
        label_elementEquipped->setText("Equipped : True");
        inventoryEquipButton->setText("Take off");
    }else
    {
        label_elementEquipped->setText("Equipped : No");
        inventoryEquipButton->setText("Equip");
    }

    label_elementDesc->setText(equip->desc);

    if( equip->skill != nullptr)
    {
        label_elementAbilityName->setText(equip->skill->getName());
        label_elementAbilityDesc->setText(equip->skill->getDesc());
    }else
    {
         label_elementAbilityName->setText("");
         label_elementAbilityDesc->setText("");
    }

    infoGroupBox->show();
    inventoryManagment_Frame->show();
}


void PlayerInventoryWidget::initUI()
{
    int start_x_point = 20;
    int start_y_point = 30;
    int inventory_browser_w = 150;
    int inventory_browser_h = 250;
    int distance_between_elements = 5;
    int inventory_managment_frame_h = 30;

    inventoryBrowser = new QListWidget(this);
    inventoryBrowser->setGeometry(start_x_point,start_y_point,inventory_browser_w,inventory_browser_h);

    label_inventory = new QLabel(this);
    label_inventory->setGeometry(start_x_point+45,start_y_point-20,65,20);

    label_inventory_c = new QLabel("Size", this);
    label_inventory_c->setGeometry(start_x_point,start_y_point-20,35,20);

    inventoryManagment_Frame = new QFrame(this);
    inventoryManagment_Frame->setGeometry(
                start_x_point,
                start_y_point + inventory_browser_h + distance_between_elements,
                inventory_browser_w,
                inventory_managment_frame_h);

    inventoryEquipButton = new QPushButton(inventoryManagment_Frame);
    inventoryEquipButton->setGeometry(0,0, inventory_browser_w/2 - 2,20);
    inventoryEquipButton->setStyleSheet("font-size : 9pt");

    inventoryRemoveButton = new QPushButton(inventoryManagment_Frame);
    inventoryRemoveButton->setText("Remove");
    inventoryRemoveButton->setStyleSheet("font-size : 9pt");
    inventoryRemoveButton->setGeometry(inventory_browser_w/2,0,inventory_browser_w/2 - 2,20);

    inventoryManagment_Frame->hide();   // shows inventory managment frame only when item selected.

    inventoryElementInitUI();

    connect(inventoryBrowser,&QListWidget::itemClicked,this,&PlayerInventoryWidget::onInventoryItemSelected);
    connect(inventoryEquipButton,&QPushButton::clicked,this,&PlayerInventoryWidget::onInvenrotyEquipButtonPressed);
    connect(inventoryRemoveButton,&QPushButton::clicked,this,&PlayerInventoryWidget::onInventoryRemoveItemButtonPressed);
}

void PlayerInventoryWidget::inventoryElementInitUI()
{
    // look at initUI local variables param and pos everything relatively on it
    int start_x_point = 200;
    int start_y_point = 10;
    int group_w = 320;
    int group_h = 300;

    infoGroupBox = new QGroupBox(this);
    infoGroupBox->setGeometry(start_x_point,start_y_point,group_w,group_h);
    infoGroupBox->hide();

    label_elementType = new QLabel(infoGroupBox);
    label_elementType->setGeometry(5,25,300,20);

    label_elementWeight = new QLabel(infoGroupBox);
    label_elementWeight->setGeometry(5,45,300,20);

    label_elementSpec = new QLabel(infoGroupBox);
    label_elementSpec->setGeometry(5,65,300,20);

    label_elementLevel = new QLabel(infoGroupBox);
    label_elementLevel->setGeometry(5,85,300,20);

    label_elementEquipped = new QLabel(infoGroupBox);
    label_elementEquipped->setGeometry(5,105,300,20);

    label_elementDesc = new QLabel(infoGroupBox);
    label_elementDesc->setGeometry(5,145,300,40);
    label_elementDesc->setWordWrap(true);
    label_elementDesc->setStyleSheet("font-style : italic");

    label_elementAbilityName = new QLabel(infoGroupBox);
    label_elementAbilityName->setGeometry(5,200,300,20);

    label_elementAbilityDesc = new QLabel(infoGroupBox);
    label_elementAbilityDesc->setGeometry(5,220,300,80);
    label_elementAbilityDesc->setWordWrap(true);

}
