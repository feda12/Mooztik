#ifndef VIDEOSMODULE_H
#define VIDEOSMODULE_H

#include "module.h"
#include "videoswindow.h"

namespace Mooztik{
namespace Videos{

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
} //Namespace Videos


#endif //VIDEOSMODULE_H
