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
