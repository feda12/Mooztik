#include "homemodule.h"
 
namespace Mooztik{
namespace Home{

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
    return QIcon(":/modules/home");
}
QString Module::getName() const
{
    return tr("Accueil");
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
} //Namespace Home
