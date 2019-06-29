#include "gui.h"
#include <QDebug>

Gui::Gui(QWidget *parent) : QWidget(parent)
{
    mainWindow = new MainWindow();
    connectInit();
}

void Gui::updatePlayerInfo(int **stats, int level, QString raceName, int step, float health, float energy)
{
    mainWindow->updatePlayerInfo(stats,level,raceName,step,health,energy);
}

void Gui::updateInventory(inventoryStatus * status)
{
    mainWindow->updateInventoryInfo(status);
}

void Gui::updateInfoElement(QSharedPointer<EquipStatus> equip)
{
    mainWindow->updateInventoryElementInfo(equip);
}

void Gui::startGame()
{
    mainWindow->startGame();
}

void Gui::showWarningMessage(EquipReturnCode err)
{
    QString msg;
    switch ( err )
    {
        case EquipReturnCode::LEVEL_ERROR:
        msg = "Not enough level for this";
        break;
        case EquipReturnCode::POINTS_ERROR:
        msg = "Not enough  points for this";
        break;
        case EquipReturnCode::SUCCESS:
        break;
    }
    QMessageBox::warning(this, "Cannot!",msg);
}

void Gui::connectInit()
{
    connect(mainWindow, &MainWindow::startButtonSignal, this, &Gui::button_StartClicked);
    connect(mainWindow, &MainWindow::inventoryElementSelected,this, &Gui::onInventoryItemSelected);
    connect(mainWindow, &MainWindow::inventoreItemEquipTakeoff,this,&Gui::onInventoryEquipButton);
    connect(mainWindow, &MainWindow::inventoryItemRemove,this,&Gui::onInventoryRemoveEquipButton);
}

void Gui::button_StartClicked()
{
    emit startSignal();
}


/*
 * desc : slots reacting when clicked on inventory equipment name
 *
 */
void Gui::onInventoryItemSelected(int id)
{
    emit inventoryElementSelected(id);
}

/*
 * desc : slots reacting when clicked on inventory equip button
 * to equip or take off equipment. It just send to player inventory equipment id, and
 * inventory desides inside that need to do with equipment. take off or equip
 */
void Gui::onInventoryEquipButton(int id)
{
    emit inventoryEquipElement(id);
}

void Gui::onInventoryRemoveEquipButton(int id)
{

    emit inventoryRemoveElement(id);
}


