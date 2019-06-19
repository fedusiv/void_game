#include "gui.h"
#include <QDebug>

Gui::Gui(QWidget *parent) : QWidget(parent)
{
    enterUiSetup();
    this->show();
    connectInit();

}

void Gui::updateFullPlayerInfo(int **stats, int level, QString raceName, QString className, int step, int health)
{
    label_strength->setText(QString::number(*(stats[0])));
    label_agility->setText(QString::number(*(stats[1])));
    label_energy->setText(QString::number(*(stats[2])));
    label_vitality->setText(QString::number(*(stats[3])));

    label_level->setText(QString::number(level));
    label_step->setText(QString::number(step));

    label_race->setText(raceName);
    label_class->setText(className);

    healthBar->setMaximum(health);
    healthBar->setValue(health);
}

void Gui::updateInventory(inventoryStatus * status)
{
    label_inventory->setText( QString::number( *(status->size) ) + " / " + QString::number( *(status->max) ));
    for( int i = 0; i < *(status->size); i++)
        inventoryBrowser->addItem(status->list->at(i));
}
/*
 * desc : show information about selected element in inventory
 */
void Gui::updateInfoElement(QSharedPointer<EquipStatus> equip)
{
    infoGroupBox->setTitle(equip->name);
    QString full = QString(
                equip->info + '\n' + (equip->equiped ? "Equipped" : "Useless") +
                '\n' + "Size : " + QString::number(equip->size));
    label_infoInfo->setText(full);
    label_infoDesc->setText(equip->desc);
    infoGroupBox->show();
}

void Gui::startGame()
{
    enterUiHide();
    gameUiSetup();
}

void Gui::enterUiSetup()
{
    this->setFixedSize(400,300);

    button_Start = new QPushButton("Start", this);
    button_Start->setGeometry(QRect(QPoint(150, 90),
                                    QSize(80, 40)));

    button_Score = new QPushButton("Scores", this);
    button_Score->setGeometry(QRect(QPoint(150, 150),
                                    QSize(80, 40)));

    // connect part of GUI
    connect(button_Start, SIGNAL(clicked()) , this, SLOT(button_StartClicked()));

}

void Gui::enterUiHide()
{
    // disconnect part
    disconnect(button_Start, SIGNAL(clicked()) , this, SLOT(button_StartClicked()));

    button_Start->hide();
    button_Score->hide();
    this->hide();
}

void Gui::gameUiSetup()
{
    this->setFixedSize(800,500);

    gameUiSetup_playerInfo();   // setup player information
    gameUiSetup_inv();  // setup inventory
    gameUiSetup_info(); // setup informationbox

    this->show();
}


void Gui::connectInit()
{
    //connect(inventoryBrowser, SIGNAL(itemClicked()), this, SLOT(onInventoryItemSelected()));
}

void Gui::button_StartClicked()
{
    emit startSignal();
}


/*
 * desc : slots reacting when clicked on inventory equipment name
 *
 */
void Gui::onInventoryItemSelected(QListWidgetItem *item)
{
    Q_UNUSED(item);
    emit inventoryElementSelected(inventoryBrowser->currentRow());
}
/*
 * Initilize gui part for information box
 * that shows info about chosen element
 */
void Gui::gameUiSetup_info()
{
    infoGroupBox = new QGroupBox(this);
    infoGroupBox->setGeometry(140,20,120,210);

    label_infoInfo = new QLabel(infoGroupBox);
    label_infoInfo->setGeometry(2,22, 110, 130);
    label_infoInfo->setWordWrap(true);
    label_infoInfo->setAlignment(Qt::AlignLeft | Qt::AlignTop );

    label_infoDesc = new QLabel(infoGroupBox);
    label_infoDesc->setGeometry(2,120, 110, 90);
    label_infoDesc->setStyleSheet("font-style: italic");
    label_infoDesc->setWordWrap(true);
    label_infoDesc->setAlignment( Qt::AlignLeft | Qt::AlignBottom );

    infoGroupBox->hide();

}
/*
 * setup inventory gui, qlistwidget + label to show
 */
void Gui::gameUiSetup_inv()
{
    label_inventory = new QLabel(this);
    label_inventory->setGeometry(60,250,40,20);

    label_inventory_c = new QLabel("Size", this);
    label_inventory_c->setGeometry(20,250,40,20);

    inventoryBrowser = new QListWidget(this);
    inventoryBrowser->setGeometry(20,270,100,180);

    // inventory connects
    connect(inventoryBrowser, &QListWidget::itemClicked, this, &Gui::onInventoryItemSelected);
}

void Gui::gameUiSetup_playerInfo()
{
    int ilsp = 20;     // started point for info lables;
    int ilsp_s = 20;   // step for started point for info lables;
    QSize ils_c = QSize(60,20); // size of info labels
    QSize ils = QSize(20,20); // size of info labels

    label_step_c = new QLabel("Step",this);
    label_step_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_step = new QLabel(this);
    label_step->setGeometry(QRect(QPoint(80, ilsp),ils));

    ilsp+= 1.5*ilsp_s;
    label_level_c = new QLabel("Level",this);
    label_level_c->setGeometry(QRect(QPoint(20, ilsp), ils_c));
    label_level = new QLabel(this);
    label_level->setGeometry(QRect(QPoint(80, ilsp),ils));

    ilsp+=ilsp_s;
    label_strength_c = new QLabel("Strength",this);
    label_strength_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_strength = new QLabel(this);
    label_strength->setGeometry(QRect(QPoint(80, ilsp),ils));

    ilsp+=ilsp_s;
    label_agility_c = new QLabel("Agility",this);
    label_agility_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_agility = new QLabel(this);
    label_agility->setGeometry(QRect(QPoint(80, ilsp),ils));

    ilsp+=ilsp_s;
    label_energy_c = new QLabel("Energy",this);
    label_energy_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_energy = new QLabel(this);
    label_energy->setGeometry(QRect(QPoint(80, ilsp),ils));

    ilsp+=ilsp_s;
    label_vitality_c = new QLabel("Vitality",this);
    label_vitality_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_vitality = new QLabel(this);
    label_vitality->setGeometry(QRect(QPoint(80, ilsp),ils));

    ilsp+=1.5 * ilsp_s;
    label_race_c = new QLabel("Race",this);
    label_race_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_race = new QLabel(this);
    label_race->setGeometry(QRect(QPoint(80, ilsp),ils_c));

    ilsp+=ilsp_s;
    label_class_c = new QLabel("Class",this);
    label_class_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_class = new QLabel(this);
    label_class->setGeometry(QRect(QPoint(80, ilsp),ils_c));

    ilsp+=1.5 * ilsp_s;
    healthBar = new QProgressBar(this);
    healthBar->setGeometry(QRect(QPoint(20, ilsp),QSize(100,20)));
    healthBar->setFormat("%v");
}

