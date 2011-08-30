#include "musicmodule.h"
 
namespace Mooztik{
namespace Music{

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
    return QIcon(":/modules/music");
}
QString Module::getName() const
{
    return tr("Musique");
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
} //Namespace Music
