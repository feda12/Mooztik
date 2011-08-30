#ifndef PHOTOSWINDOW_H
#define PHOTOSWINDOW_H

#include <QMainWindow>
#include "accordeon.h"

namespace Mooztik{
namespace Photos{

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
} //Namespace Photos


#endif //PHOTOSWINDOW_H
