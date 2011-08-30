#ifndef MOVIESMODULE_H
#define MOVIESMODULE_H

#include "module.h"
#include "movieswindow.h"

namespace Mooztik{
namespace Movies {

class Module : public Mooztik::Module
{
    Q_OBJECT
public:
    explicit Module(QObject *parent = 0);

    QMainWindow *getWindow() const;
    QIcon getIcon() const;
    QString getName() const;
    Qopo::Gui::ToolBar *getToolBar();

    bool close();
    bool open();

private:
    Window *_window;

};

} //Namespace Movies
} //Namespace Mooztik

#endif // MOVIESMODULE_H
