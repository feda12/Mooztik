#ifndef VIDEOSWINDOW_H
#define VIDEOSWINDOW_H

#include <QMainWindow>
#include "accordeon.h"

namespace Mooztik{
namespace Videos{

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
} //Namespace Videos


#endif //VIDEOSWINDOW_H
