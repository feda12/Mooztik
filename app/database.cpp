#include "database.h"
#define _SQLITE_

namespace Database
{
bool connect(const QString &databaseName, const QString &hostname, const QString &username,
             const QString &password, const QString &port){
    QSqlDatabase db;
#ifdef _MYSQL_
    qx::QxSqlDatabase::getSingleton()->setDriverName("QMYSQL");
    qx::QxSqlDatabase::getSingleton()->setHostName(hostname);
    qx::QxSqlDatabase::getSingleton()->setUserName(username);
    qx::QxSqlDatabase::getSingleton()->setPort(port.toInt());
    if(port.isEmpty()){
#if defined(Q_WS_MAC)
        qx::QxSqlDatabase::getSingleton()->setPassword(password);
        qx::QxSqlDatabase::getSingleton()->setPort(8889);
#endif
#if defined(Q_WS_WIN)
        qx::QxSqlDatabase::getSingleton()->setPort(3306);
#endif
    }
    qx::QxSqlDatabase::getSingleton()->setDatabaseName(databaseName);

#endif
#ifdef _SQLITE_
    Q_UNUSED(hostname);
    Q_UNUSED(username);
    Q_UNUSED(password);
    Q_UNUSED(port);
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName(databaseName);
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");

#endif
    if (!qx::QxSqlDatabase::getSingleton()->getDatabase().open()) {
        qDebug() << "Cant connect to database.";
        return false;
    }
    return true;
}
} //Namespace Database
