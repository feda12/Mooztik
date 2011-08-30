#include "accordeonitem.h"
#include <QDebug>
namespace Qopo{
namespace Gui{

AccordeonItem::AccordeonItem(Action *action, bool enableEdition, const QString &textIfEmpty ,QWidget *parent):QWidget(parent)
{
    setup();
    m_enableEdition = enableEdition;
    m_textIfEmpty = textIfEmpty;
    setAction(action);
}

void AccordeonItem::setup()
{
    m_pressed = false;
    m_editing = false;
    m_enableEdition = false;
    m_drop = false;

    setAcceptDrops(true);

    this->setMinimumWidth(100);

    m_edit = new QLineEdit(this);
    m_edit->setAttribute(Qt::WA_MacShowFocusRect, false);
    m_edit->setFixedHeight(16);
    QFont fontEdit(font());
    fontEdit.setBold(true);
    fontEdit.setPixelSize(10);
    m_edit->setFont(fontEdit);
    m_edit->setMinimumWidth(10);
    m_edit->move(26, 2);
    m_edit->hide();
}

void AccordeonItem::setAction(Action *action)
{
    m_action = action;
    m_edit->setText(action->text());
    QFontMetrics fm(font());
    this->setMinimumWidth(fm.width(action->text()));
    update();
}

Action *AccordeonItem::setAction(const QString &text, const QIcon &icon)
{
    Action *action =  new Action(text, this);
    action->setIcon(icon);
    setAction(action);
    return action;
}

Action *AccordeonItem::action() const
{
    return m_action;
}

void AccordeonItem::setEditable(bool set)
{
    m_enableEdition = set;
}

bool AccordeonItem::isEditable() const
{
    return m_enableEdition;
}

void AccordeonItem::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QFont smallerBoldFont;
    smallerBoldFont.setPointSize(smallerBoldFont.pointSize()*0.95);
    smallerBoldFont.setFamily("lucida");
    painter.setFont(smallerBoldFont);

    if(m_action->isChecked() || m_editing || m_drop)
    {
        QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
        linearGrad.setColorAt(0, QColor(209, 211, 213));
        linearGrad.setColorAt(1, QColor(208, 208, 208));
        QFontMetrics fm(painter.font());
        QRect roundedRect(10, event->rect().y(), width()-20, height());
        if(fm.width(m_action->text())+26 > width()-20)
            roundedRect.setWidth(width());
        qreal leftTopRadius = 5;
        qreal leftBottomRadius = 5;
        qreal rightTopRadius = 5;
        qreal rightBottomRadius = 5;

        QPainterPath path(QPoint(roundedRect.left(), roundedRect.top() + leftTopRadius));
        path.quadTo(roundedRect.left(), roundedRect.top(), roundedRect.left() + leftTopRadius, roundedRect.top());
        path.lineTo(roundedRect.right() - rightTopRadius, roundedRect.top());
        path.quadTo(roundedRect.right(), roundedRect.top(), roundedRect.right(), roundedRect.top() + rightTopRadius);
        path.lineTo(roundedRect.right(), roundedRect.bottom() - rightBottomRadius);
        path.quadTo(roundedRect.right(), roundedRect.bottom(), roundedRect.right() - rightBottomRadius, roundedRect.bottom());
        path.lineTo(roundedRect.left() + leftBottomRadius, roundedRect.bottom());
        path.quadTo(roundedRect.left(), roundedRect.bottom(), roundedRect.left(), roundedRect.bottom() - leftBottomRadius);
        path.closeSubpath();
        QPen pen;

        if(!m_drop)
        {
            pen.setWidth(2);
            painter.setPen(pen);
            //painter.fillPath(path, QBrush(QColor(210, 229, 234)));
        }

        pen.setColor(QColor(0, 128, 225));
        pen.setWidth(1);
        painter.setPen(pen);
        if(m_drop)
        {
            painter.fillPath(path, QBrush(QColor(210, 229, 234)));
            painter.drawPath(path);
        }
        pen.setWidth(1);
        painter.setPen(pen);
        if(!m_drop)
        painter.drawLine(event->rect().topLeft().x()+36, event->rect().topLeft().y()-1,
                         event->rect().topRight().x(), event->rect().topRight().y()-1);
    }

    QRect rectIcon(rect());
    rectIcon.setWidth(12);
    rectIcon.setHeight(12);
    rectIcon.setX(16);
    rectIcon.setY(event->rect().y()+event->rect().height()/2-rectIcon.height()/2);

