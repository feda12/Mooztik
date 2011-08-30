#include "userprofilewidget.h"

namespace Mooztik {
namespace Gui {

UserProfileWidget::UserProfileWidget(QWidget *parent) :
    QWidget(parent)
{
    _pressed = false;
    _disconnectPressed = false;
    setFixedWidth(160);
    setMinimumHeight(25);
}

void UserProfileWidget::setUser(UserPtr user)
{
    _user = user;
    update();
}

void UserProfileWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);

    /* Drawing background */
    QLinearGradient gradient(QPoint(0, 0), QPoint(width(), 0));
    if(!_pressed)
    {
        gradient.setColorAt(0, QColor(63, 63, 63));
        gradient.setColorAt(1, QColor(75, 75, 75));

    } else if(_pressed) {
        gradient.setColorAt(0, QColor(53, 53, 53));
        gradient.setColorAt(1, QColor(63, 63, 63));
    }
    p.fillRect(event->rect(), QBrush(gradient));

    /* Drawing separator */
    p.setPen(QColor(55, 55, 55));
    p.drawLine(QPoint(event->rect().bottomLeft().x(), event->rect().bottomLeft().y()-1),
               QPoint(event->rect().bottomRight().x(), event->rect().bottomRight().y()-1));

    p.setPen(QColor(80, 80, 80));
    p.drawLine(event->rect().bottomLeft(), event->rect().bottomRight());

    if(_user.isNull())
        return;

    p.setRenderHint(QPainter::Antialiasing);

    /* Drawing user icon */
    if(!_user->avatar().isNull())
        _user->avatar().paint(&p, 0, 0, height(), height());

    /* Drawing text */
    p.setPen(Qt::white);
    p.drawText(height()+5, 0, width()-(height()+30), height(), Qt::AlignCenter, "blecam");

    /*Drawing disconnection icon */
    QIcon disconnectIcon;
    if(!_disconnectPressed)
        disconnectIcon = QIcon(":/icons/disconnect");
    if(_disconnectPressed)
        disconnectIcon = QIcon(":/icons/disconnect_2");
    disconnectIcon.paint(&p, width()-25, height()/2-8, 16, 16);
}

void UserProfileWidget::mousePressEvent(QMouseEvent *event)
{
    QRect rectDisconnect(width()-25, height()/2-8, 16, 16);
    if(rectDisconnect.contains(event->pos()))
        _disconnectPressed = true;
    else
        _pressed = true;

    update();
    return;
}

void UserProfileWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(!rect().contains(event->pos()))
    {
        _disconnectPressed = false;
        _pressed = false;
        update();
        return;
    }
    if(!_pressed && !_disconnectPressed)
        return;

    if(_disconnectPressed)
    {
        QRect rectDisconnect(width()-25, height()/2-8, 16, 16);
        if(rectDisconnect.contains(event->pos()))
        {
            emit disconnectionRequested();
        }
        _disconnectPressed = false;
        _pressed = false;
        update();
        return;
    }
    if(_pressed)
    {
        QRect rectDisconnect(width()-25, height()/2-8, 16, 16);
        if(!rectDisconnect.contains(event->pos()))
        {
            emit clicked();
        }
        _disconnectPressed = false;
        _pressed = false;
        update();
        return;
    }
    update();
    return;
}

} //Namespace Gui
} //Namespace Mooztik
