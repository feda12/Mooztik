#ifndef HOMEMODULE_H
#define HOMEMODULE_H

#include "module.h"
#include "homewindow.h"

namespace Mooztik{
namespace Home{

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
} //Namespace Home


#endif //HOMEMODULE_H
