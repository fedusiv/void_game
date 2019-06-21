#ifndef JSON_READER_H
#define JSON_READER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

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

    int weaponSize(int level);  // return full mount of weapons at level 0
    QJsonObject weaponRead(int level); // return information about all weapon at level;

private:
    JsonReader();

};

#endif // JSON_READER_H
