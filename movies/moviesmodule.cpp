#include "moviesmodule.h"

namespace Mooztik {
namespace Movies {

Module::Module(QObject *parent) :
    Mooztik::Module(parent)
{
    _window = new Window();
}

QMainWindow *Module::getWindow() const
{
    return _window;
}
QIcon Module::getIcon() const
{
    return QIcon(":/modules/movies");
}
QString Module::getName() const
{
    return tr("Films");
}
Qopo::Gui::ToolBar *Module::getToolBar()
{
    return _window->toolBar();
}

bool Module::close()
{
    return true;
}

bool Module::open()
{
    return true;
}

} //Namespace Movies
} //Namespace Mooztik
