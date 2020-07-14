#include "edit.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    edit w;
    w.show();
    return a.exec();
}
