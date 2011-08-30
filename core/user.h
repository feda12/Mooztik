#ifndef USER_H
#define USER_H

#define SEL_AVANT "EE9*e7È&àKmq$^zae"
#define SEL_APRES "x,czc^$z)-zokxé^;lz"

#include <QByteArray>
#include <QCryptographicHash>
#include <QString>
#include <QIcon>
#include <QSet>
#include <QSettings>
#include "module.h"

namespace Mooztik{
namespace Core{

class User
{
public:
    static bool searchByPointerUsername (QSharedPointer<User> o, QString username)
    {
        return o->username() == username;
    }


    static QByteArray cryptPassword(const QString &password, const QString &username)
    {
        return QCryptographicHash::hash(QByteArray(QCryptographicHash::hash(username.toUtf8(), QCryptographicHash::Md5) +
                                                                        QCryptographicHash::hash(QString(SEL_AVANT).toUtf8(), QCryptographicHash::Md5) +
                                                                        QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5) +
                                                                        QCryptographicHash::hash(QString(SEL_APRES).toUtf8(), QCryptographicHash::Md5)), QCryptographicHash::Sha1).toHex();
    }

    User();
    User(const User &user);

    void save();
    void update();

    void setDefaultSession(const QString &set);
    QString defaultSession() const;

    void setAutoconnect(bool set);
    bool autoconnect() const;

    void setAccessibleOnlyUnderDefaultSession(bool set);
    bool accessibleOnlyUnderDefaultSession() const;

    void setUsername(const QString &set);
    QString username() const;

    void setPassword(const QString &set);
    void setNewPassword(const QString &set);
    QByteArray password() const;

    void setFolderPath(const QString &set);
    QString folderPath() const;

    void setAvatar(const QIcon &set);
    QIcon avatar() const;

    void closeSession() {}
private:
    QString m_username;
    QByteArray m_password;
    QIcon m_avatar;
    QString m_folderPath;
    bool m_autoconnect;
    bool m_accesibleOnlyUnderDefaultSession;
    QString m_defaultSession;
};

}} //NAMESPACE

typedef QSharedPointer<Mooztik::Core::User> UserPtr;

#endif // USER_H
