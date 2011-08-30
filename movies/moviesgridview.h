#ifndef MOVIESGRIDVIEW_H
#define MOVIESGRIDVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QScrollBar>
#include "movie.h"
#include "moviedelegate.h"

namespace Mooztik {
namespace Movies {

class GridView : public QListView
{
    Q_OBJECT
public:
    explicit GridView(QWidget *parent = 0);

private:
    void setModel(QAbstractItemModel *model);

    QStandardItemModel *_model;

public slots:
    void setItemsSize(const QSize &s);

    void addMovie(const MoviePtr &movie);
    void addMovies(const MoviePtrList &movies);
    void setMovies(const MoviePtrList &movies);

    void removeMovie(const QModelIndex &index);

    MoviePtr getMovieAt(const QModelIndex &index) const;
    MoviePtrList currentMovies() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void playClicked(const QModelIndex &index);

private:
    bool isHoveringPlayIcon(QMouseEvent *event) const;
    bool m_pressHovered;

};

} //Namespace Movies
} //Namespace Mooztik


#endif // MOVIESGRIDVIEW_H
