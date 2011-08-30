#include "photosmodule.h"
 
namespace Mooztik{
namespace Photos{

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
    return QIcon(":/modules/photos");
}
QString Module::getName() const
{
    return tr("Photos");
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
} //Namespace Photos