    painter.drawPixmap(rectIcon, m_action->icon().pixmap(rectIcon.width(), rectIcon.height()));

    QRect rectText(event->rect());
    rectText.setX(34);
    rectText.setWidth(width()-34);
    if(!m_editing)
    {
        painter.setPen(QColor(0, 0, 0, 128));
        painter.drawText(rectText, Qt::AlignLeft | Qt::AlignVCenter, m_action->text());

        if(m_action->isChecked())
            painter.setPen(QColor(0, 168, 225));

        if(!m_action->isChecked())
            painter.setPen(QColor(26, 25, 26));

        painter.drawText(rectText, Qt::AlignLeft | Qt::AlignVCenter, m_action->text());
    }
}

void AccordeonItem::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    if(rect().contains(event->pos()))
    {
        m_pressed = true;
    }
    update();
}

void AccordeonItem::mouseReleaseEvent(QMouseEvent *event)
{
    if(rect().contains(event->pos()) && m_pressed)
    {
        if(!m_editing)
        {
            m_action->trigger();
            emit clicked(this);
        }
        if(m_editing && !m_edit->rect().contains(event->pos()))
        {
            m_action->trigger();
            if(!m_edit->text().isEmpty())
                m_action->setText(m_edit->text());
            m_edit->hide();
            m_editing = false;
            emit clicked(this);
        }
    }

    m_pressed = false;
    update();
}

void AccordeonItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);
    if(!m_enableEdition)
    {
        m_pressed = true;
        m_action->trigger();
        emit clicked(this);
        update();
    }
    if(m_enableEdition)
    {
        if(m_edit->isVisible())
        {
            if(!m_edit->text().isEmpty())
                m_action->setText(m_edit->text());

            m_edit->hide();
            m_editing = false;
            m_pressed = true;
            update();
            return;
        }
        if(m_edit->isHidden())
        {
            m_edit->show();
            m_edit->setText(m_action->text());
            if(m_edit->text().isEmpty())
                m_edit->setText(m_textIfEmpty);
            m_edit->setFocus();
            m_edit->selectAll();
            m_editing = true;
            m_pressed = true;
            update();
            return;
        }
        emit clicked(this);
    }
    return;
}

void AccordeonItem::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_edit->setFixedWidth(event->size().width()-26-15);
}

QSize AccordeonItem::sizeHint() const
{
    QFontMetrics fm(font());
    return QSize(20, fm.width(m_action->text())+26);
}

void AccordeonItem::setCheckedAction(bool set)
{
    if(m_action->isChecked() == set)
        return;
    else
    {
        m_action->setChecked(set);
        if(m_editing)
        {
            if(!m_edit->text().isEmpty())
                m_action->setText(m_edit->text());
            m_edit->hide();
            m_editing = false;
            m_pressed = false;
            emit leaveEdition(this);
        }

        update();
    }
}
void AccordeonItem::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        if(m_editing)
        {
            if(m_action->text().isEmpty() && m_edit->text() != m_textIfEmpty)
                return;
            m_edit->hide();
            m_edit->setText(m_action->text());
            m_editing = false;
            update();
            emit leaveEdition(this);
            return;
        }
    }
    if(event->key() == Qt::Key_Return)
    {
        if(m_editing)
        {
            if(!m_edit->text().isEmpty())
                m_action->setText(m_edit->text());
            m_edit->hide();
            m_editing = false;
            emit leaveEdition(this);
            update();
            return;
        }
        if(!m_editing)
            edit();
    }
}

void AccordeonItem::edit()
{
    m_edit->show();
    m_edit->setText(m_action->text());
    if(m_edit->text().isEmpty())
        m_edit->setText(m_textIfEmpty);
    m_edit->setFocus();
    m_edit->selectAll();
    m_editing = true;
    m_pressed = true;
    update();

    emit editing(this);
    return;
}
void AccordeonItem::dragEnterEvent(QDragEnterEvent *event)
{
    if(event)
    {
        m_drop = true;
        update();
        event->acceptProposedAction();
    }
}

void AccordeonItem::dropEvent(QDropEvent *event)
{
    emit dropEvent(action());

    m_drop = false;
    event->acceptProposedAction();
    update();

}
void AccordeonItem::dragLeaveEvent(QDragLeaveEvent *event)
{
    Q_UNUSED(event);
    m_drop = false;
    update();
}
void AccordeonItem::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}
}} //NAMESPACE
