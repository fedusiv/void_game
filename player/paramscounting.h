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
    static int randomSimpleCount( int size);

};

#endif // PARAMSCOUNTING_H
