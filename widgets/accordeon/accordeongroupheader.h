#ifndef AccordeonGROUPHEADER_H
#define AccordeonGROUPHEADER_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QLinearGradient>
#include "accordeonitem.h"

namespace Qopo{
namespace Gui{

class AccordeonGroupHeader : public QWidget
{
    Q_OBJECT
public:
    explicit AccordeonGroupHeader(QWidget *parent = 0);
    AccordeonGroupHeader(const QString &title,  QWidget *parent = 0);

    void setTitle(const QString &set);
    QString title() const;

    void setSelectable(bool set);
    bool selectable() const;

    void setSelected(bool set);
    bool isSelected() const;

    QColor triangleColor() const;
    void setTriangleColor(const QColor &c);
protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void setup();

signals:
    void clicked();
    void clicked(AccordeonItem *);
private:
    QString m_title;
    bool m_hovered;
    bool m_pressed;
    bool m_selectable;
    bool m_selected;
    QColor _triangleColor;
};

}} //NAMESPACE

#endif // AccordeonGROUPHEADER_H
