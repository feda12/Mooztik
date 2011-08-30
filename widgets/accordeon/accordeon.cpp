#include "accordeon.h"

namespace Qopo{
namespace Gui{

Accordeon::Accordeon(QWidget *parent) :
    QScrollArea(parent)
{
    setStyleSheet("border:none");
    m_widget = new AccordeonWidget(this);

    this->setMouseTracking(true);

    this->setWidget(m_widget);
    this->setWidgetResizable(true);

    this->setMinimumWidth(150);
    this->setMinimumHeight(450);
}

void Accordeon::addGroup(AccordeonGroup *group)
{
    m_widget->addGroup(group);
}

AccordeonWidget::AccordeonWidget(QWidget *parent): QWidget(parent)
{
    this->setMouseTracking(true);

    m_layout = new QVBoxLayout;
    this->setLayout(m_layout);

    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addStretch(2);
}

void AccordeonWidget::addGroup(AccordeonGroup *group)
{
    m_groups.push_back(group);
    m_layout->insertWidget(m_layout->count()-1, group);
    group->show();

    QObject::connect(group, SIGNAL(clicked(AccordeonGroup*)), this, SLOT(groupClicked(AccordeonGroup*)));
    QObject::connect(group, SIGNAL(headerClicked(AccordeonGroup*)), this, SLOT(groupClicked(AccordeonGroup*)));
}

void AccordeonWidget::addLightSeparator()
{
    AccordeonSeparator *g = new AccordeonSeparator(this);
    g->setColor(Qt::black);
    m_layout->insertWidget(m_layout->count()-1, g);
}
void AccordeonWidget::addStrongSeparator()
{
    AccordeonSeparator *g = new AccordeonSeparator(this);
    m_layout->insertWidget(m_layout->count()-1, g);
}

void AccordeonWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.save();
    QLinearGradient gradient(QPoint(0, 0), QPoint(width(), 0));
    gradient.setColorAt(0, QColor(63, 63, 63));
    gradient.setColorAt(1, QColor(75, 75, 75));

    p.fillRect(this->rect(), QBrush(gradient));
    p.restore();
    QWidget::paintEvent(event);
}

QSize AccordeonWidget::sizeHint() const
{
    int height = 0;
    int width = 150;
    foreach(AccordeonGroup *group, m_groups)
    {
        height += group->sizeHint().height();
        if(group->sizeHint().width() > width)
            width = group->sizeHint().width();
    }
    return QSize(width, height);
}

void AccordeonWidget::groupClicked(AccordeonGroup *clicked)
{
    foreach(AccordeonGroup *t, m_groups)
        if(t != clicked)
            t->uncheck();
}

}} //NAMESPACE
