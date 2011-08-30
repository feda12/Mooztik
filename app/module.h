#ifndef MODULE_H
#define MODULE_H

#include <QObject>
#include <QMainWindow>
#include <QIcon>
#include "toolbar/toolbar.h"

namespace Mooztik{

class Module : public QObject
{
    Q_OBJECT
public:
    explicit Module(QObject *parent = 0);

    virtual QMainWindow *getWindow() const = 0;
    virtual QIcon getIcon() const = 0;
    virtual QString getName() const = 0;
    virtual Qopo::Gui::ToolBar * getToolBar()
    {
        return new Qopo::Gui::ToolBar;
    }

    virtual bool close() = 0;
    virtual bool open() = 0;
};
} //Namespace Mooztik

#endif // MODULE_H
