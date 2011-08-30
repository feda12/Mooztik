#include "button.h"

namespace Qopo{
namespace Gui{

class Button::Private {
public:
    QString text;
    QIcon icon;
    qreal topLeftRadius;
    qreal topRightRadius;
    qreal bottomLeftRadius;
    qreal bottomRightRadius;
    bool pressed;
    bool checked;
    bool checkable;
    QString checkedText;
    QIcon checkedIcon;
    QLinearGradient pressedGradient;
    QLinearGradient gradient;
    QColor textColor;
    QColor borderColor;
};

Button::Button(QWidget *parent) :
    QWidget(parent), d(new Button::Private)
{
    setMaximumHeight(20);

    d->pressed = false;
    d->checkable = false;
    d->checked = false;
    d->topLeftRadius
            = d->topRightRadius
            = d->bottomRightRadius
            = d->bottomLeftRadius = 5;
    d->text = QString();

    d->gradient.setColorAt(0, QColor(Qt::white));
    d->gradient.setColorAt(1, QColor(240, 240, 240));

    d->pressedGradient.setColorAt(0, QColor(230, 230, 230));
    d->pressedGradient.setColorAt(1, QColor(Qt::white));

    d->borderColor = QColor(204, 204, 204);
    d->textColor = Qt::black;

    setFixedHeight(25);
}

void Button::setText(const QString &text)
{
    d->text = text;
    update();
}

QString Button::text() const
{
    return d->text;
}

void Button::setIcon(const QIcon &icon)
{
    d->icon = icon;
    update();
}

QIcon Button::icon() const
{
    return d->icon;
}

void Button::setCheckable(bool set)
{
    d->checkable = set;
}

bool Button::isCheckable() const
{
    return d->checkable;
}

void Button::setChecked(bool set)
{
    d->checked = set;
    update();
}

bool Button::isChecked() const
{
    return d->checked;
}

void Button::setCheckedText(const QString &text)
{
    d->checkedText = text;
    update();
}

QString Button::checkedText() const
{
    return d->checkedText;
}

void Button::setCheckedIcon(const QIcon &icon)
{
    d->checkedIcon = icon;
    update();
}

QIcon Button::checkedIcon() const
{
    return d->checkedIcon;
}

void Button::setBorderRadius(qreal rad)
{
    d->topLeftRadius
            = d->topRightRadius
            = d->bottomRightRadius
            = d->bottomLeftRadius = rad;
    update();
}

void Button::setTopLeftRadius(qreal rad)
{
    d->topLeftRadius = rad;
    update();
}

void Button::setTopRightRadius(qreal rad)
{
    d->topRightRadius = rad;
    update();
}

void Button::setBottomLeftRadius(qreal rad)
{
    d->bottomLeftRadius = rad;
    update();
}

void Button::setBottomRightRadius(qreal rad)
{
    d->bottomRightRadius = rad;
    update();
}

qreal Button::topLeftRadius() const
{
    return d->topLeftRadius;
}
qreal Button::topRightRadius() const
{
    return d->topRightRadius;
}
qreal Button::bottomLeftRadius() const
{
    return d->bottomLeftRadius;
}
qreal Button::bottomRightRadius() const
{
    return d->bottomRightRadius;
}

void Button::setPressedGradient(QLinearGradient set)
{
    d->pressedGradient = set;
    update();
}

void Button::setGradient(QLinearGradient set)
{
    d->gradient = set;
    update();
}
void Button::setTextColor(QColor set)
{
    d->textColor = set;
    update();
}

void Button::setBorderColor(QColor set)
{
    d->borderColor = set;
    update();
}
void Button::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    QRect roundedRect(event->rect().x(), event->rect().y(), event->rect().width(), event->rect().height());

    QPainterPath path(QPoint(roundedRect.left(), roundedRect.top() + d->topLeftRadius));
    path.quadTo(roundedRect.left(), roundedRect.top(), roundedRect.left() + d->topLeftRadius, roundedRect.top());
    path.lineTo(roundedRect.right() - d->topRightRadius, roundedRect.top());
    path.quadTo(roundedRect.right(), roundedRect.top(), roundedRect.right(), roundedRect.top()
                + d->topRightRadius);
    path.lineTo(roundedRect.right(), roundedRect.bottom() - d->bottomRightRadius);
    path.quadTo(roundedRect.right(), roundedRect.bottom(), roundedRect.right() -
                d->bottomRightRadius, roundedRect.bottom());
    path.lineTo(roundedRect.left() + d->bottomLeftRadius, roundedRect.bottom());
    path.quadTo(roundedRect.left(), roundedRect.bottom(), roundedRect.left(), roundedRect.bottom()
                - d->bottomLeftRadius);
    path.closeSubpath();

    QLinearGradient gradient;
    if(!d->pressed)
    {
        gradient = d->gradient;
    }
    if(d->pressed || (d->checked && d->checkable))
    {
        gradient = d->pressedGradient;
    }
    if(!isEnabled())
    {
        gradient = QLinearGradient(QPoint(0, 0), QPoint(0, height()));
        gradient.setColorAt(0, QColor(230, 230, 230));
        gradient.setColorAt(1, QColor(200, 200, 200));
    }
    gradient.setStart(QPoint(0, 0));
    gradient.setFinalStop(QPoint(0, height()));
    p.fillPath(path, QBrush(gradient));

    p.setPen(QColor(d->borderColor));
    p.drawPath(path);
    p.setPen(QColor(d->textColor));

    if(d->icon.isNull())
    {
        if(d->checked && d->checkable && !d->checkedText.isEmpty())
            p.drawText(roundedRect, Qt::AlignCenter, d->checkedText);
        if(!d->checkable || !d->checked || d->checkedText.isEmpty())
            p.drawText(roundedRect, Qt::AlignCenter, d->text);
    }
    else
    {
        if(d->checked && d->checkable && !d->checkedIcon.isNull())
               d->checkedIcon.paint(&p, roundedRect, Qt::AlignCenter);
        if(!d->checkable || !d->checked || d->checkedIcon.isNull())
            d->icon.paint(&p, roundedRect.x()+4, roundedRect.y()+4, roundedRect.width()-8
                          , roundedRect.height()-8,  Qt::AlignCenter);
    }
}

void Button::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    d->pressed = true;
    update();
}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    d->pressed = false;
    if(rect().contains(event->pos()))
    {
        emit clicked();
        if(d->checkable)
        {
            d->checked = !d->checked;
            emit checked(d->checked);
        }
    }
    update();
}

QSize Button::minimumSizeHint() const
{
    QFontMetrics fm(font());
    return QSize(fm.width(d->text)+20, fm.height()+10);
}

}} //NAMESPACE
