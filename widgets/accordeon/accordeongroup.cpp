#include "accordeongroup.h"

namespace Qopo{
namespace Gui{

AccordeonGroup::AccordeonGroup(QWidget *parent) :
    QWidget(parent)
{
    setup();
}

AccordeonGroup::AccordeonGroup(const QString &title, QWidget *parent)
    :QWidget(parent)
{
    setup();
    setTitle(title);

    setHeaderSelectable(true);
}

void AccordeonGroup::setup()
{
    m_isExpanded = true;
    m_pressed = false;
    m_editing = false;
    m_headerSelectable = false;
    m_itemsHeight = 23;
    m_current_action = NULL;

    setMinimumHeight(m_itemsHeight);
    setMinimumWidth(150);
    setMouseTracking(true);

    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);

    m_widgetHeader = new AccordeonGroupHeader(this);
    m_widgetHeader->setFixedHeight(30);

    m_layout->addWidget(m_widgetHeader);

    QObject::connect(m_widgetHeader, SIGNAL(clicked()), this, SIGNAL(headerClicked()));
    QObject::connect(m_widgetHeader, SIGNAL(clicked()), this, SLOT(headerClick()));
    QObject::connect(m_widgetHeader, SIGNAL(clicked(AccordeonItem*)), this, SLOT(itemClicked(AccordeonItem*)));

    setLayout(m_layout);
}

QString AccordeonGroup::title() const
{
    return m_widgetHeader->title();
}
void AccordeonGroup::setTitle(const QString &set)
{
    m_widgetHeader->setTitle(set);
}

bool AccordeonGroup::isExpanded() const
{
    return m_isExpanded;
}
void AccordeonGroup::setExpanded(bool expand)
{
    if(expand == m_isExpanded)
        return;
    if (expand) {
        foreach (AccordeonItem *item, m_items) {
            m_layout->addWidget(item);
            item->show();
        }
        this->setFixedHeight(m_itemsHeight*(m_items.size())+30);
    } else {
        foreach (AccordeonItem *item, m_items) {
            m_layout->removeWidget(item);
            item->hide();
        }
        this->setFixedHeight(m_widgetHeader->height());
    }
    m_isExpanded = expand;
}

Action *AccordeonGroup::addItem(const QString &text, bool enableEdition, const QString &textIfEmpty)
{
    if(m_editing)
        return NULL;
    Action *action = new Action(text, this);
    addItem(action, enableEdition, textIfEmpty);
    return action;
}

void AccordeonGroup::addItem(Action *action, bool enableEdition, const QString &textIfEmpty)
{
    action->setCheckable(true);
    AccordeonItem *widget = new AccordeonItem(action, enableEdition, textIfEmpty, this);
    addItem(widget);

}
void AccordeonGroup::addItem(AccordeonItem *widget)
{
    QObject::connect(widget, SIGNAL(clicked(AccordeonItem*)), this, SLOT(itemClicked(AccordeonItem*)));
    m_items.push_back(widget);
    if(m_layout->count() >= 1)
    {
        AccordeonSeparator *separator = new AccordeonSeparator(this);
        separator->setColor(Qt::white);
        m_layout->addWidget(separator);
    }
    m_layout->addWidget(widget);
    widget->show();
    widget->action()->setCheckable(true);
    if(widget->action()->text().isEmpty())
        widget->edit();
    widget->setFixedHeight(30);
    this->setFixedHeight(m_itemsHeight*(m_items.size())+30);
}

QSize AccordeonGroup::sizeHint() const
{
    int width = 0;
    foreach(AccordeonItem *item, m_items)
        if(item->sizeHint().width() > width)
            width = item->sizeHint().width();
    if(m_isExpanded)
        return QSize(width, m_itemsHeight*m_items.size()+30);
    return QSize(width, 30);
}

void AccordeonGroup::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    QRect rectHeader(rect());
    rectHeader.setHeight(m_widgetHeader->height());
    rectHeader.setWidth(rectHeader.width()-m_widgetHeader->height());
    if(rectHeader.contains(event->pos()))
        m_pressed = true;
}

void AccordeonGroup::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    QRect rectHeader(rect());
    rectHeader.setHeight(m_widgetHeader->height());
    rectHeader.setWidth(rectHeader.width()-m_widgetHeader->height());
    if(rectHeader.contains(event->pos()) && !m_widgetHeader->selectable()){
        if(m_pressed)
            setExpanded(!m_isExpanded);
    }
    m_pressed = false;
}

void AccordeonGroup::itemClicked(AccordeonItem *item)
{
    if(item && m_widgetHeader->isSelected())
        m_widgetHeader->setSelected(false);
    foreach(AccordeonItem *t, m_items)
        if(t != item)
            t->setCheckedAction(false);
    if(item)
    {
        m_current_action = item->action();
        m_current_action = item->action();
        emit clicked(this);
    }

}

void AccordeonGroup::uncheck()
{
    if(m_widgetHeader->selectable())
        m_widgetHeader->setSelected(false);
    foreach(AccordeonItem *t, m_items)
        t->setCheckedAction(false);
}

void AccordeonGroup::editionLeaved(AccordeonItem *item)
{
    if(item->action()->text().isEmpty())
    {
        m_layout->removeWidget(item);
        m_items.removeOne(item);
        delete item;
    }
}

void AccordeonGroup::itemEditing(AccordeonItem *item)
{
    m_editing = false;
    itemClicked(item);
}

void AccordeonGroup::setItemEditing(Action *itemAction)
{
    foreach(AccordeonItem *item, m_items)
        if(item->action() == itemAction)
            item->edit();

}

void AccordeonGroup::setItemsHeight(int height)
{
    m_itemsHeight = height;
}

int AccordeonGroup::itemsHeight() const
{
    return m_itemsHeight;
}

void AccordeonGroup::setHeaderSelectable(bool set)
{
    m_headerSelectable = set;
    m_widgetHeader->setSelectable(set);
}
bool AccordeonGroup::isHeaderSelectable() const
{
    return m_headerSelectable;
}

void AccordeonGroup::headerClick()
{
    emit headerClicked(this);
}

void AccordeonGroup::setHeaderTriangleColor(const QColor &c)
{
    m_widgetHeader->setTriangleColor(c);
}

QColor AccordeonGroup::headerTriangleColor() const
{
    return m_widgetHeader->triangleColor();
}

}} //NAMESPACE
