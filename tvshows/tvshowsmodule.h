#ifndef TVSHOWSMODULE_H
#define TVSHOWSMODULE_H

#include "module.h"
#include "tvshowswindow.h"

namespace Mooztik{
namespace TvShows{

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
} //Namespace TvShows


#endif //TVSHOWSMODULE_H
