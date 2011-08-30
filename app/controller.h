#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QSettings>
#include <QStackedWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include "user.h"
#include "module.h"
#include "moduleswindow.h"
#include "loginwindow.h"
#include "errors.h"
#include "database.h"

namespace Mooztik {

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = 0);

private slots:
    void disconnect();
    void login();

    void goLoginWindow();
    void goModulesWindow();
    void goUserPreferences();

    Error connectUser(const QString &username, const QString &password);
    Error addUser(const QString &username, const QString &password, const QString &folderPath);
    bool userExists(const QString &username);
    void loadUser();
private:
    UserPtr _user;
    QList<Module*> _modules;
    QStackedWidget *_windows;
    Gui::ModulesWindow *_modulesWindow;
    Gui::LoginWindow *_loginWindow;
};

} //Namespace Mooztik

#endif // CONTROLLER_H
