#ifndef MOVIESTABLEVIEW_H
#define MOVIESTABLEVIEW_H

#include <QTableView>
#include <QStandardItemModel>
#include <QxtHeaderView>
#include <QScrollBar>

#include "stardelegate.h"
#include "favoritedelegate.h"

#include "person.h"
#include "movie.h"

namespace Mooztik {
namespace Movies {

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);

private:
    void setModel(QAbstractItemModel *model);
    void setupModel();
    void setupTable();

    QStandardItemModel *m_model;

public slots:
    void addMovie(const MoviePtr &movie);
    void addMovies(const MoviePtrList &movies);
    void setMovies(const MoviePtrList &movies);

    void removeMovie(const QModelIndex &index);

    MoviePtr getMovieAt(const QModelIndex &index) const;
    MoviePtrList currentMovies() const;

};

} //Namespace Movies
} //Namespace Mooztik

#endif // MOVIESTABLEVIEW_H
