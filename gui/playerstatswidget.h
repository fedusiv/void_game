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
    void updatePlayerInfo(int ** stats, int level,  QString raceName, int step, float health, float energy);

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
    QLabel * label_intelligence_c;
    QLabel * label_intelligence;
    QLabel * label_step_c;
    QLabel * label_step;
    QLabel * label_race_c;
    QLabel * label_race;
    QProgressBar * healthBar;
    QProgressBar * energyBar;
};

#endif // PLAYERSTATSWIDGET_H
