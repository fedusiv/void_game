#include <QApplication>
#include "gamemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameManager * gm = new GameManager();
    Q_UNUSED(gm);
    return a.exec();
}
