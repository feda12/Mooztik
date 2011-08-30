#include "toolbaractiongrouponlyclickable.h"

namespace Qopo{
namespace Gui{

class ToolBarActionGroupOnlyClickable::Private {
public:
    QList<Action *> actionList;
    Action *hoveredAction;
    Action *checkedAction;
    int spacing;
    bool pressed;
};
ToolBarActionGroupOnlyClickable::ToolBarActionGroupOnlyClickable(QWidget *parent) :
    QWidget(parent), d(new ToolBarActionGroupOnlyClickable::Private)
{
    setMinimumHeight(10);
    setFixedHeight(35);
    setMaximumHeight(50);
    setMouseTracking(true);

    d->hoveredAction = NULL;
    d->pressed = false;
    d->spacing = 20;

    QFont fontLucida(font());
    fontLucida.setFamily("Lucida Grande");
    fontLucida.setPointSize(fontLucida.pointSize()*.85);
    this->setFont(fontLucida);
}

Action *ToolBarActionGroupOnlyClickable::addAction(const QString &text)
{
    Action *action = new Action(text, this);
    addAction(action);
    return action;
}
Action *ToolBarActionGroupOnlyClickable::addAction(const QIcon &icon, const QIcon &checkedIcon)
{
    Action *action = new Action(this);
    action->setIcon(icon);
    action->setCheckedIcon(checkedIcon);
    addAction(action);
    return action;
}

void ToolBarActionGroupOnlyClickable::addAction(Action *action)
{
    action->setCheckable(true);
    d->actionList.push_back(action);
    update();
    setMaximumSize(minimumSizeHint());
}
Action *ToolBarActionGroupOnlyClickable::addSeparator()
{
    Action *action = new Action(this);
    action->setSeparator(true);
    addAction(action);
    return action;
}

void ToolBarActionGroupOnlyClickable::paintEvent(QPaintEvent *event)
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

void ToolBarActionGroupOnlyClickable::paintAction(QRect &rect, QPainter &p, Action *action)
{
    if(action->isSeparator())
    {
        p.fillRect(rect, QColor(170, 170, 170));
    }
    p.setPen(QColor(94, 94, 94));
    if(action == d->checkedAction)
        p.setPen(QColor(0, 168, 225));
    if(!action->text().isEmpty() && action->icon().isNull())
        p.drawText(rect, Qt::AlignCenter, action->text());

    if(action->text().isEmpty() && !action->icon().isNull())
    {
        int icon_size = 24;
        QRect rectIcon(rect.x()+rect.width()/2-icon_size/2, rect.y()+rect.height()/2-icon_size/2,
                       icon_size, icon_size);
        QIcon icon;
        if(action != d->checkedAction)
            icon = action->icon();
        if(action == d->checkedAction)
            icon = action->checkedIcon();
        icon.paint(&p, rectIcon, Qt::AlignCenter);
    }
}

QSize ToolBarActionGroupOnlyClickable::minimumSizeHint() const
{
    int width = 0;
    foreach(Action *action, d->actionList)
        width += calculateActionWidth(action);

    return QSize(width, 30);
}
int ToolBarActionGroupOnlyClickable::calculateActionWidth(Action *action) const
{
    if(action->isSeparator())
        return 1;
    if(!action->icon().isNull())
        return 16+d->spacing;
    QFontMetrics fm(font());
    return fm.width(action->text()) + d->spacing;
}
void ToolBarActionGroupOnlyClickable::mouseMoveEvent (QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);

}

void ToolBarActionGroupOnlyClickable::mouseReleaseEvent (QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    if(d->hoveredAction != hoveredAction(event->pos()))
    {
        d->checkedAction = NULL;
        update();
        return;
    }
    if(d->checkedAction)
    {
        d->checkedAction->trigger();
        setFocus();
    }
    d->checkedAction = NULL;
    update();
}
void ToolBarActionGroupOnlyClickable::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    d->hoveredAction = hoveredAction(event->pos());
    if (d->hoveredAction != NULL) {
        if(d->checkedAction != d->hoveredAction ||
                (d->checkedAction == d->hoveredAction && !d->checkedAction->isChecked()))
        {
            d->checkedAction = d->hoveredAction;
            setFocus();
            update();
            return;
        }
        if(d->checkedAction == d->hoveredAction&& d->checkedAction->isChecked())
        {
            setFocus();
            update();
            return;
        }

    }
}
Action *ToolBarActionGroupOnlyClickable::hoveredAction (const QPoint& pos) const {
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
