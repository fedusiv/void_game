#include "json_reader.h"

JsonReader * JsonReader::instance = nullptr;

JsonReader::JsonReader()
{

}

int JsonReader::weaponSize(int level)
{

}

QJsonObject JsonReader::weaponRead(int level)
{
    QString path = ":/weapon/json_files/weaponL" + QString::number(level)  +".json";
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    return doc.object();
}
