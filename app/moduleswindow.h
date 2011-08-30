#ifndef MODULESWINDOW_H
#define MODULESWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "applogo.h"
#include "module.h"
#include "tabbar.h"
#include "userprofilewidget.h"
#include "separator.h"
#include "playerbar.h"
#include "moviesmodule.h"
#include "downloadsmodule.h"
#include "homemodule.h"
#include "musicmodule.h"
#include "photosmodule.h"
#include "tvshowsmodule.h"
#include "videosmodule.h"
#include "webmodule.h"

namespace Mooztik {
namespace Gui {

class ModulesWindow : public QMainWindow
{
    Q_OBJECT

public:
    ModulesWindow(QWidget *parent = 0);
    ~ModulesWindow();

private:
    QStackedWidget *_user_modules;
    /* Widgets du header */
    Qopo::Gui::BlackTabBar *_tabsBar;
    UserProfileWidget *_userControl;
    QStackedWidget *_toolbarsStack;
    /* Fin du header */

    QStackedWidget *_tabsStack;

    /* Widgets du footer */
    PlayerBar *_playerBar;
    /*Fin du footer */

    QList<Mooztik::Module*> _modulesList;
protected:
    void setupGui();
    void loadModules();

public slots:
    void userLogin(UserPtr user);
    void clearWindow();

signals:
    void disconnectUser();

private slots:
};

} //Namespace Gui
} //Namespace Mooztik

#endif // MODULESWINDOW_H
