#ifndef DATABASE_H
#define DATABASE_H

#include "precompiled.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>
#include <QVariant>
#include <QFile>
#include <QDir>

namespace Database
{
    bool connect(const QString &databaseName, const QString &hostname = QString(),
                 const QString &username = QString(), const QString &password = QString(),
                 const QString &port = QString());

} //Namespace Database

#endif // DATABASE_H
