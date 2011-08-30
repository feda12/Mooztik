#ifndef SEPARATOR_H
#define SEPARATOR_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

namespace Qopo {
namespace Gui {

class Separator : public QWidget
{
    Q_OBJECT
public:
    explicit Separator(QWidget *parent = 0);
    Separator(Qt::Orientation o, QWidget *parent = 0);
    Separator(const QColor &c, Qt::Orientation o = Qt::Vertical, QWidget *parent = 0);

    Qt::Orientation orientation() const;
    void setOrientation(Qt::Orientation o);

    QColor color() const;
    void setColor(const QColor &c);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QColor _color;
    Qt::Orientation _orientation;

};

} //Namespace Gui
} //Namespace Qopo

#endif // SEPARATOR_H
