#include "playerstats.h"
#include "paramscounting.h"

PlayerStats::PlayerStats()
    : _Strength(1), _Agility(1), _Intelligence(1), _Level(1), _Health_max(50), _Energy_max(10)
{
    _statsArray[0] = &_Strength;
    _statsArray[1] = &_Agility;
    _statsArray[2] = &_Intelligence;

    _Health = _Health_max;
    _Energy = _Energy_max;
}

int ** PlayerStats::getStats()
{
    return _statsArray ;
}

int PlayerStats::getLevel()
{
    return _Level;
}
