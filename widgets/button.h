#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QIcon>

namespace Qopo{
namespace Gui{

class Button : public QWidget
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0);

    void setText(const QString &text);
    QString text() const;

    void setIcon(const QIcon &icon);
    QIcon icon() const;

    void setCheckable(bool set);
    bool isCheckable() const;

    void setChecked(bool set);
    bool isChecked() const;

    void setCheckedText(const QString &text);
    QString checkedText() const;

    void setCheckedIcon(const QIcon &icon);
    QIcon checkedIcon() const;

    void setBorderRadius(qreal rad);

    void setTopLeftRadius(qreal rad);
    void setTopRightRadius(qreal rad);
    void setBottomLeftRadius(qreal rad);
    void setBottomRightRadius(qreal rad);

    qreal topLeftRadius() const;
    qreal topRightRadius() const;
    qreal bottomLeftRadius() const;
    qreal bottomRightRadius() const;

    void setPressedGradient(QLinearGradient set);
    void setGradient(QLinearGradient set);
    void setTextColor(QColor set);
    void setBorderColor(QColor set);

    QSize minimumSizeHint() const;

signals:
    void clicked();
    void checked(bool d);

protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    class Private;
    Private *d;
};

}} //NAMESPACE

#endif // BUTTON_H
