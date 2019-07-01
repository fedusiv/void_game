#include "playerstats.h"
#include "paramscounting.h"

PlayerStats::PlayerStats()
    :  _Level(1), _Health_max(50), _Energy_max(10)
{
    mainStats = new MainPlayerStats();

    _Health = _Health_max;
    _Energy = _Energy_max;
}

MainPlayerStats *  PlayerStats::getStats()
{
    return mainStats ;
}

int PlayerStats::getLevel()
{
    return _Level;
}
