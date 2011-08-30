#include "tabbar.h"

namespace Qopo {
namespace Gui {

/* ============================================================================
 *  PRIVATE Class
 */
class BlackTabBar::Private {
public:
    bool pressed;
    bool tabsClosable;
    bool closePressed;
};

/* ============================================================================
 *  PUBLIC Constructor/Destructors
 */
BlackTabBar::BlackTabBar (QWidget *parent)
    : QTabBar(parent), d(new BlackTabBar::Private)
{
    // Setup Widget Options
    setMouseTracking(true);

    // Setup Members
    d->pressed = false;
    d->tabsClosable = false;
    d->closePressed = false;

    setMinimumHeight(25);
}

BlackTabBar::~BlackTabBar() {
    delete d;
}

/* ============================================================================
 *  PUBLIC Methods
 */

void BlackTabBar::setCheckedAction(int index) {
    if(index == -1) return;
    setCurrentIndex(index);
    update();
}


QSize BlackTabBar::minimumSizeHint (void) const {
    return(QSize(100, minimumHeight()));
}
int BlackTabBar::tabAt(const QPoint &pos) const
{
    if (pos.y() <= 0 || pos.y() >= height())
        return(NULL);
    int buttonsX = 0;
    int buttonWidth = 0;
    int index = -1;
    for(int i = 0; i < count(); i ++)
    {
        buttonWidth = tabSizeHint(i).width();
        if (pos.x() >= buttonsX && pos.x() <= (buttonsX + buttonWidth))
        {
            index = i;
        }
        buttonsX += buttonWidth;
    }
    return index;
}

void BlackTabBar::setTabsClosable(bool closable)
{
    d->tabsClosable = closable;
    update();
}

bool BlackTabBar::tabsClosable() const
{
    return d->tabsClosable;
}

QRect BlackTabBar::tabRect(int index) const
{
    int buttonsX = 0;
    int buttonWidth = 0;
    for(int i = 0; i < count(); i ++)
    {
        buttonWidth = tabSizeHint(index).width();
        if(index == i)
        {
            return QRect(buttonsX, 5, buttonWidth, height());
        }
        buttonsX += buttonWidth;
    }
    return QRect();
}
/* ============================================================================
 *  PROTECTED Methods
 */

void BlackTabBar::paintEvent (QPaintEvent *event) {
    int height = event->rect().height();

    QPainter p(this);

    p.setPen(Qt::NoPen);
    QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, event->rect().height()));
    linearGrad.setColorAt(0, QColor(248, 248, 248));
    linearGrad.setColorAt(1, QColor(238, 238, 238));
    p.fillRect(event->rect(), QBrush(linearGrad));

    p.setPen(QColor(150, 150, 150));
    p.drawLine(QPoint(event->rect().bottomLeft().x(), event->rect().bottomLeft().y()-1),
               QPoint(event->rect().bottomRight().x(), event->rect().bottomRight().y()-1));
    //p.drawLine(event->rect().bottomLeft(), event->rect().bottomRight());
    // Calculate Buttons Size & Location
    int buttonsX = 0;
    // Draw Buttons
    for(int index = 0; index < count(); index ++)
    {
        QRect rect(buttonsX, 0, tabSizeHint(index).width(), height);
        drawButton(&p, rect, index);
        rect.moveLeft(rect.x() + rect.width());
        buttonsX += tabSizeHint(index).width();
    }
}

void BlackTabBar::mouseMoveEvent (QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
}

void BlackTabBar::mousePressEvent (QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    int tabIndex = tabAt(event->pos());
    if(tabAt(event->pos()) != -1)
    {
        d->pressed = true;
        if(tabsClosable())
        {
            QRect tabRect = this->tabRect(tabIndex);
            QRect rectClose(tabRect.x()+tabRect.width()-8, (height()-4)/2, 8, 8);
            if(rectClose.contains(event->pos()) && tabIndex == currentIndex())
            {
                d->closePressed = true;
                update();
            }
        }
    }
}

void BlackTabBar::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    if(!d->pressed) return;
    int tabIndex = tabAt(event->pos());
    if(rect().contains(event->pos()) && tabIndex != -1 && tabIndex != currentIndex())
    {
        if(tabsClosable())
        {
            QRect tabRect = this->tabRect(tabIndex);
            QRect rectClose(tabRect.x()+tabRect.width()-8, (height()-4)/2, 8, 8);
            if(rectClose.contains(event->pos()) && tabIndex == currentIndex())
            {
                emit tabCloseRequested(tabIndex);
            }
        }
        setCurrentIndex(tabIndex);
    }
    d->closePressed = false;
    d->pressed = false;
    update();
}
void BlackTabBar::resizeEvent(QResizeEvent *event)
{
    QTabBar::resizeEvent(event);
}

