#ifndef MOVIEDELEGATE_H
#define MOVIEDELEGATE_H

#include <QStyledItemDelegate>
#include <QtGui>
#include "movie.h"
namespace Mooztik {
namespace Movies {

class Delegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint (const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    void paintThumbmail(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index, const QPixmap &pixmap, bool paintBorder = false) const;
    void paintTextAndRating(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index,const QRect &textBox, const QString &text, const int& rating) const;
    void paintActions(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

} //Namespace Movies
} //Namespace Mooztik

#endif // MOVIEDELEGATE_H
