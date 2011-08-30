#include "videoswindow.h"

namespace Mooztik{
namespace Videos{

Window::Window(QWidget *parent) :
    QMainWindow(parent)
{
    setupGui();
}

void Window::setupGui()
{
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
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("À regarder")));
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Origine")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Pays")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Années")));
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Tags")));
    _navigationLeftBar->addStrongSeparator();
    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Playlists")));
    _navigationLeftBar->addStrongSeparator();
}

} //Namespace Mooztik
} //Namespace Videos
