#ifndef USERPROFILEWIDGET_H
#define USERPROFILEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include "user.h"
#include "settings.h"

namespace Mooztik {
namespace Gui {

class UserProfileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UserProfileWidget(QWidget *parent = 0);

    void setUser(UserPtr user);
protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    UserPtr _user;

    bool _pressed;
    bool _disconnectPressed;

signals:
    void disconnectionRequested();
    void clicked();
};

} //Namespace Gui
} //Namespace Mooztik

#endif // USERPROFILEWIDGET_H
