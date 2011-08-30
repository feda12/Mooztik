#ifndef TVSHOWSWINDOW_H
#define TVSHOWSWINDOW_H

#include <QMainWindow>
#include "accordeon.h"

namespace Mooztik{
namespace TvShows{

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
} //Namespace TvShows


#endif //TVSHOWSWINDOW_H
