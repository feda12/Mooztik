#include "accordeongroupheader.h"
#include <QDebug>

namespace Qopo{
namespace Gui{

AccordeonGroupHeader::AccordeonGroupHeader(QWidget *parent) :
    QWidget(parent)
{
    setup();
}

AccordeonGroupHeader::AccordeonGroupHeader(const QString &title, QWidget *parent)
    :QWidget(parent), m_title(title)
{
    setup();
}

QString AccordeonGroupHeader::title() const
{
    return m_title;
}
void AccordeonGroupHeader::setTitle(const QString &set)
{
    m_title = set;
    QFontMetrics fm(font());
    setMinimumWidth(fm.width(m_title));
    update();
}
QColor AccordeonGroupHeader::triangleColor() const
{
    return _triangleColor;
}
void AccordeonGroupHeader::setTriangleColor(const QColor &c)
{
    _triangleColor = c;
    update();
}

void AccordeonGroupHeader::setup()
{
    setMouseTracking(true);

    m_hovered = false;
    m_pressed = false;
    m_selectable = false;
    m_selected = false;
    _triangleColor = QColor(50, 50, 50);
}

void AccordeonGroupHeader::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QFont font(p.font());
    font.setPointSize(font.pointSize()*0.8);
    p.setFont(font);
    p.translate(event->rect().topLeft());
    QRect headerText(20, 0, event->rect().width(), event->rect().height());

    if(m_hovered|| m_selected)
    {
        QLinearGradient linearGrad(QPointF(0, 0), QPointF(width(), 0));
        linearGrad.setColorAt(0, QColor(53, 53, 53));
        linearGrad.setColorAt(1, QColor(63, 63, 63));
        p.fillRect(event->rect(), QBrush(linearGrad));
    }
    if(m_selected)
    {
        p.setPen(QColor(50, 50, 50));
        p.drawLine(event->rect().topLeft(), event->rect().topRight());
        p.setPen(QColor(55, 55, 55));
        p.drawLine(QPoint(event->rect().bottomLeft().x(), event->rect().bottomLeft().y()-1),
                   QPoint(event->rect().bottomRight().x(), event->rect().bottomRight().y()-1));

        p.setPen(QColor(80, 80, 80));
        p.drawLine(event->rect().bottomLeft(), event->rect().bottomRight());

    }

    p.setRenderHint(QPainter::Antialiasing, true);
    headerText.setX(30);
    headerText.setWidth(headerText.width());

    p.setPen(QColor(230, 230, 230));
    if(m_selected)
        p.setPen(Qt::white);
    p.drawText(headerText, Qt::AlignLeft | Qt::AlignVCenter, m_title);

    QPainterPath triangle(QPoint(width(), 0));
    triangle.lineTo(width()-15, height()/2);
    triangle.lineTo(width(), height());
    triangle.closeSubpath();
    if(m_selected)
        p.fillPath(triangle, QColor(_triangleColor));
}

void AccordeonGroupHeader::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    m_pressed = true;
    update();
}

void AccordeonGroupHeader::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

    if(!rect().contains(event->pos()) || !m_pressed)
    {
        m_pressed = false;
        return;
    }
    if(m_selectable)
        m_selected = true;

    emit clicked();
    emit clicked(NULL);

    m_pressed = false;

    update();
}

void AccordeonGroupHeader::enterEvent(QEvent *event)
{
    QWidget::enterEvent(event);

    m_hovered = true;
    update();
}

void AccordeonGroupHeader::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);

    m_hovered = false;
    update();
}

void AccordeonGroupHeader::setSelectable(bool set)
{
    m_selectable = set;
}

bool AccordeonGroupHeader::selectable() const
{
    return m_selectable;
}

void AccordeonGroupHeader::setSelected(bool set)
{
    m_selected = set;
    update();
}

bool AccordeonGroupHeader::isSelected() const
{
    return m_selected;
}

}} //NAMESPACE
