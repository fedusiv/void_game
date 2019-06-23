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
    inventoryBrowser->clear();
    label_inventory->setText( QString::number( static_cast<double>(*(status->size)) ) + " / " + QString::number( static_cast<double>(*(status->max) )));
    for( int i = 0; i < *(status->count); i++)
        inventoryBrowser->addItem(status->list->at(i));
}
/*
 * desc : show information about selected element in inventory
 */
void Gui::updateInfoElement(QSharedPointer<EquipStatus> equip)
{
    infoGroupBox->setTitle(equip->name);
    QString iseq = (equip->equiped ? "Equipped" : "Useless");   // IS EQuipped
    QString dmg   =  equip->damage == 0.0 ? QString("") : QString("Dmg : "+ QString::number(static_cast<double>(equip->damage)) + '\n');
    QString armor = equip->armor == 0.0 ? QString("") : QString("Armor : "+ QString::number(static_cast<double>(equip->armor)) + '\n');
    QString requirments = "Need :";
    if ( *(equip->require) > 0 ) requirments.append("\n  Strength : " + QString::number(*(equip->   require++)));
    if ( *(equip->require) > 0 ) requirments.append("\n  Agility : " + QString::number(*(equip->    require++)));
    if ( *(equip->require) > 0 ) requirments.append("\n  Energy : " + QString::number(*(equip->     require++)));
    if ( *(equip->require) > 0 ) requirments.append("\n  Vitality : " + QString::number(*(equip->   require++)));

    QString full = QString(
                equip->type + '\n' +        // shows type of equipment
                iseq + '\n' +               // is equipped
                dmg  + armor+               // damage for weapons + armor for cloth
                requirments +               // required main stats for this equipment
                '\n' + "Weight : " + QString::number(static_cast<double>(equip->size)) +  // size of equip
                '\n' + "Level : " + QString::number(static_cast<double>(equip->level)));  // level of equip
    label_infoInfo->setText(full);
    label_infoDesc->setText(equip->desc);

    if( equip->equiped )
    {
        // equipment equipped, opportunity to take off from player
        inventoryEquipButton->setText("Take off");
    }else
    {
        // equipment just useless lying in players inventory, so give opportunity to equip
        inventoryEquipButton->setText("Equip");
    }

    updateSkillInfo(equip->skill);
    inventoryManagment_Frame->show();   // shows frame of inventory managment
    infoGroupBox->show();   // shows info box
}

/*
 * desc : updating information about skills in skill tabwidget
 */
void Gui::updateSkillInfo(Skill * skill)
{
    uint8_t counter = 0;
    // delete widgets in tab widget
    for (int i = 0; i < skillTabWidget->count(); i ++ )
    {
       QWidget *w = skillTabWidget->widget(i);
       skillTabWidget->removeTab(i);
       delete  w;
    }


    while( skill != nullptr)
    {
        skillTabWidget->addTab(new SkillInfoWidget(skillTabWidget, skill->getDesc() +
                                                   "\n"+ skill->getCostStr() ), skill->getName());
        counter++;
        skill = skill->getBinded();
    }

    if (counter > 0) skillTabWidget->show();

}

void Gui::startGame()
{
    enterUiHide();
    gameUiSetup();
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
    gameUiSetup_skills();//setup skill information box
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
 * desc : slots reacting when clicked on inventory equip button
 * to equip or take off equipment. It just send to player inventory equipment id, and
 * inventory desides inside that need to do with equipment. take off or equip
 */
void Gui::onInventoryEquipButton()
{
    emit inventoryEquipElement(inventoryBrowser->currentRow());
}

void Gui::onInventoryRemoveEquipButton()
{
    infoGroupBox->hide();
    emit inventoryRemoveElement(inventoryBrowser->currentRow());
}
/*
 * Initilize gui part for skills tab widget information box
 * that shows info about skills from equipment and choosen skills
 */
void Gui::gameUiSetup_skills()
{
    skillTabWidget = new QTabWidget(this);
    skillTabWidget->setGeometry(160,240,140,210);
    skillTabWidget->hide();
}
/*
 * Initilize gui part for information box
 * that shows info about chosen element
 */
void Gui::gameUiSetup_info()
{
    infoGroupBox = new QGroupBox(this);
    infoGroupBox->setGeometry(160,20,140,210);

    label_infoInfo = new QLabel(infoGroupBox);
    label_infoInfo->setGeometry(2,22, 138, 140);
    label_infoInfo->setWordWrap(true);
    label_infoInfo->setAlignment(Qt::AlignLeft | Qt::AlignTop );
    label_infoInfo->setStyleSheet("font-size : 10pt");

    label_infoDesc = new QLabel(infoGroupBox);
    label_infoDesc->setGeometry(2,140, 138, 68);
    label_infoDesc->setStyleSheet("font-style: italic ; \
                                   font-size : 9pt");

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
    label_inventory->setGeometry(65,250,55,20);

    label_inventory_c = new QLabel("Size", this);
    label_inventory_c->setGeometry(20,250,35,20);

    inventoryBrowser = new QListWidget(this);
    inventoryBrowser->setGeometry(20,270,135,180);

    inventoryManagment_Frame = new QFrame(this);
    inventoryManagment_Frame->setGeometry(20, 450, 135, 30);

    inventoryEquipButton = new QPushButton(inventoryManagment_Frame);
    inventoryEquipButton->setGeometry(1,1,65,20);
    inventoryEquipButton->setStyleSheet("font-size : 9pt");

    inventoryRemoveButton = new QPushButton(inventoryManagment_Frame);
    inventoryRemoveButton->setText("Remove");
    inventoryRemoveButton->setStyleSheet("font-size : 9pt");
    inventoryRemoveButton->setGeometry(69,1,65,20);

    inventoryManagment_Frame->hide();   // shows inventory managment frame only when item selected.

    // inventory connects
    connect(inventoryBrowser, &QListWidget::itemClicked, this, &Gui::onInventoryItemSelected);
    connect(inventoryEquipButton, &QPushButton::clicked, this, &Gui::onInventoryEquipButton);
    connect(inventoryRemoveButton, &QPushButton::clicked, this, &Gui::onInventoryRemoveEquipButton);
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
    label_step->setGeometry(QRect(QPoint(90, ilsp),ils));

    ilsp+= 1.5*ilsp_s;
    label_level_c = new QLabel("Level",this);
    label_level_c->setGeometry(QRect(QPoint(20, ilsp), ils_c));
    label_level = new QLabel(this);
    label_level->setGeometry(QRect(QPoint(90, ilsp),ils));

    ilsp+=ilsp_s;
    label_strength_c = new QLabel("Strength",this);
    label_strength_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_strength = new QLabel(this);
    label_strength->setGeometry(QRect(QPoint(90, ilsp),ils));

    ilsp+=ilsp_s;
    label_agility_c = new QLabel("Agility",this);
    label_agility_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_agility = new QLabel(this);
    label_agility->setGeometry(QRect(QPoint(90, ilsp),ils));

    ilsp+=ilsp_s;
    label_energy_c = new QLabel("Energy",this);
    label_energy_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_energy = new QLabel(this);
    label_energy->setGeometry(QRect(QPoint(90, ilsp),ils));

    ilsp+=ilsp_s;
    label_vitality_c = new QLabel("Vitality",this);
    label_vitality_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_vitality = new QLabel(this);
    label_vitality->setGeometry(QRect(QPoint(90, ilsp),ils));

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
    healthBar->setGeometry(QRect(QPoint(20, ilsp),QSize(110,20)));
    healthBar->setFormat("%v");
}

