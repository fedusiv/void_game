#include "json_reader.h"

JsonReader * JsonReader::instance = nullptr;

JsonReader::JsonReader()
{

}
/*
 * desc : return QJsonobject of all information about weapon on it is level
 * @param : level of weapon
 * @return: QJsonObject
 */
QJsonObject JsonReader::weaponRead(int level)
{
    QString path = ":/weapon/json_files/weaponL" + QString::number(level)  +".json";
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    return doc.object();
}

/*
 * desc : return QJsonobject of all information about given cloth on it is level
 * @param : level of body cloth
 * @return: QJsonObject
 */
QJsonObject JsonReader::clothBodyRead(EquipClothType type, int level)
{
    QString type_path;
    switch ( type )
    {
    case EquipClothType::Head :
    type_path = "head";
    break;
    case EquipClothType::Body :
    type_path = "body";
        break;
    case EquipClothType::Arms :
    type_path = "arms";
        break;
    case EquipClothType::Legs :
    type_path = "legs";
        break;
    case EquipClothType::Feet :
    type_path = "feet";
        break;
    case EquipClothType::Accessorize :
    type_path = "accessorize";
        break;
    }
    QString path = ":/cloth/json_files/"+type_path +"L" + QString::number(level)  +".json";
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    return doc.object();
}
/*
 * desc : return QStringList description and name from json file, where written all descriptions about weapon hits abilities
 * @param : iterator in JSON array
 * @return: QStringList
 */
QStringList JsonReader::skillWeaponHitsDescRead(int id)
{
    QStringList list;
    QString path = ":/skills/json_files/weaponHitsDesc.json";
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray array = doc.object()["desc"].toArray();
    list.append( array[id].toString() );
    array = doc.object()["name"].toArray();
    list.append( array[id].toString() );
    return list;
}

