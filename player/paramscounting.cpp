#include "paramscounting.h"

ParamsCounting::ParamsCounting()
{

}

int ParamsCounting::healthCount(int current, int vitality)
{
    // health = cur_health + step * (vital - 1)
    int step_value = 5;
    return current + step_value * (vitality - 1);
}

int ParamsCounting::inventorySizeCount( int level)
{
    return 10 + level*2;
}

int ParamsCounting::randomSimpleCount(int size)
{
    int v = QRandomGenerator::global()->bounded(size);
    return v;
}
int ParamsCounting::randomSimpleCount(int min, int max)
{
    int v = QRandomGenerator::global()->bounded(min, max);
    return v;
}
/*
 * desc : calculate damage of weapon equip, all params given and return in float,
 * but calculation with int variables, it could be if only disspersion on integer numbers
 * double cause from json they converted to double, float return cause in game we using float numbers
 * @param : minimal damage of weapon given in docs
 * @param : maximal damage of weapon
 * @return : damage of weapon
 */
float ParamsCounting::weaponCalculateDamage(double min, double max)
{
    int v = QRandomGenerator::global()->bounded(static_cast<int>(min), static_cast<int>(max + 1) );
    return static_cast<float>(v);
}

/*
 * desc : calculate procent of scaling, int given in double cause json,
 * and returns in float
 * @param : minimal increase procent of weapon hit skill scaling ability
 * @param : minimal increase procent of weapon hit skill scaling ability
 * @return : scaling procent
 */
float ParamsCounting::skillWeaponCalculateScalingProcent(double min, double max)
{
    int v = QRandomGenerator::global()->bounded(static_cast<int>(min * 100), static_cast<int>( max * 100 + 1 ));
    return static_cast<float>(v) / 100;
}
