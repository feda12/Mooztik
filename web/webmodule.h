#ifndef WEBMODULE_H
#define WEBMODULE_H

#include "module.h"
#include "webwindow.h"

namespace Mooztik{
namespace Web{

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
} //Namespace Web


#endif //WEBMODULE_H
