#include "accordeonseparator.h"

namespace Qopo {
namespace Gui {

AccordeonSeparator::AccordeonSeparator(QWidget *parent) :
    QWidget(parent)
{
    setMaximumHeight(2);
    setMinimumHeight(2);

    _color = QColor(55, 55, 55);
}

void AccordeonSeparator::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(_color);
    p.drawLine(event->rect().topLeft(), event->rect().topRight());
    p.setPen(QColor(80, 80, 80));
    p.drawLine(event->rect().bottomLeft(), event->rect().bottomRight());
}

} //Namespace Gui
} //Namespace Qopo