QSize BlackTabBar::tabSizeHint(int index) const
{
    QFontMetrics fontMetrics(font());
    int tabWidth = 0;
    if(!tabIcon(index).isNull())
        return QSize(height(), minimumHeight());
    tabWidth += fontMetrics.width(tabText(index)+10);
    if(this->tabsClosable())
        tabWidth += 15;
    return QSize(tabWidth+14, minimumHeight());
}

/* ============================================================================
 *  PRIVATE Methods
 */
void BlackTabBar::drawUnselectedButton (	QPainter *painter,
                                                const QRect& rect,
                                                int index)
{
    QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
    linearGrad.setColorAt(0, QColor(81, 81, 81));
    linearGrad.setColorAt(1, QColor(64, 64, 64));
    drawButton(painter, rect, linearGrad, QColor(230, 230, 230), index);
}

void BlackTabBar::drawSelectedButton (	QPainter *painter,
                                        const QRect& rect,
                                        int index)
{
    QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
    linearGrad.setColorAt(0, QColor(Qt::white));
    linearGrad.setColorAt(1, QColor(Qt::white));
    drawButton(painter, rect, linearGrad, QColor(230, 230, 230), index);
}

void BlackTabBar::drawButton (QPainter *painter, const QRect& rect, int index)
{
    if (index == currentIndex())
        drawSelectedButton(painter, rect, index);
    else
        drawUnselectedButton(painter, rect, index);
}

void BlackTabBar::drawButton (QPainter *painter, const QRect& rect, const QLinearGradient& gradient, const QColor& color, int index)
{
    painter->save();
    int height = rect.height();
    int width = rect.width();

    painter->setPen(QColor(150, 150, 150));

    if(index == currentIndex())
    {
        painter->fillRect(rect, QBrush(gradient));
        if(currentIndex() != 0)
            painter->drawLine(rect.topLeft(), QPoint(rect.bottomLeft().x(), rect.bottomLeft().y()-1));
        painter->drawLine(rect.topRight(), QPoint(rect.bottomRight().x(), rect.bottomRight().y()-1));
        painter->setPen(QColor(68, 68, 68));
        //painter->drawRoundedRect(roundedRect, 10, 10);
    }

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->translate(rect.x(), rect.y());

    QFont smallerBoldFont;
    smallerBoldFont.setPointSize(smallerBoldFont.pointSize()*.85);
    if(index == currentIndex())
        smallerBoldFont.setBold(true);
    painter->setFont(smallerBoldFont);

    if(index != currentIndex())
    {
        painter->setPen(QColor(Qt::white));
        //painter->drawText(0, -1, width, height, Qt::AlignCenter, action->text());
    }
    painter->setPen(QPen(color, 1));
    int textWidth = width;
    if(tabsClosable())
    {
        textWidth -= 8;
        QRect closeRect(width-8, (height-4)/2, 8, 8);
        if(d->closePressed && index == currentIndex())
        {
            painter->setBrush(QBrush(color));
            painter->drawEllipse(closeRect.x()-2, closeRect.y()-2, closeRect.width()+3, closeRect.height()+3);
            painter->setPen(Qt::black);
            painter->setBrush(Qt::NoBrush);
        }
        painter->drawLine(closeRect.topLeft(), closeRect.bottomRight());
        painter->drawLine(closeRect.bottomLeft(), closeRect.topRight());
    }
    int icons_width = 24;
    painter->setPen(QPen(color, 1));
    painter->setRenderHint(QPainter::Antialiasing, true);
    if(tabIcon(index).isNull())
        painter->drawText(0, 0, textWidth, height, Qt::AlignCenter, tabText(index));
    else if (!tabIcon(index).isNull())
        tabIcon(index).paint(painter, rect.width()/2-icons_width/2, rect.height()/2-icons_width/2,
                             icons_width, icons_width);
    painter->restore();
}

void BlackTabBar::wheelEvent(QWheelEvent *event)
{
    event->accept();
}

} //Namespace Gui
} //Namespace Qopo
