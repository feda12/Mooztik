#include "homewindow.h"
 
namespace Mooztik{
namespace Home{

Window::Window(QWidget *parent) :
    QMainWindow(parent)
 { 
    QLabel *label = new QLabel(this);
    label->setStyleSheet("color: rgb(119, 130, 143);  ");
    label->setOpenExternalLinks(true);
    label->setText(tr("<span style=\"font-size: 30px;\">Bienvenue dans Mooztik !</span> <br />"
                      "Pour plus d'infos, "
                      "n'hésitez pas à aller consulter les sites suivants: <br />"
                      "<a href=\"http://www.mooztik.com\">Site officiel</a><br />"
                      "<a href=\"http://www.siteduzero.com/forum-83-"
                      "499604-p1-logiciel-mooztik.html\">Site du zéro</a><br />"
                      "<a href=\"http://www.zprojets.fr/projets-48-228-mooztik.html\">zProjets</a><br />"
                      "<a href=\"https://github.com/feda12/Mooztik\">GitHub</a>"));
    label->setAlignment(Qt::AlignCenter);
    this->setCentralWidget(label);
 } 
 
void Window::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(event->rect(), Qt::white);
}
} //Namespace Mooztik
} //Namespace Home
