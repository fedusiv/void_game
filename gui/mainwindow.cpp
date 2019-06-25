#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget (parent)
{
    startUiSetup();
    this->show();
}

void MainWindow::startGame()
{
    button_Score->hide();
    button_Start->hide();
    label_welcome->hide();
    this->setFixedSize(900,600);

    mainUiSetup();
    this->show();


}

void MainWindow::updatePlayerInfo(int **stats, int level, QString raceName, QString className, int step, float health)
{
    playerStatsWidget->updatePlayerInfo(stats,level,raceName,className,step,health);
}

void MainWindow::updateInventoryInfo(inventoryStatus *status)
{
    playerInventoryWidget->updateInventory(status);
}

void MainWindow::updateInventoryElementInfo(QSharedPointer<EquipStatus> equip)
{
    playerInventoryWidget->updateInfoElement(equip);
}

void MainWindow::startUiSetup()
{
    this->setFixedSize(300,300);

    button_Start = new QPushButton("Start", this);
    button_Start->setGeometry(QRect(QPoint(110, 90),
                                    QSize(80, 40)));

    button_Score = new QPushButton("Scores", this);
    button_Score->setGeometry(QRect(QPoint(110, 150),
                                    QSize(80, 40)));


    label_welcome = new QLabel(this);
    label_welcome->setGeometry(110,20, 90, 40);
    label_welcome->setStyleSheet("font-style: italic ; \
                                   font-size : 12pt");
    label_welcome->setText("Welcome to Void Game!");
    label_welcome->setWordWrap(true);

    connect(button_Start, SIGNAL(clicked()) , this, SLOT(onButton_StartClicked()));
}

void MainWindow::mainUiSetup()
{
    tabWidget = new QTabWidget(this);
    tabWidget->setGeometry(10,10, 550, 580);

    playerStatsWidget = new PlayerStatsWidget(tabWidget);
    tabWidget->addTab(playerStatsWidget,"Player");

    playerInventoryWidget = new PlayerInventoryWidget(tabWidget);
    tabWidget->addTab(playerInventoryWidget,"Inventory");

    tabWidget->show();


    connect(playerInventoryWidget,&PlayerInventoryWidget::inventoryElementSelected, this, &MainWindow::onInventoryItemSelected);
    connect(playerInventoryWidget,&PlayerInventoryWidget::inventoryEquipElement,this, &MainWindow::onInventoryItemEquipTakeoff);
    connect(playerInventoryWidget,&PlayerInventoryWidget::inventoryRemoveElement,this,&MainWindow::onInventoryItemRemove);
}

void MainWindow::onButton_StartClicked()
{
    emit startButtonSignal();
}

void MainWindow::onInventoryItemSelected(int id)
{
    emit inventoryElementSelected(id);
}

void MainWindow::onInventoryItemEquipTakeoff(int id)
{
    emit inventoreItemEquipTakeoff(id);
}

void MainWindow::onInventoryItemRemove(int id)
{
    emit inventoryItemRemove(id);
}
