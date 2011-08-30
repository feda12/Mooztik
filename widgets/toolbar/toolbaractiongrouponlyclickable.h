#ifndef TOOLBARACTIONGROUPONLYCLICKABLE_H
#define TOOLBARACTIONGROUPONLYCLICKABLE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QAction>
#include <QFileInfo>
#include "action.h"
#include <QMenu>

namespace Qopo{
namespace Gui{

class ToolBarActionGroupOnlyClickable : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBarActionGroupOnlyClickable(QWidget *parent = 0);

    void addAction(Action *action);
    Action *addAction(const QString &text);
    Action *addAction(const QIcon &icon, const QIcon &checkedIcon = QIcon());
    Action *addSeparator();

    QSize minimumSizeHint() const;
protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    Action *hoveredAction (const QPoint& pos) const;
private:
    int calculateActionWidth(Action *action) const;
    void paintAction(QRect &rect, QPainter &p, Action *action);

    class Private;
    Private *d;
};

}} //NAMESPACE

#endif // TOOLBARACTIONGROUPONLYCLICKABLE_H
