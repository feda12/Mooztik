#include "controller.h"

namespace Mooztik {

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    _windows = new QStackedWidget;

    _modulesWindow = new Gui::ModulesWindow(_windows);
    _loginWindow = new Gui::LoginWindow(_windows);

    _windows->addWidget(_loginWindow);
    _windows->addWidget(_modulesWindow);

    _windows->setCurrentWidget(_loginWindow);

    QObject::connect(_loginWindow, SIGNAL(connect()), this, SLOT(login()));

    QObject::connect(_modulesWindow, SIGNAL(disconnectUser()), this, SLOT(disconnect()));

    //addUser("pseudo", "mot de passe en clair", "emplacement de stockage");
}

void Controller::disconnect()
{
    _user->closeSession();

    _modulesWindow->clearWindow();
    QSqlDatabase::database().close();
    QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());
    goLoginWindow();
}

void Controller::login()
{
    Error err = connectUser(_loginWindow->username(), _loginWindow->password());
    _loginWindow->setPassword(QString());
    if(err != NONE)
        _loginWindow->error(err);
    else
    {
        _modulesWindow->userLogin(_user);
        goModulesWindow();
    }
    _loginWindow->setUsername(QString());
    return;
}

void Controller::goLoginWindow()
{
    _windows->setCurrentWidget(_loginWindow);
}

void Controller::goModulesWindow()
{
    _windows->setCurrentWidget(_modulesWindow);
}
void Controller::goUserPreferences()
{

}

Error Controller::addUser(const QString &username, const QString &password, const QString &folderPath)
{
    QString path = folderPath;
    Core::User user;
    if(userExists(username))
        return USER_EXISTS;

    if(password.size() < 6)
        return PASSWORD_UNDER_LIMIT;

    if(path.at(path.size()-1) != QDir::separator())
        path.append(QDir::separator());

    path = QDir::toNativeSeparators(path);

    QDir dir(path);
    if(!dir.exists())
        return INVALID_PATH;

    path.append("Mooztik");
    int pathExistsCount = 0;
    //Tant que le chemin existe déjà, on ajout un nombre pour le différencier
    while(dir.exists())
    {
        pathExistsCount ++;
        dir = QDir(path+"_"+QString::number(pathExistsCount));
    }
    if(path.at(path.size()-1) != QDir::separator())
        path.append(QDir::separator());

    path = QDir::toNativeSeparators(path);

    if(!dir.mkdir(path))
        return FAILED_DIR_CREATION;

    user.setUsername(username);
    user.setNewPassword(password);
    user.setFolderPath(path);
    QString dbPath = user.folderPath().append(QCoreApplication::applicationName()).append(".db");
    if(!Database::connect(dbPath))
        return DB_CREATION_FAILED;

    qx::dao::create_table<Mooztik::Core::movie>();
    QSettings settings(QSettings::SystemScope, "Qopo", "Qopo");
    settings.beginGroup("Users");
    settings.setValue(username, user.password());
    settings.beginGroup(username);
    settings.setValue("folderPath", path);
    settings.endGroup();
    settings.endGroup();

    return NONE;
}

Error Controller::connectUser(const QString &username, const QString &password)
{
    /* On récupère les données de l'utilisateur afin de pouvoir vérifier son identité */
    QSettings settings(QSettings::SystemScope, "Qopo", "Qopo");
    settings.beginGroup("Users");
    qDebug() << settings.allKeys();
    QString key = settings.allKeys().value(settings.allKeys().indexOf(username));
    Core::User tmpUser;
    tmpUser = Core::User();
    tmpUser.setUsername(key);
    tmpUser.setPassword(settings.value(key).toString());
    settings.beginGroup(key);
    tmpUser.setFolderPath(settings.value("folderPath").toString());
    settings.endGroup();

    /* On vérifie à la fois que l'utilisateur existe et que le mot de passe est correct */
    if(Core::User::cryptPassword(password, username) != tmpUser.password())
    {
        qDebug() << "[Controller] Invalid username/password";
       return INVALID_USERNAME_PASSWORD;
    }

    qDebug() << "[Controller] Connecting to database";
    if(!Database::connect(tmpUser.folderPath().append(QCoreApplication::applicationName()).append(".db")))
    {
        qDebug() << "[Controller] Failed to connect database";
        return DB_CONNECTION_FAILED;
    }
    _user = UserPtr(new Core::User(tmpUser));
    qx::QxSqlDatabase::getSingleton()->getDatabase().open();
    loadUser();
    goModulesWindow();

    return NONE;
}
bool Controller::userExists(const QString &username)
{
    QSettings settings(QSettings::SystemScope, "Qopo", "Qopo");
    settings.beginGroup("Users");
    return settings.allKeys().contains(username);
}

void Controller::loadUser()
{

}
} //Namespace Mooztik
