#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QMainWindow>
#include "accordeon.h"

namespace Mooztik{
namespace Music{

class Window: public QMainWindow
{
    Q_OBJECT
public:
    Window(QWidget *parent = 0);

private:
    void setupGui();

private:
    Qopo::Gui::Accordeon *_navigationLeftBar;

};

} //Namespace Mooztik
} //Namespace Music


#endif //MUSICWINDOW_H
