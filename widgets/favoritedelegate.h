#ifndef FAVORITEDELEGATE_H
#define FAVORITEDELEGATE_H

#include <QtGui>
#include <QStyledItemDelegate>
#include "starrating.h"
#include "stareditor.h"

namespace Mooztik {
namespace Gui {

class FavoriteDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit FavoriteDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

};

} //Namespace Mooztik
} //Namespace Gui

#endif // FAVORITEDELEGATE_H
