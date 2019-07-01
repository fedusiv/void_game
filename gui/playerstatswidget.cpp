#include "playerstatswidget.h"

PlayerStatsWidget::PlayerStatsWidget(QWidget *parent) : QWidget (parent)
{
    initUI();
}

void PlayerStatsWidget::updatePlayerInfo(MainPlayerStats *stats, int level, QString raceName, int step, float health, float energy)
{
    label_strength->setText(QString::number(stats->Strength));
    label_agility->setText(QString::number(stats->Agility));
    label_intelligence->setText(QString::number(stats->Intelligence));

    label_level->setText(QString::number(level));
    label_step->setText(QString::number(step));

    label_race->setText(raceName);

    healthBar->setMaximum(static_cast<int>(health));
    healthBar->setValue(static_cast<int>(health));

    energyBar->setMaximum(static_cast<int>(energy));
    energyBar->setValue(static_cast<int>(energy));

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

    ilsp+=1.5*ilsp_s;
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
    label_intelligence_c = new QLabel("Energy",this);
    label_intelligence_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_intelligence = new QLabel(this);
    label_intelligence->setGeometry(QRect(QPoint(90, ilsp),ils));

    ilsp+=1.5 * ilsp_s;
    label_race_c = new QLabel("Race",this);
    label_race_c->setGeometry(QRect(QPoint(20, ilsp),ils_c));
    label_race = new QLabel(this);
    label_race->setGeometry(QRect(QPoint(80, ilsp),ils_c));

    ilsp+=1.5 * ilsp_s;
    healthBar = new QProgressBar(this);
    healthBar->setGeometry(QRect(QPoint(20, ilsp),QSize(110,20)));
    healthBar->setFormat("%v");
    healthBar->setStyleSheet("QProgressBar {text-align: center;\
                              border: 0px}\
                             QProgressBar::chunk {\
                             background-color: #f23737;\
                             border: 2px solid grey; \
                             border-radius: 10px; }");

    ilsp+=1.5 * ilsp_s;
    energyBar = new QProgressBar(this);
    energyBar->setGeometry(QRect(QPoint(20, ilsp),QSize(110,20)));
    energyBar->setFormat("%v");
    energyBar->setStyleSheet("QProgressBar {text-align: center;\
                              border: 0px}\
                             QProgressBar::chunk {\
                             background-color: #378bf1;\
                             border: 2px solid grey; \
                             border-radius: 10px; }");
}
