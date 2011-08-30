#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QxtLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QAction>
#include <QRegExpValidator>
#include <QPainter>
#include <QPaintEvent>
#include <QEventLoop>
#include <QTimer>

#include "actionlabel.h"

#include "errors.h"

namespace Mooztik{
namespace Gui {
class LoginWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);

    QString password() const;
    void setPassword(const QString &set);

    void setUsername(const QString &set);
    QString username() const;

    void setErrorsLimit(int set);
    int errorsLimit() const;
private:
    QxtLineEdit *m_username;
    QxtLineEdit *m_password;

    QSint::ActionLabel *m_connect;
    QSint::ActionLabel *m_createAccount;

    QLabel *m_announcement;
    QLabel *m_error;

    int m_errors;
    int m_errors_limit;

    QWidget *m_box_widget;
    QWidget *m_widget;
protected:
    void paintEvent(QPaintEvent *event);

    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void error(Error code);

private slots:
    void createAccountClicked();
    void connectClicked();

signals:
    void createAccount();
    void connect();
};

} //Namespace Gui
} //Namespace Mooztik

#endif // LOGINWINDOW_H
