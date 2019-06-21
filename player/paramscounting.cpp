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
