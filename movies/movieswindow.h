#ifndef MOVIESWINDOW_H
#define MOVIESWINDOW_H

#include <QMainWindow>
#include <QxtLineEdit>
#include "accordeon/accordeon.h"
#include "toolbar/toolbar.h"
#include "userprofilewidget.h"
#include "objectsview.h"
#include "accordeon/accordeongroup.h"
#include "toolbar/toolbaractiongroup.h"
#include "toolbar/toolbaractiongrouponlyclickable.h"
#include "searchlinewidget.h"
#include "moviestableview.h"
#include "moviesgridview.h"

namespace Mooztik {
namespace Movies {

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

    Qopo::Gui::ToolBar *toolBar() const;
private:
    void setupGui();

private: /* Attributs */
    QDockWidget *_leftDockNavigation;
    Qopo::Gui::Accordeon *_navigationLeftBar;

    Qopo::Gui::SearchLineWidget *_searchArea;
    Qopo::Gui::ToolBar *_toolbarTop;

    Mooztik::Gui::ObjectsView *_actorsView;
    Mooztik::Gui::ObjectsView *_directorsView;
    Mooztik::Gui::ObjectsView *_genresView;
    Mooztik::Gui::ObjectsView *_countriesView;
    Mooztik::Gui::ObjectsView *_yearsView;
    Mooztik::Gui::ObjectsView *_tagsView;
    Mooztik::Gui::ObjectsView *_sagasView;
    Mooztik::Gui::ObjectsView *_playlistsView;

    QDockWidget *_subviewsDock;
    QStackedWidget *_subviewsStack;
    QxtLineEdit *_searchSubView;


    QStackedWidget *_moviesViews;
    TableView *_tableView;
    GridView *_gridView;

private slots:
    void enableNavigationDock(bool b);

    void hideNavigationDock();
    void showNavigationDock();

    void hideSortViews();
    void showSortViews();

    void goAllLibrary();

    void goFavorites();
    void goToWatch();

    void goActors();
    void goDirectors();
    void goGenres();
    void goCountries();
    void goYears();
    void goTags();

    void goSagas();
    void goPlaylists();

    void goTableView();
    void goGridView();

    void setMovies(const MoviePtrList &movies);

};

} //Namespace Movies
} //Namespace Mooztik

#endif // MOVIESWINDOW_H
