#include "webmodule.h"
 
namespace Mooztik{
namespace Web{

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
    return QIcon(":/modules/web");
}
QString Module::getName() const
{
    return tr("Web");
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
} //Namespace Web
