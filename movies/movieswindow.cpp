#include "movieswindow.h"

namespace Mooztik {
namespace Movies {

Window::Window(QWidget *parent) :
    QMainWindow(parent)
{
    setupGui();
}

void Window::setupGui()
{
    /*=========================================
       =========================================
                               SETUP LEFT NAVIGATION BAR
       =========================================
       ========================================= */
    _leftDockNavigation = new QDockWidget(this);
    _leftDockNavigation->setFixedWidth(160);
    _leftDockNavigation->setTitleBarWidget(new QWidget(0));
    _leftDockNavigation->setFeatures(QDockWidget::NoDockWidgetFeatures);

    _navigationLeftBar = new  Qopo::Gui::Accordeon(this);
    _leftDockNavigation->setWidget(_navigationLeftBar);

    this->addDockWidget(Qt::LeftDockWidgetArea, _leftDockNavigation);

    Qopo::Gui::AccordeonGroup *libraryGroup = new Qopo::Gui::AccordeonGroup(tr("Bibliothèque"));
    Qopo::Gui::AccordeonGroup *favoritesGroup = new Qopo::Gui::AccordeonGroup(tr("Coups de coeur"));
    Qopo::Gui::AccordeonGroup *toWatchGroup = new Qopo::Gui::AccordeonGroup(tr("À regarder"));
    Qopo::Gui::AccordeonGroup *actorsGroup = new Qopo::Gui::AccordeonGroup(tr("Acteurs"));
    Qopo::Gui::AccordeonGroup *directorsGroup = new Qopo::Gui::AccordeonGroup(tr("Réalisateurs"));
    Qopo::Gui::AccordeonGroup *genresGroup = new Qopo::Gui::AccordeonGroup(tr("Genres"));
    Qopo::Gui::AccordeonGroup *countriesGroup = new Qopo::Gui::AccordeonGroup(tr("Pays"));
    Qopo::Gui::AccordeonGroup *yearsGroup = new Qopo::Gui::AccordeonGroup(tr("Années"));
    Qopo::Gui::AccordeonGroup *tagsGroup = new Qopo::Gui::AccordeonGroup(tr("Tags"));
    Qopo::Gui::AccordeonGroup *sagasGroup = new Qopo::Gui::AccordeonGroup(tr("Sagas"));
    Qopo::Gui::AccordeonGroup *playlistsGroup = new Qopo::Gui::AccordeonGroup(tr("Playlists"));

    libraryGroup->setHeaderTriangleColor(Qt::transparent);
    favoritesGroup->setHeaderTriangleColor(Qt::transparent);
    toWatchGroup->setHeaderTriangleColor(Qt::transparent);

    _navigationLeftBar->addGroup(libraryGroup);
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(favoritesGroup);
    _navigationLeftBar->addGroup(toWatchGroup);
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(actorsGroup);
    _navigationLeftBar->addGroup(directorsGroup);
    _navigationLeftBar->addGroup(genresGroup);
    _navigationLeftBar->addGroup(countriesGroup);
    _navigationLeftBar->addGroup(yearsGroup);
    _navigationLeftBar->addGroup(tagsGroup);
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(sagasGroup);
    _navigationLeftBar->addGroup(playlistsGroup);
    _navigationLeftBar->addStrongSeparator();

    QObject::connect(libraryGroup, SIGNAL(headerClicked()), this, SLOT(goAllLibrary()));
    QObject::connect(favoritesGroup, SIGNAL(headerClicked()), this, SLOT(goFavorites()));
    QObject::connect(toWatchGroup, SIGNAL(headerClicked()), this, SLOT(goToWatch()));
    QObject::connect(actorsGroup, SIGNAL(headerClicked()), this, SLOT(goActors()));
    QObject::connect(directorsGroup, SIGNAL(headerClicked()), this, SLOT(goDirectors()));
    QObject::connect(genresGroup, SIGNAL(headerClicked()), this, SLOT(goGenres()));
    QObject::connect(countriesGroup, SIGNAL(headerClicked()), this, SLOT(goCountries()));
    QObject::connect(yearsGroup, SIGNAL(headerClicked()), this, SLOT(goYears()));
    QObject::connect(tagsGroup, SIGNAL(headerClicked()), this, SLOT(goTags()));
    QObject::connect(sagasGroup, SIGNAL(headerClicked()), this, SLOT(goSagas()));
    QObject::connect(playlistsGroup, SIGNAL(headerClicked()), this, SLOT(goPlaylists()));


    /*=========================================
       =========================================
                            SETUP SUBVIEWS DOCK & WIDGETS
       =========================================
       ========================================= */
    _actorsView = new Mooztik::Gui::ObjectsView(this);
    _directorsView = new Mooztik::Gui::ObjectsView(this);
    _genresView = new Mooztik::Gui::ObjectsView(this);
    _countriesView = new Mooztik::Gui::ObjectsView(this);
    _yearsView = new Mooztik::Gui::ObjectsView(this);
    _tagsView = new Mooztik::Gui::ObjectsView(this);
    _sagasView = new Mooztik::Gui::ObjectsView(this);
    _playlistsView = new Mooztik::Gui::ObjectsView(this);

    _subviewsStack = new QStackedWidget(this);
    _subviewsStack->setStyleSheet("background: qlineargradient(x1: 0, x2: 1, y1:0, y2:0,"
                                  "stop: 0 rgb(50, 50, 50), stop: 1 rgb(50, 50, 50)); border-right:"
                                  "1px solid rgb(211, 215, 224);");

    _subviewsStack->addWidget(_actorsView);
    _subviewsStack->addWidget(_directorsView);
    _subviewsStack->addWidget(_genresView);
    _subviewsStack->addWidget(_countriesView);
    _subviewsStack->addWidget(_yearsView);
    _subviewsStack->addWidget(_tagsView);
    _subviewsStack->addWidget(_sagasView);
    _subviewsStack->addWidget(_playlistsView);

    _searchSubView = new QxtLineEdit(this);
    _searchSubView->setAttribute(Qt::WA_MacShowFocusRect, false);
    _searchSubView->setSampleText(tr("Chercher..."));
    _searchSubView->setFixedHeight(30);
    _searchSubView->setStyleSheet("border:none; border-right: 1px solid rgb(211, 215, 224); border-left: 1px solid transparent;");

    QVBoxLayout *layoutSubViews = new QVBoxLayout;
    layoutSubViews->setSpacing(0);
    layoutSubViews->setMargin(0);
    layoutSubViews->addWidget(_searchSubView);
    layoutSubViews->addWidget(_subviewsStack);

    QWidget *widgetSubViews = new QWidget(this);
    widgetSubViews->setLayout(layoutSubViews);

    _subviewsDock = new QDockWidget(this);
    _subviewsDock->setMinimumWidth(200);
    _subviewsDock->setFixedWidth(200);
    _subviewsDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    _subviewsDock->setTitleBarWidget(new QWidget(0));
    _subviewsDock->setWidget(widgetSubViews);

    /*=========================================
       =========================================
                     SETUP CENTRAL VIEW AND MOVIES VIEWS
       =========================================
       ========================================= */

    QMainWindow *centralWindow = new QMainWindow;
    centralWindow->addDockWidget(Qt::LeftDockWidgetArea, _subviewsDock);
    setCentralWidget(centralWindow);

    _moviesViews = new QStackedWidget(this);
    centralWindow->setCentralWidget(_moviesViews);

    _gridView = new GridView(this);
    _tableView = new TableView(this);

    _moviesViews->addWidget(_gridView);
    _moviesViews->addWidget(_tableView);

   /*=========================================
      =========================================
                                    SETUP TOOLBAR TOP
      =========================================
      ========================================= */
    _searchArea = new Qopo::Gui::SearchLineWidget(this);

    Qopo::Gui::ToolBarActionGroup*groupLeft = new Qopo::Gui::ToolBarActionGroup(this);
    QObject::connect(groupLeft->addAction(QIcon(":/actions/open_left"), QIcon(":/actions/close_left")), SIGNAL(toggled(bool)),
                     this, SLOT(enableNavigationDock(bool)));
    Qopo::Gui::ToolBarActionGroup*groupRight = new Qopo::Gui::ToolBarActionGroup(this);
    groupRight->addAction(QIcon(":/actions/open_right"), QIcon(":/actions/close_right"));

    Qopo::Gui::ToolBarActionGroup *groupViews = new Qopo::Gui::ToolBarActionGroup(this);
    QObject::connect(groupViews->addAction(QIcon(":/actions/gridview"), QIcon(":/actions/gridview_checked")), SIGNAL(triggered()), this, SLOT(goGridView()));
    groupViews->addSeparator();
    QObject::connect(groupViews->addAction(QIcon(":/actions/tableview"), QIcon(":/actions/tableview_checked")), SIGNAL(triggered()), this, SLOT(goTableView()));

    _toolbarTop = new Qopo::Gui::ToolBar(this);
    _toolbarTop->addWidget(groupLeft, 1, Qt::AlignLeft);
    _toolbarTop->addSpacing(100);
    _toolbarTop->addWidget(groupViews, 1, Qt::AlignCenter);
    _toolbarTop->addSpacing(20);
    _toolbarTop->addWidget(_searchArea, 10, Qt::AlignCenter);
    _toolbarTop->addWidget(groupRight, 1, Qt::AlignRight);

}

Qopo::Gui::ToolBar *Window::toolBar() const
{
    return _toolbarTop;
}

void Window::enableNavigationDock(bool b)
{
    if(b)
        showNavigationDock();
    else if(!b)
        hideNavigationDock();
    return;
}

void Window::hideNavigationDock()
{
    _leftDockNavigation->hide();
    _subviewsDock->hide();
}

void Window::showNavigationDock()
{
    _leftDockNavigation->show();
    _subviewsDock->show();
}

void Window::hideSortViews()
{
    _subviewsDock->hide();
}

void Window::showSortViews()
{
    _subviewsDock->show();
}

void Window::goAllLibrary()
{
    hideSortViews();
    MoviePtrList ms;
    qx::dao::fetch_all(ms, &qx::QxSqlDatabase::getSingleton()->getDatabase());
    setMovies(ms);
}

void Window::goFavorites()
{
    hideSortViews();
    MoviePtrList ms;
    qx::dao::fetch_by_query(qx::QxSqlQuery("WHERE movie.favorite=\"true\""), ms, &qx::QxSqlDatabase::getSingleton()->getDatabase());
    setMovies(ms);
}

void Window::goToWatch()
{
    hideSortViews();
    MoviePtrList ms;
    qx::dao::fetch_by_query(qx::QxSqlQuery("WHERE movie.to_play=\"true\""), ms, &qx::QxSqlDatabase::getSingleton()->getDatabase());
    setMovies(ms);
}

void Window::goActors()
{
    showSortViews();
    _subviewsStack->setCurrentWidget(_actorsView);
}

void Window::goDirectors()
{
    showSortViews();
    _subviewsStack->setCurrentWidget(_directorsView);
}

void Window::goGenres()
{
    showSortViews();
    _subviewsStack->setCurrentWidget(_genresView);
}

void Window::goCountries()
{
    showSortViews();
    _subviewsStack->setCurrentWidget(_countriesView);
}

void Window::goYears()
{
    showSortViews();
    _subviewsStack->setCurrentWidget(_yearsView);
}

void Window::goTags()
{
    showSortViews();
    _subviewsStack->setCurrentWidget(_tagsView);
}

void Window::goSagas()
{
    showSortViews();
    _subviewsStack->setCurrentWidget(_sagasView);
}

void Window::goPlaylists()
{
    showSortViews();
        _subviewsStack->setCurrentWidget(_playlistsView);
}

void Window::goTableView()
{
    _moviesViews->setCurrentWidget(_tableView);
}

void Window::goGridView()
{
    _moviesViews->setCurrentWidget(_gridView);
}

void Window::setMovies(const MoviePtrList &movies)
{
    _gridView->setMovies(movies);
    _tableView->setMovies(movies);
}

} //Namespace Movies
} //Namespace Mooztik
