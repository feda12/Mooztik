#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

#include <QPaintEvent>
#include <QPainter>
#include <QLabel>

namespace Mooztik{
namespace Home{

class Window: public QMainWindow
{
    Q_OBJECT
public:
    Window(QWidget *parent = 0);

private:
    void paintEvent(QPaintEvent *event);
};

} //Namespace Mooztik
} //Namespace Home


#endif //HOMEWINDOW_H
