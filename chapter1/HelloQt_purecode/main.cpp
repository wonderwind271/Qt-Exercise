#include "widget_purecode.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//application window for output. Basic application is packed in QApplication class
    Widget_purecode w; //default: not show
    //w is the top window
    w.show(); //so show it
    return a.exec();
}
