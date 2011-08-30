#include "moviestableview.h"

#include <QSqlRecord>

namespace Mooztik {
namespace Movies {

TableView::TableView(QWidget *parent) :
    QTableView(parent)
{
    m_model = new QStandardItemModel(this);
    setModel(m_model);

    setMinimumWidth(750);

    m_model->setColumnCount(8);

    setShowGrid(false);
    setSortingEnabled(true);
    setAlternatingRowColors(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setContextMenuPolicy(Qt::CustomContextMenu);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    verticalHeader()->hide();
    setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    verticalScrollBar()->setPageStep(3);
    verticalScrollBar()->setSingleStep(1);
    setItemDelegateForColumn(0, new Mooztik::Gui::FavoriteDelegate(this));
    setItemDelegateForColumn(2, new StarDelegate(this));
    QStringList headers;
    headers <<QString() << tr("Titre") << tr("Durée") << tr("Classement") << tr("Réalisateur(s)") << tr("Année") << tr("Genre(s)") << tr("Acteur(s)");
    m_model->setHorizontalHeaderLabels(headers);

    setColumnWidth(0, 30);
    setColumnWidth(1, 200);
    setColumnWidth(2, 70);
    setColumnWidth(3, 120);
    setColumnWidth(4, 250);
    setColumnWidth(5, 70);
    setColumnWidth(6, 300);
    setColumnWidth(7, 400);

    verticalHeader()->setDefaultSectionSize(18);

    setStyleSheet("QTableView {"
                  "font-family: \"lucida\";"
                  "selection-background-color: rgb(225, 236, 240);"
                  "selection-color: rgb(0, 168, 225);"
                  ""
                  "color: rgb(78, 78, 78);"
                  "background-color: rgb(250, 250, 250);"
                  "border: none;"
                  "border-right: 1px solid rgb(211, 215, 224);"
                  "alternate-background-color: rgb(240, 240, 240);"
                  "gridline-color: rgb(240, 200, 200);}"

                  "QHeaderView::section{"
                  "background-color: qlineargradient(x1:0, x2:0, y1:0, y2:0, stop: 0 rgb(255, 255, 255), stop: 1 rgb(255, 255, 255));"
                  "color: rgb(69, 69, 69);"
                  "border:none;"
                  "border-right:1px dotted rgb(211, 215, 224);"
                  "border-bottom:1px solid rgb(211, 215, 224);"
                  "height:29px;"
                  "font: bold;}");

}

void TableView::setModel(QAbstractItemModel *model)
{
    QTableView::setModel(model);
}

void TableView::addMovie(const MoviePtr &movie)
{
    setSortingEnabled(false);

    QStandardItem *itemFavorite = new QStandardItem;
    QStandardItem *itemTitle = new QStandardItem(movie->title());
    QStandardItem *itemTimeLapse = new QStandardItem(movie->timelapse().toString("hh:mm"));
    QStandardItem *itemRating = new QStandardItem;
    QStandardItem *itemDirectors = new QStandardItem(/*Mooztik::Core::Person::toString(movie->directors())*/);
    QStandardItem *itemYear = new QStandardItem(movie->releaseDate().toString("yyyy"));
    QStandardItem *itemGenres = new QStandardItem(/*movie->genres().toString()*/);
    QStandardItem *itemActors = new QStandardItem(/*Mooztik::Core::Person::toString(movie->actors())*/);

    itemTitle->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    itemTimeLapse->setTextAlignment(Qt::AlignCenter);
    itemDirectors->setTextAlignment(Qt::AlignCenter);
    itemYear->setTextAlignment(Qt::AlignCenter);
    itemGenres->setTextAlignment(Qt::AlignCenter);
    itemActors->setTextAlignment(Qt::AlignCenter);

    itemTitle->setData(QVariant::fromValue(movie), Qt::UserRole);
    //itemRating->setData(StarRating(movie->rating()), Qt::DisplayRole);
    itemFavorite->setData(movie->isFavorite(), Qt::DisplayRole);

    QList<QStandardItem*> itemsList;
    itemsList << itemFavorite << itemTitle << itemTimeLapse << itemRating << itemDirectors << itemYear << itemGenres << itemActors;

    m_model->appendRow(itemsList);

    /*QxtStars *rating = new QxtStars(this);
    QPalette palette;
    palette.setColor(QPalette::Highlight, QColor(31, 31, 31));
    palette.setColor(QPalette::Text, QColor(0, 0, 0, 0));
    palette.setColor(QPalette::Base, QColor(Qt::transparent));
    rating->setPalette(palette);
    rating->setValue(movie->rating());
    rating->setRange(0,5);
    rating->setReadOnly(true);*/

    setSortingEnabled(true);
}

void TableView::addMovies(const MoviePtrList &movies)
{
    for(MoviePtrList::ConstIterator i = movies.begin(); i != movies.end(); i ++)
        addMovie(*i);
}

void TableView::setMovies(const MoviePtrList &movies)
{
    QList<int> col_widths;
    for(int i = 0; i < m_model->columnCount(); i ++)
        col_widths.push_back(columnWidth(i));
    setModel(NULL);
    m_model->removeRows(0, m_model->rowCount());
    addMovies(movies);
    setModel(m_model);
    for(int i = 0; i < m_model->columnCount(); i ++)
        setColumnWidth(i, col_widths.at(i));
}

void TableView::removeMovie(const QModelIndex &index)
{
    m_model->removeRow(index.row());
}

MoviePtr TableView::getMovieAt(const QModelIndex &index) const
{
    return  m_model->item(index.row(), 1)->data(Qt::UserRole).value<MoviePtr>();
}

MoviePtrList TableView::currentMovies() const
{
    MoviePtrList tmpMovies;

    QModelIndexList indexes = selectionModel()->selectedRows();
    for(QModelIndexList::ConstIterator i = indexes.begin(); i <indexes.end(); i++)
        tmpMovies.push_back(getMovieAt(*i));

    return tmpMovies;
}


} //Namespace Movies
} //Namespace Mooztik
