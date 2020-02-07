#include "updclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UpdClient w;
    w.show();

    return a.exec();
}
