#include "photoswindow.h"
 
namespace Mooztik{
namespace Photos{

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
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Photo du jour")));
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Albums")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Evènements")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Lieux")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Visages")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Photographes")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Dates")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Tags")));
    _navigationLeftBar->addStrongSeparator();
}
} //Namespace Mooztik
} //Namespace Photos
