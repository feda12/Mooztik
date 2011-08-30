#ifndef Accordeon_H
#define Accordeon_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>

#include "action.h"
#include "accordeongroup.h"
#include "accordeonseparator.h"

namespace Qopo{
namespace Gui{

class AccordeonWidget:public QWidget
{
    Q_OBJECT
public:
    AccordeonWidget(QWidget *parent = 0);

    void addGroup(AccordeonGroup *group);
    void addLightSeparator();
    void addStrongSeparator();
    QSize sizeHint() const;

    void clear()
    {
        foreach(AccordeonGroup *group, m_groups)
        {
            m_layout->removeWidget(group);
        }
        m_groups.clear();
    }

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void groupClicked(AccordeonGroup *clicked);

private:
    QVBoxLayout *m_layout;
    QList<AccordeonGroup*> m_groups;
};

class Accordeon : public QScrollArea
{
    Q_OBJECT
public:
    explicit Accordeon(QWidget *parent = 0);

    void addLightSeparator()
    {
        m_widget->addLightSeparator();
    }
    void addStrongSeparator()
    {
        m_widget->addStrongSeparator();
    }
    void addGroup(AccordeonGroup *group);
    void clear() {m_widget->clear(); }
private:
    AccordeonWidget *m_widget;


};

}} //NAMESPACE

#endif // Accordeon_H
