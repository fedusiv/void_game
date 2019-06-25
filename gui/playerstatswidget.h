#ifndef PLAYERSTATSWIDGET_H
#define PLAYERSTATSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QProgressBar>

class PlayerStatsWidget : public QWidget
{
    Q_OBJECT
public:
    PlayerStatsWidget(QWidget * parent);
    void updatePlayerInfo(int ** stats, int level,  QString raceName, QString className, int step, float health);

private:
    void initUI();      // init ui



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
};

#endif // PLAYERSTATSWIDGET_H
