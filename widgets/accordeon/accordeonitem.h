#ifndef AccordeonITEM_H
#define AccordeonITEM_H

#include <QWidget>
#include <QIcon>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QLineEdit>

#include "action.h"

namespace Qopo{
namespace Gui{

class AccordeonItem : public QWidget
{
    Q_OBJECT
public:
    AccordeonItem(Action *action, bool enableEdition = true, const QString &textIfEmpty = QString(), QWidget *parent = 0);

    void setAction(Action *action);
    Action *setAction(const QString &text, const QIcon &icon = QIcon());
    Action *action() const;

    void setEditable(bool set);
    bool isEditable() const;

    void setCheckedAction(bool set);

    QSize sizeHint() const;

protected:
    virtual void paintEvent(QPaintEvent *event);

    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    virtual void mouseDoubleClickEvent(QMouseEvent *event);

    virtual void resizeEvent(QResizeEvent *event);

    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);

    void setup();
signals:
    void dropEvent(Qopo::Gui::Action *);

    void clicked(AccordeonItem *);
    void leaveEdition(AccordeonItem *);
    void editing(AccordeonItem *);
public slots:
    void edit();

protected:
    Action *m_action;
    QLineEdit *m_edit;
    QString m_textIfEmpty;
    bool m_pressed;
    bool m_editing;
    bool m_enableEdition;
    bool m_drop;
};

}} //NAMESPACE

#endif // AccordeonITEM_H
