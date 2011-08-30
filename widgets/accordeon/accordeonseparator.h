#ifndef ACCORDEONSEPARATOR_H
#define ACCORDEONSEPARATOR_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

namespace Qopo {
namespace Gui {

class AccordeonSeparator : public QWidget
{
    Q_OBJECT
public:
    explicit AccordeonSeparator(QWidget *parent = 0);

    void setColor(const QColor &color) { _color = color; }
private:
    QColor _color;
protected:
    void paintEvent(QPaintEvent *event);
};

} //Namespace Gui
} //Namespace Qopo

#endif // ACCORDEONSEPARATOR_H
