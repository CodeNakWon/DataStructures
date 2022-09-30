#include "GUIprogramming.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIprogramming w;
    w.show();
    return a.exec();
}
