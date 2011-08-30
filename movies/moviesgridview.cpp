#include "moviesgridview.h"

namespace Mooztik {
namespace Movies {

GridView::GridView(QWidget *parent) :
    QListView(parent)
{
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setFlow(QListView::LeftToRight);
    setWrapping(true);
    setResizeMode(QListView::Adjust);
    setMovement(QListView::Static);
    setUniformItemSizes(true);
    //setDragEnabled(true);
    // setDragDropMode(QAbstractItemView::DragOnly);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setFrameShape( QFrame::NoFrame );
    setAttribute(Qt::WA_MacShowFocusRect, false);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setMouseTracking(true);
    verticalScrollBar()->setPageStep(3);
    verticalScrollBar()->setSingleStep(1);
    setSelectionRectVisible(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    QPalette p = palette();
    p.setBrush(QPalette::Base, Qt::white);
    p.setBrush(QPalette::Text, Qt::white);
    setPalette(p);

    this->setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);

    m_pressHovered = false;

    setItemDelegate(new Mooztik::Movies::Delegate(this));

    _model = new QStandardItemModel(this);
    _model->setProperty("showRating", true);
    setModel(_model);

    QObject::connect(_model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(dataChanged(QModelIndex,QModelIndex)));

    setItemsSize(QSize(170, 270));
    setSpacing(10);
}

void GridView::setModel(QAbstractItemModel *model)
{
    QListView::setModel(model);
}


void GridView::setItemsSize(const QSize &size)
{
    if(model()){
        this->model()->setProperty("item_width", QVariant::fromValue(size.width()));
        this->model()->setProperty("item_height", QVariant::fromValue(size.height()+10));
    }

    this->setGridSize(QSize(size.width()+10,size.height()));
    this->setMinimumSize(QSize(gridSize().width()+20, gridSize().height()+10));
}

void GridView::mousePressEvent(QMouseEvent *event)
{
    if(isHoveringPlayIcon(event))
    {
        m_pressHovered = true;
        model()->setProperty("play_clicked", QVariant::fromValue(true));
        update();
    }
    QListView::mousePressEvent(event);
}

void GridView::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_pressHovered && isHoveringPlayIcon(event))
        emit playClicked(indexAt(event->pos()));
    m_pressHovered = false;
    model()->setProperty("play_clicked", QVariant::fromValue(false));
    update();
    QListView::mouseReleaseEvent(event);
}

bool GridView::isHoveringPlayIcon(QMouseEvent *event) const
{
    const QModelIndex itemIndex = indexAt(event->pos());
    const QRect itemRect = visualRect(itemIndex);

    QRect rectPlay = QRect(itemRect.center().x()-10, itemRect.center().y()-10, 40, 40);

    return  rectPlay.contains(event->pos());
}

void GridView::addMovie(const MoviePtr &movie)
{
    if(!movie) return;
    QStandardItem *item = new QStandardItem;
    item->setData(QVariant::fromValue(movie),Qt::DisplayRole);
    _model->appendRow(item);
}

void GridView::addMovies(const MoviePtrList &movies)
{
    for(MoviePtrList::ConstIterator i = movies.begin(); i != movies.end(); i ++)
        addMovie(*i);
}

void GridView::setMovies(const MoviePtrList &movies)
{
    setModel(NULL);
    _model->clear();
    addMovies(movies);
    setModel(_model);
}

void GridView::removeMovie(const QModelIndex &index)
{
    _model->removeRow(index.row());
}

MoviePtr GridView::getMovieAt(const QModelIndex &index) const
{
    return _model->data(index).value<MoviePtr>();
}

MoviePtrList GridView::currentMovies() const
{
    MoviePtrList tmpMovies;
    QModelIndexList indexes = selectionModel()->selectedIndexes();
    for(QModelIndexList::ConstIterator i = indexes.begin(); i <indexes.end(); i++)
    {
        MoviePtr mov = getMovieAt(*i);
        tmpMovies.push_back(mov);
    }
    return tmpMovies;
}

} //Namespace Movies
} //Namespace Mooztik
