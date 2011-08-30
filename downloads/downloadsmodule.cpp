#include "downloadsmodule.h"
 
namespace Mooztik{
namespace Downloads{

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
    return QIcon(":/modules/downloads");
}
QString Module::getName() const
{
    return tr("Téléchargements");
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
} //Namespace Downloads
