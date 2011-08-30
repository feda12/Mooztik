#include "tvshowsmodule.h"
 
namespace Mooztik{
namespace TvShows{

Module::Module(QObject *parent) :
    Mooztik::Module(parent)
 { 
 
 } 
 
QMainWindow *Module::getWindow() const
{
    return new Window();
}
QIcon Module::getIcon() const
{
    return QIcon(":/modules/tvshows");
}
QString Module::getName() const
{
    return tr("Séries TV");
}

bool Module::close()
{
    return true;
}

bool Module::open()
{
    return true;
}

} //Namespace Mooztik
} //Namespace TvShows
