#include "toolbaractiongroup.h"

#include <QDebug>

namespace Qopo{
namespace Gui{

class ToolBarActionGroup::Private {
public:
    QList<Action *> actionList;
    Action *hoveredAction;
    Action *checkedAction;
    int spacing;
    bool pressed;
};
ToolBarActionGroup::ToolBarActionGroup(QWidget *parent) :
    QWidget(parent), d(new ToolBarActionGroup::Private)
{
    setMinimumHeight(35);
    setMaximumHeight(35);
    setMouseTracking(true);

    d->hoveredAction = NULL;
    d->pressed = false;
    d->spacing = 20;
}

Action *ToolBarActionGroup::addAction(const QString &text)
{
    Action *action = new Action(text, this);
    addAction(action);
    return action;
}
Action *ToolBarActionGroup::addAction(const QIcon &icon, const QIcon &checkedIcon)
{
    Action *action = new Action(this);
    action->setIcon(icon);
    action->setCheckedIcon(checkedIcon);
    addAction(action);
    return action;
}

void ToolBarActionGroup::addAction(Action *action)
{
    action->setCheckable(true);
    d->actionList.push_back(action);
    update();
    setMaximumSize(minimumSizeHint());
}

void ToolBarActionGroup::setSpacing(int s)
{
    d->spacing = s;
    update();
}

int ToolBarActionGroup::spacing() const
{
    return d->spacing;
}

Action *ToolBarActionGroup::addSeparator()
{
    Action *action = new Action(this);
    action->setSeparator(true);
    addAction(action);
    return action;
}

void ToolBarActionGroup::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(Qt::black);

    int a_width = 0, a_x = 0;
    foreach(Action *action, d->actionList)
    {
        a_width = calculateActionWidth(action);
        QRect rectAction(a_x, 0, a_width, height());
        a_x += a_width;
        paintAction(rectAction, p, action);
    }
}

void ToolBarActionGroup::paintAction(QRect &rect, QPainter &p, Action *action)
{
    if(action->isSeparator())
    {
        QLinearGradient gradient(QPoint(0, 0), QPoint(0, rect.height()-2));
        gradient.setColorAt(0, Qt::transparent);
        gradient.setColorAt(0.3, Qt::transparent);
        gradient.setColorAt(0.4, QColor(200, 200, 200));
        gradient.setColorAt(0.6, QColor(200, 200, 200));
        gradient.setColorAt(0.7, Qt::transparent);
        gradient.setColorAt(0.99, Qt::transparent);
        gradient.setColorAt(1, Qt::transparent);

        p.fillRect(rect, QBrush(gradient));
    }
    int icon_size = 24;
    QRect rectIcon(rect.x()+rect.width()/2-icon_size/2, rect.y()+rect.height()/2-icon_size/2,
                   icon_size, icon_size);
    QIcon icon;
    if(action != d->checkedAction)
        icon = action->icon();
    else if(action == d->checkedAction)
        icon = action->checkedIcon();
    icon.paint(&p, rectIcon, Qt::AlignCenter);
}

QSize ToolBarActionGroup::minimumSizeHint() const
{
    int width = 0;
    foreach(Action *action, d->actionList)
        width += calculateActionWidth(action);

    return QSize(width, 30);
}
int ToolBarActionGroup::calculateActionWidth(Action *action) const
{
    if(action->isSeparator())
        return 1;
    else
        return 24 +d->spacing;
}
void ToolBarActionGroup::mouseMoveEvent (QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
}

void ToolBarActionGroup::mouseReleaseEvent (QMouseEvent *event) {

    QWidget::mouseReleaseEvent(event);
    if(!d->pressed) return;
    if(d->hoveredAction != hoveredAction(event->pos())) return;
    d->hoveredAction = hoveredAction(event->pos());
    if (d->hoveredAction != NULL) {
        if(d->checkedAction != d->hoveredAction ||
                (d->checkedAction == d->hoveredAction && !d->checkedAction->isChecked()))
        {
            d->checkedAction = d->hoveredAction;
            d->hoveredAction->setChecked(true);
            if(d->actionList.size() > 1)
            d->hoveredAction->trigger();
            setFocus();
            update();
            return;
        }
        if(d->checkedAction == d->hoveredAction && d->checkedAction->isChecked())
        {
            d->checkedAction->setChecked(false);
            d->checkedAction = NULL;
            setFocus();
            update();
            return;
        }

    }

}
void ToolBarActionGroup::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    d->hoveredAction = hoveredAction(event->pos());
    if(d->hoveredAction != NULL)
    {
        d->pressed = true;
    }
}
Action *ToolBarActionGroup::hoveredAction (const QPoint& pos) const {
    if(pos.y() < 4 || pos.y() >= height())
        return NULL;
    int a_x = 0, a_width = 0;
    Action *c_action = NULL;
    foreach(Action *action, d->actionList)
    {
        a_width = calculateActionWidth(action);
        if(QRect(a_x, 0, a_width, height()).contains(pos) && !action->isSeparator())
        {
            c_action = action;
        }
        a_x += a_width;
    }

    return c_action;
}

}} //NAMESPACE
