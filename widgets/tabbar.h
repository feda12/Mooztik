/* This is a THBlackBar source code from
    http://th30z.blogspot.com/2009/03/qt4-black-bar-and-buttons_5817.html
    which has been modified.
    Thanks to Mateo Bertozzi.
    */

#ifndef BLACKTABBAR_H
#define BLACKTABBAR_H

#include <QTabBar>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QAction>

namespace Qopo {
namespace Gui {

class BlackTabBar : public QTabBar {

    Q_OBJECT

public:
    BlackTabBar (QWidget *parent = 0);
    ~BlackTabBar();

    void setCheckedAction(int index);
    QSize minimumSizeHint (void) const;
    QSize tabSizeHint(int index) const;
    int tabAt(const QPoint &pos) const;
    QRect tabRect(int index) const;

    void setTabsClosable(bool closable);
    bool tabsClosable() const;

protected:
    void paintEvent (QPaintEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    void mousePressEvent (QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void wheelEvent(QWheelEvent *event);
private:
    void drawUnselectedButton (QPainter *painter,
                               const QRect& rect,
                               int index);
    void drawSelectedButton (	QPainter *painter,
                                const QRect& rect,
                                int index);
    void drawButton (QPainter *painter,
                     const QRect& rect,
                     int index);
    void drawButton (QPainter *painter,
                     const QRect& rect,
                     const QLinearGradient& gradient,
                     const QColor& color,
                     int index);

    class Private;
    Private *d;

};

} //Namespace Gui
} //Namespace Qopo
#endif // BLACKTABBAR_H
