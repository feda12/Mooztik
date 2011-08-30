#include "webwindow.h"

namespace Mooztik{
namespace Web{

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

    _navigationLeftBar->addGroup(new Qopo::Gui::AccordeonGroup(tr("Streaming")));
    _navigationLeftBar->addStrongSeparator();
}

} //Namespace Mooztik
} //Namespace Web
