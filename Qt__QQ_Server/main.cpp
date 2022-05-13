#include "Qt__QQ_Server.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt__QQ_Server w;
    w.show();
    return a.exec();
}
