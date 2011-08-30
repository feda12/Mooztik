#include "moviedelegate.h"

namespace
{
int ITEM_WIDTH = 0;
int ITEM_HEIGHT = 0;
}

namespace Mooztik {
namespace Movies {

Delegate::Delegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    ITEM_HEIGHT = index.model()->property("item_height").toInt();
    ITEM_WIDTH = index.model()->property("item_width").toInt();

    if(ITEM_HEIGHT == 0 || ITEM_WIDTH == 0){
        ITEM_WIDTH = 200;
        ITEM_HEIGHT = 200;
    }

    if(!qVariantCanConvert<MoviePtr>(index.data()))
        return;

    MoviePtr movie = index.data().value<MoviePtr>();

    if(!movie)
        return;

    QPixmap pixmap("/Users/Blecam/Developpement/Fourre-tout/Mooztik/ressources/nopreview/no-preview-movie.jpg");
    /*QPixmap pixmap(movie->poster()->pathThumbnail());

    if(!QPixmapCache::find(movie->poster()->pathThumbnail(), &pixmap)){
        QPixmapCache::insert(movie->poster()->pathThumbnail(), pixmap);
    }*/

    const bool isSelected = option.state & QStyle::State_Selected;
    const bool isHovered = option.state & QStyle::State_MouseOver;
    const bool playSelected = index.model()->property("play_clicked").toBool();

    QRect rect(0, 10, ITEM_WIDTH, ITEM_HEIGHT);
    rect.setWidth(option.rect.width()-10);

    painter->setRenderHint(QPainter::Antialiasing);

    painter->save();
    painter->translate(option.rect.topLeft());
    QRect posterRect(10, 10, ITEM_WIDTH-20, ITEM_HEIGHT-70);
    painter->drawPixmap(posterRect, pixmap);
    QRectF selectionRect(9, 9, posterRect.width()+2, posterRect.height()+2);
    QPen penBorder;
    penBorder.setWidth(7);
    penBorder.setColor(Qt::white);
    painter->setPen(penBorder);
    painter->drawRoundedRect(selectionRect, 10, 10);
    if(isSelected)
    {
        penBorder.setWidth(4);
        penBorder.setColor(QColor(38, 161, 241));
        painter->setPen(penBorder);
        painter->drawRoundedRect(posterRect, 10, 10);
    }
    painter->restore();

    painter->save();
    QFont fontText(painter->font());
    fontText.setFamily("Helvetia");
    fontText.setBold(true);
    painter->setFont(fontText);
    painter->translate(option.rect.topLeft());
    QString movie_title = movie->title();
    QFontMetrics fm(painter->font());
    if(movie_title.size() > 28)
    {

        movie_title.truncate(25);
        movie_title += "..." ;
    }
    painter->setPen(Qt::black);
    QRect textRect(0, rect.height()-60, option.rect.width(), 30);
    painter->drawText(textRect, Qt::AlignCenter, movie_title);
    painter->restore();

    painter->save();
    painter->translate(option.rect.topLeft());
    QRect ratingRect(0, rect.height()-35, option.rect.width(), 15);
    //painter->fillRect(ratingRect, QColor(0, 0, 0, 230));
    if(movie->rating() > 0)
    {
        QIcon iconRating(":/icons/rating"+QString::number(movie->rating()));
        iconRating.paint(painter, ratingRect, Qt::AlignCenter);
    }
    painter->restore();

    if(movie->isFavorite())
    {
        painter->save();
        painter->translate(option.rect.topLeft());
        QRect rectFav;
        rectFav = QRect(pixmap.rect().topLeft().x()+5, pixmap.rect().topLeft().y()+5, 20, 20);
        QIcon iconFav(":/icons/favorite");
        iconFav.paint(painter, rectFav, Qt::AlignCenter);
        painter->restore();
    }

    if(isHovered)
    {

        if(playSelected)
        {

        }
    }
}

QSize Delegate::sizeHint (const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    return QSize(ITEM_WIDTH, ITEM_HEIGHT);
}

} //Namespace Movies
} //Namespace Mooztik
