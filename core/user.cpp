#include "user.h"

namespace Mooztik{
namespace Core{

User::User()
{
    setAvatar(QIcon("/Users/Blecam/Downloads/user_icon.png"));
}

User::User(const User &user)
{
    m_username = user.username();
    m_password = user.password();
    m_avatar = user.avatar();
    m_folderPath = user.folderPath();
}

void User::save()
{
    QSettings settings(QSettings::SystemScope, "Qopo", "Qopo");
    settings.beginGroup("Users");
    settings.setValue(m_username, m_password);

    settings.beginGroup(m_username);
    settings.setValue("folderPath", m_folderPath);
    settings.endGroup();

    settings.endGroup();
}

void User::update()
{
    QSettings settings(QSettings::SystemScope, "Qopo", "Qopo");
    settings.beginGroup("Users/"+m_username);
    m_folderPath = settings.value("folderPath").toString();
    settings.endGroup();
}

void User::setDefaultSession(const QString &set)
{
    m_defaultSession = set;
}

QString User::defaultSession() const
{
    return m_defaultSession;
}

void User::setAutoconnect(bool set)
{
    m_autoconnect = set;
}

bool User::autoconnect() const
{
    return m_autoconnect;
}

void User::setAccessibleOnlyUnderDefaultSession(bool set)
{
    m_accesibleOnlyUnderDefaultSession = set;
}

bool User::accessibleOnlyUnderDefaultSession() const
{
    return m_accesibleOnlyUnderDefaultSession;
}

void User::setUsername(const QString &set)
{
    m_username = set;
}

QString User::username() const
{
    return m_username;
}

void User::setPassword(const QString &set)
{
    m_password = set.toUtf8();
}

void User::setNewPassword(const QString &set)
{
    QByteArray password_hash = User::cryptPassword(set, m_username);
    if(password_hash != m_password)
        m_password = password_hash;
}

QByteArray User::password() const
{
    return m_password;
}

void User::setFolderPath(const QString &set)
{
    m_folderPath = set;
}

QString User::folderPath() const
{
    return m_folderPath;
}

void User::setAvatar(const QIcon &set)
{
    m_avatar = set;
}

QIcon User::avatar() const
{
    return m_avatar;
}

}} //NAMESPACE
