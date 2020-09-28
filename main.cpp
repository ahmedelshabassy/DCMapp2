#include "dcmapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DCMapp w;
    w.show();
    return a.exec();
}
