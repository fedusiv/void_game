#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

// struct stores information in main stats view
class MainPlayerStats
{
public:
    int Strength;
    int Agility;
    int Intelligence;
    int size;               // full amount of main params
    MainPlayerStats(){Strength = 1;Agility = 1;  Intelligence =1;}
    MainPlayerStats(int * array)
    {
        Strength = *array++;
        Agility = *array++;
        Intelligence = *array++;
        size = 3;
    }
    bool check(MainPlayerStats * req)
    {
        if ( req->Strength < Strength) return false;
        if ( req->Agility < Agility) return false;
        if ( req->Intelligence < Intelligence) return false;
        return true;
    }
};

#endif // COMMON_TYPES_H
