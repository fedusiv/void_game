#ifndef PARAMSCOUNTING_H
#define PARAMSCOUNTING_H

#include <QRandomGenerator>
#include <QDebug>

class ParamsCounting
{
public:
    ParamsCounting();

    static int healthCount(int current, int vitality);
    static int inventorySizeCount(int level);
    static int randomSimpleCount(int size);
    static int randomSimpleCount(int min, int max);
    static float weaponCalculateDamage( double min, double max);  // counting weapon damage, when equip created. Not damage in fight
    static float skillWeaponCalculateScalingProcent( double min, double max); // calculate for weapon hit skill scaling ability procent

};

#endif // PARAMSCOUNTING_H
