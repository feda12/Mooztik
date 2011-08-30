#include "musicwindow.h"
 
namespace Mooztik{
namespace Music{

Window::Window(QWidget *parent) :
    QMainWindow(parent)
 { 
    setupGui();
 } 
 
void Window::setupGui(){
    /* Setting up left navigation bar */
    QDockWidget *leftDock = new QDockWidget(this);
    leftDock->setFixedWidth(160);
    leftDock->setTitleBarWidget(new QWidget(0));
    leftDock->setFeatures(QDockWidget::NoDockWidgetFeatures);

    _navigationLeftBar = new  Qopo::Gui::Accordeon(this);
    leftDock->setWidget(_navigationLeftBar);

    this->addDockWidget(Qt::LeftDockWidgetArea, leftDock);

    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Bibliothèque")));
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Coups de coeur")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Non écoutées")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("À découvrir")));
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Artistes")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Albums")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Genres")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Compositeurs")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Années")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Tags")));
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Playlists")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Radios")));
    _navigationLeftBar->addStrongSeparator();

    //Temporary

}
} //Namespace Mooztik
} //Namespace Music
