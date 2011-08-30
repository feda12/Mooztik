#include "separator.h"

namespace Qopo {
namespace Gui {

Separator::Separator(QWidget *parent) :
    QWidget(parent), _color(Qt::black), _orientation(Qt::Vertical)
{
    setMaximumWidth(1);
    setMinimumWidth(1);
}

Separator::Separator(Qt::Orientation o, QWidget *parent):
     QWidget(parent), _color(Qt::black), _orientation(o)
{
    if(_orientation == Qt::Vertical){
        setMaximumWidth(1);
        setMinimumWidth(1);
        setMaximumHeight(10000);
        setMinimumHeight(0);
    } else if (_orientation == Qt::Horizontal) {
        setMaximumHeight(1);
        setMinimumHeight(1);
        setMaximumWidth(10000);
        setMinimumWidth(0);
    }
}

Separator::Separator(const QColor &c, Qt::Orientation o, QWidget *parent):
    QWidget(parent), _color(c), _orientation(o)
{
    if(_orientation == Qt::Vertical){
        setMaximumWidth(1);
        setMinimumWidth(1);
        setMaximumHeight(10000);
        setMinimumHeight(0);
    } else if (_orientation == Qt::Horizontal) {
        setMaximumHeight(1);
        setMinimumHeight(1);
        setMaximumWidth(10000);
        setMinimumWidth(0);
    }
}

Qt::Orientation Separator::orientation() const
{
    return _orientation;
}
void Separator::setOrientation(Qt::Orientation o)
{
    _orientation = o;
    if(_orientation == Qt::Vertical){
        setMaximumWidth(1);
        setMinimumWidth(1);
        setMaximumHeight(10000);
        setMinimumHeight(0);
    } else if (_orientation == Qt::Horizontal) {
        setMaximumHeight(1);
        setMinimumHeight(1);
        setMaximumWidth(10000);
        setMinimumWidth(0);
    }
    update();
}

QColor Separator::color() const
{
    return _color;
}
void Separator::setColor(const QColor &c)
{
    _color = c;
    update();
}

void Separator::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(event->rect(), QBrush(_color));
}
} //Namespace Gui
} //Namespace Qopo
