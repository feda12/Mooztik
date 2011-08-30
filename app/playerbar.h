#ifndef PLAYERBAR_H
#define PLAYERBAR_H

#include <QWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QPaintEvent>
#include "separator.h"

namespace Mooztik {
namespace Gui {

class PlayerBar : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerBar(QWidget *parent = 0);

private:
    void paintEvent(QPaintEvent *event);

private:
    QWidget *_volume;
    QWidget *_play, *_pause, *_stop;
    QWidget *_time;
    QWidget *_timeTotal;
    QWidget *_songPicker;

};

} //Namespace Gui
} //Namespace Mooztik

#endif // PLAYERBAR_H
