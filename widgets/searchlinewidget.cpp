#include "searchlinewidget.h"

namespace Qopo{
namespace Gui{

SearchLineWidget::SearchLineWidget(QWidget *parent) :
    QWidget(parent)
{
    _lineEdit = new QxtLineEdit(this);
    _lineEdit->setStyleSheet("border: none; color: rgb(170, 170, 170);");
    _lineEdit->setSampleText(tr("Chercher..."));
    _lineEdit->setAttribute(Qt::WA_MacShowFocusRect, false);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addSpacing(23);
    layout->addWidget(_lineEdit, 1000, Qt::AlignCenter);
    layout->addSpacing(23);

    setMaximumWidth(200);
    setFixedHeight(25);
}
void SearchLineWidget::paintEvent(QPaintEvent *e)
{
    e->accept();
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QColor(211, 215, 224));

    QRect roundedRect(e->rect().x(), e->rect().y(), e->rect().width(), e->rect().height());

    qreal bottomLeftRadius, bottomRightRadius, topLeftRadius, topRightRadius;
    bottomLeftRadius = bottomRightRadius = topLeftRadius = topRightRadius = 15;

    QPainterPath path(QPoint(roundedRect.left(), roundedRect.top() + topLeftRadius));
    path.quadTo(roundedRect.left(), roundedRect.top(), roundedRect.left() + topLeftRadius, roundedRect.top());
    path.lineTo(roundedRect.right() - topRightRadius, roundedRect.top());
    path.quadTo(roundedRect.right(), roundedRect.top(), roundedRect.right(), roundedRect.top()
                + topRightRadius);
    path.lineTo(roundedRect.right(), roundedRect.bottom() - bottomRightRadius);
    path.quadTo(roundedRect.right(), roundedRect.bottom(), roundedRect.right() -
                bottomRightRadius, roundedRect.bottom());
    path.lineTo(roundedRect.left() + bottomLeftRadius, roundedRect.bottom());
    path.quadTo(roundedRect.left(), roundedRect.bottom(), roundedRect.left(), roundedRect.bottom()
                - bottomLeftRadius);
    path.closeSubpath();

    p.drawPath(path);

    QIcon iconAdvSearch(":/actions/advanced_search");
    QIcon iconSearch(":/actions/search");

    QRect rectAdvSearch(5, 5, e->rect().height()-10, e->rect().height()-10);
    iconAdvSearch.paint(&p, rectAdvSearch, Qt::AlignCenter);

    QRect rectSearch(width()-e->rect().height(), 0, e->rect().height(), e->rect().height());
    iconSearch.paint(&p, rectSearch, Qt::AlignCenter);

}
} //Namespace Gui
} //Namespace Qopo
