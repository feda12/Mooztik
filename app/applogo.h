#ifndef APPLOGO_H
#define APPLOGO_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QApplication>

class AppLogo : public QWidget
{
public:
    AppLogo(QWidget *parent = 0) :
        QWidget(parent)
    {

    }

protected:
    void paintEvent(QPaintEvent *e)
    {
        QPainter p(this);

        QLinearGradient gradient(QPoint(0,0), QPoint(width(), 0));
        gradient.setColorAt(0, QColor(63, 63, 63));
        gradient.setColorAt(1, QColor(75, 75, 75));

        p.fillRect(e->rect(), QBrush(gradient));

        p.setPen(QColor(55, 55, 55));
        p.drawLine(QPoint(e->rect().bottomLeft().x(), e->rect().bottomLeft().y()-1),
                   QPoint(e->rect().bottomRight().x(), e->rect().bottomRight().y()-1));

        p.setPen(QColor(80, 80, 80));
        p.drawLine(e->rect().bottomLeft(), e->rect().bottomRight());

        p.setPen(Qt::white);
        QFont pFont(p.font());
        pFont.setFamily("Myriad");
        pFont.setPixelSize(24);
        p.setFont(pFont);

        p.drawText(e->rect(), Qt::AlignCenter, QApplication::applicationName());
    }
};

#endif // APPLOGO_H
