#include <QtGui/QApplication>
#include <QTextCodec>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setApplicationName("Mooztik");
    a.setStyleSheet("QMainWindow::separator{ width: 0px; height: 0px; }");

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

   Mooztik::Controller w;

    return a.exec();
}
