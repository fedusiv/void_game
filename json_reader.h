#ifndef JSON_READER_H
#define JSON_READER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include "equip/equip.h"


/*
 * signleton class
 *  read data from json files
 */
class JsonReader
{
public:
    static JsonReader * instance;
    static JsonReader * getInstance()
    {
        if ( instance == nullptr)
        {
            instance = new JsonReader();
        }
        return instance;
    }

    QJsonObject weaponRead(int level); // return information about all weapon at level;
    QJsonObject clothBodyRead(EquipClothType type, int level ); // return information about all body's cloth at level
    QStringList skillWeaponHitsDescRead(int id);    // return string name and description of weapon hit skills ability



private:
    JsonReader();

};

#endif // JSON_READER_H
