#include "toolbar.h"

namespace Qopo{
namespace Gui{

class ToolBar::Private {
public:
    QHBoxLayout *layout;
    QLinearGradient backgroundGrad;
    QColor lineColor;
    qreal topLeftRadius;
    qreal topRightRadius;
    qreal bottomLeftRadius;
    qreal bottomRightRadius;
};
ToolBar::ToolBar(QWidget *parent) :
    QWidget(parent), d(new ToolBar::Private)
{
    d->layout = new QHBoxLayout;
    d->layout->setMargin(0);
    d->layout->setSpacing(0);

    this->setLayout(d->layout);

    QLinearGradient gradient(QPoint(0, 0), QPoint(0, height()));
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::white);


    d->backgroundGrad = gradient;

    d->lineColor = QColor(211, 215, 224);

    d->topLeftRadius = 0;
    d->topRightRadius = 0;
    d->bottomLeftRadius = 0;
    d->bottomRightRadius = 0;

    setMinimumHeight(25);
}

void ToolBar::paintEvent(QPaintEvent *event)
{
    QPainter p(this);


    d->backgroundGrad.setStart(event->rect().topLeft());
    d->backgroundGrad.setFinalStop(event->rect().bottomLeft());

    p.fillRect(event->rect(), QBrush(d->backgroundGrad));

    p.setPen(d->lineColor);

    if(property("top-border").toBool())
        p.drawLine(event->rect().topLeft().x(), event->rect().topLeft().y()-1, event->rect().topRight().x(), event->rect().topRight().y()-1);


    p.drawLine(event->rect().bottomLeft(), event->rect().bottomRight());
}
void ToolBar::addSpacing(int spacing)
{
    d->layout->addSpacing(spacing);
}

void ToolBar::addStretch(int stretch)
{
    d->layout->addStretch(stretch);
}

void ToolBar::addWidget(QWidget *widget, int stretch, Qt::Alignment alignment)
{
    d->layout->addWidget(widget, stretch, alignment);
}
void ToolBar::insertWidget(int index, QWidget *widget, int stretch, Qt::Alignment alignment)
{
    d->layout->insertWidget(index, widget, stretch, alignment);
}

void ToolBar::setBackgroundGradient(QLinearGradient grad)
{
    d->backgroundGrad = grad;
    update();
}

void ToolBar::setLineColor(QColor lineColor)
{
    d->lineColor = lineColor;
    update();
}
void ToolBar::setBorderRadius(qreal radius)
{
    d->topLeftRadius = radius;
    d->topRightRadius = radius;
    d->bottomLeftRadius = radius;
    d->bottomRightRadius = radius;

    update();
}
}} //NAMESPACE
