#include "playerbar.h"

namespace Mooztik {
namespace Gui {

PlayerBar::PlayerBar(QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(45);
    _volume = new QWidget(this);
    _volume->setMinimumWidth(160);
    _volume->setMaximumWidth(175);
    _play = new QWidget(this);
    _play->setFixedWidth(30);
    _pause = new QWidget(this);
    _pause->setFixedWidth(30);
    _stop = new QWidget(this);
    _stop->setFixedWidth(30);
    _time = new QWidget(this);
    _timeTotal = new QWidget(this);
    _songPicker = new QWidget(this);
    _songPicker->setMinimumWidth(300);

    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->setMargin(0);
    layoutMain->setSpacing(0);
    layoutMain->addWidget(_volume);
    layoutMain->addWidget(new Qopo::Gui::Separator(this));
    layoutMain->addWidget(_play);
    layoutMain->addWidget(_pause);
    layoutMain->addWidget(_stop);
    layoutMain->addWidget(_time);
    layoutMain->addWidget(_songPicker);
    layoutMain->addWidget(_timeTotal);
    if(layout())
    {
        delete layout();
    }
    setLayout(layoutMain);
}

void PlayerBar::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QLinearGradient gradient(QPoint(0, 0), QPoint(0, height()));
    gradient.setColorAt(0, QColor(238, 238, 238));
    gradient.setColorAt(1, QColor(238, 238, 238));
    p.fillRect(event->rect(), QBrush(gradient));

    p.translate(event->rect().topLeft());
    p.setPen(Qt::black);
    p.drawLine(event->rect().topLeft(), event->rect().topRight());
}

} //Namespace Gui
} //Namespace Mooztik
