#include "playerstats.h"
#include "paramscounting.h"

PlayerStats::PlayerStats(int str, int agil, int ener, int vital)
    : _Strength(str), _Agility(agil), _Energy(ener), _Vitality(vital), _Level(1), _Health_max(50)
{
    _statsArray[0] = &_Strength;
    _statsArray[1] = &_Agility;
    _statsArray[2] = &_Energy;
    _statsArray[3] = &_Vitality;

    _Health = _Health_max;
}

int ** PlayerStats::getStats()
{
    return _statsArray ;
}

int PlayerStats::getLevel()
{
    return _Level;
}
