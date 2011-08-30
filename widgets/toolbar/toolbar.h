#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QAction>

#include "actionlabel.h"

namespace Qopo{
namespace Gui{

class ToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBar(QWidget *parent = 0);

    void setBackgroundGradient(QLinearGradient grad);
    void setLineColor(QColor lineColor);
    void setBorderRadius(qreal radius);

    void addSpacing(int spacing);
    void addStretch(int stretch = 0);

    void addWidget(QWidget *widget, int stretch = 0, Qt::Alignment alignment = 0);
    void insertWidget(int index, QWidget *widget, int stretch = 0, Qt::Alignment alignment = 0);
protected:
    void paintEvent(QPaintEvent *event);

private:
    class Private;
    Private *d;
};

}} //NAMESPACE
#endif // TOOLBAR_H
