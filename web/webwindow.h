#ifndef WEBWINDOW_H
#define WEBWINDOW_H

#include <QMainWindow>
#include "accordeon.h"

namespace Mooztik{
namespace Web{

class Window: public QMainWindow
{
    Q_OBJECT
public:
    Window(QWidget *parent = 0);

private:
    void setupGui();

private: /* Attributs */
    Qopo::Gui::Accordeon *_navigationLeftBar;
};

} //Namespace Mooztik
} //Namespace Web


#endif //WEBWINDOW_H
