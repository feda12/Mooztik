#ifndef AccordeonGROUP_H
#define AccordeonGROUP_H

#include <QtGui>
#include "accordeonitem.h"
#include "accordeongroupheader.h"
#include "accordeonseparator.h"

namespace Qopo{
namespace Gui{

class AccordeonGroup : public QWidget
{
    Q_OBJECT

public:
    AccordeonGroup(QWidget *parent = 0);
    AccordeonGroup(const QString &title, QWidget *parent = 0);

    QString title() const;
    void setTitle(const QString &set);

    bool isExpanded() const;
    void setExpanded(bool expand);

    Action *addItem(const QString &text, bool enableEdition = false, const QString &textIfEmpty = QString());
    void addItem(Action *action, bool enableEdition = false, const QString &textIfEmpty= QString());
    void addItem(AccordeonItem *widget);

    void setItemEditing(Action *itemAction);

    void setHeaderSelectable(bool set);
    bool isHeaderSelectable() const;

    void setHeaderTriangleColor(const QColor &c);
    QColor headerTriangleColor() const;

    void setItemsHeight(int height);
    int itemsHeight() const;

    QSize sizeHint() const;

    Action *currentAction() const { return m_current_action; }
protected:
    void setup();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void itemClicked(AccordeonItem *item);
    void itemEditing(AccordeonItem *item);
    void editionLeaved(AccordeonItem *item);
    void headerClick();
public slots:
    void uncheck();

    void clear()
    {
        foreach(AccordeonItem *item, m_items)
            m_layout->removeWidget(item);
        m_items.clear();
    }
    void setLastItemEdit()
    {
        m_items.last()->edit();
    }
signals:
    void headerClicked();
    void headerClicked(AccordeonGroup*);
    void clicked(AccordeonGroup*);

private:
    QList<AccordeonItem*> m_items;
    Action *m_current_action;
    bool m_isExpanded;
    QVBoxLayout *m_layout;
    AccordeonGroupHeader *m_widgetHeader;
    bool m_pressed;
    bool m_editing;
    bool m_headerSelectable;
    int m_itemsHeight;
};

}} //NAMESPACE

#endif // AccordeonGROUP_H
