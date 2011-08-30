#ifndef MUSICMODULE_H
#define MUSICMODULE_H

#include "module.h"
#include "musicwindow.h"

namespace Mooztik{
namespace Music{

class Module: public Mooztik::Module
{
    Q_OBJECT
public:
    Module(QObject *parent = 0);

    QMainWindow *getWindow() const;
    QIcon getIcon() const;
    QString getName() const;

    bool close();
    bool open();
private:
};

} //Namespace Mooztik
} //Namespace Music


#endif //MUSICMODULE_H
