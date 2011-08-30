#ifndef DOWNLOADSMODULE_H
#define DOWNLOADSMODULE_H

#include "module.h"
#include "downloadswindow.h"

namespace Mooztik{
namespace Downloads{

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
} //Namespace Downloads


#endif //DOWNLOADSMODULE_H
