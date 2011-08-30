#include "favoritedelegate.h"

namespace Mooztik {
namespace Gui {

FavoriteDelegate::FavoriteDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void FavoriteDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    bool favorite = true;
    if (qVariantCanConvert<bool>(index.data()))
        favorite = qVariantValue<bool>(index.data());

    bool isSelected = option.state & QStyle::State_Selected;
    if(isSelected)
        painter->fillRect(option.rect, QColor(225, 236, 240));
    QIcon icon(":/icons/favorite");
    QRect rectFav(option.rect.x(), option.rect.y()+2, option.rect.width(), option.rect.height()-4);
    if(favorite)
        icon.paint(painter, rectFav, Qt::AlignCenter);
}

} //Namespace Mooztik
} //Namespace Gui
