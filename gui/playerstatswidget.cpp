#include "playerstatswidget.h"

PlayerStatsWidget::PlayerStatsWidget(QWidget *parent) : QWidget (parent)
{
    initUI();
}

void PlayerStatsWidget::updatePlayerInfo(int **stats, int level, QString raceName, QString className, int step, float health)
{
    label_strength->setText(QString::number(*(stats[0])));
    label_agility->setText(QString::number(*(stats[1])));
    label_energy->setText(QString::number(*(stats[2])));
    label_vitality->setText(QString::number(*(stats[3])));

    label_level->setText(QString::number(level));
    label_step->setText(QString::number(step));

    label_race->setText(raceName);
    label_class->setText(className);

    healthBar->setMaximum(static_cast<int>(health));
    healthBar->setValue(static_cast<int>(health));
}




void PlayerStatsWidget::initUI()
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
