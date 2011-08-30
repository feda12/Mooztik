#ifndef PHOTOSMODULE_H
#define PHOTOSMODULE_H

#include "module.h"
#include "photoswindow.h"

namespace Mooztik{
namespace Photos{

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
} //Namespace Photos


#endif //PHOTOSMODULE_H
