#include "moduleswindow.h"

namespace Mooztik {
namespace Gui {

ModulesWindow::ModulesWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupGui();
}

ModulesWindow::~ModulesWindow()
{

}

void ModulesWindow::setupGui()
{
    setWindowTitle(tr("Mooztik"));

    _tabsBar = new Qopo::Gui::BlackTabBar(this);
    _tabsBar->setFixedHeight(40);
    _userControl = new UserProfileWidget(this);

    AppLogo *appLogo = new AppLogo(this);
    appLogo->setFixedWidth(160);

    QHBoxLayout *layoutHeaderTop = new QHBoxLayout;
    layoutHeaderTop->setSpacing(0);
    layoutHeaderTop->setMargin(0);
    layoutHeaderTop->addWidget(appLogo);
    layoutHeaderTop->addWidget(_tabsBar);

    _toolbarsStack = new QStackedWidget(this);
    _toolbarsStack->setFixedHeight(35);
    QHBoxLayout *layoutHeaderBottom = new QHBoxLayout;
    layoutHeaderBottom->setSpacing(0);
    layoutHeaderBottom->setMargin(0);
    layoutHeaderBottom->addWidget(_userControl);
    layoutHeaderBottom->addWidget(_toolbarsStack);

    _tabsStack = new QStackedWidget(this);

    //_playerBar = new PlayerBar(this);

    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->setSpacing(0);
    layoutMain->setMargin(0);
    layoutMain->addLayout(layoutHeaderTop);
    layoutMain->addLayout(layoutHeaderBottom);
    layoutMain->addWidget(_tabsStack);
    //layoutMain->addWidget(_playerBar);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layoutMain);

    setCentralWidget(centralWidget);

    QObject::connect(_tabsBar, SIGNAL(currentChanged(int)), _tabsStack, SLOT(setCurrentIndex(int)));
    QObject::connect(_tabsBar, SIGNAL(currentChanged(int)), _toolbarsStack, SLOT(setCurrentIndex(int)));

    //QObject::connect(_userControl, SIGNAL(clicked()), this, SLOT(goUserWindow()));
    QObject::connect(_userControl, SIGNAL(disconnectionRequested()), this, SIGNAL(disconnectUser()));
}

void ModulesWindow::userLogin(UserPtr user)
{
    loadModules();
    _userControl->setUser(user);
}
void ModulesWindow::clearWindow()
{
    /* On ne laisse aucune trace de l'utilisateur précédent,
      on reinitalise donc tous les champs */
    setupGui();
    _userControl->setUser(UserPtr());

}

void ModulesWindow::loadModules()
{
    // reinitialize window
    setupGui();
    //load the modules
    _modulesList.clear();
    _modulesList.push_back(new Home::Module());
    _modulesList.push_back(new Movies::Module());
    _modulesList.push_back(new TvShows::Module());
    _modulesList.push_back(new Videos::Module());
    _modulesList.push_back(new Music::Module());
    _modulesList.push_back(new Photos::Module());
    _modulesList.push_back(new Web::Module());
    _modulesList.push_back(new Downloads::Module());
    foreach(Mooztik::Module *module, _modulesList)
    {
        _tabsBar->addTab(module->getIcon(), module->getName());
        _tabsStack->addWidget(module->getWindow());
        _toolbarsStack->addWidget(module->getToolBar());
    }
}

} //Namespace Gui
} //Namespace Mooztik
