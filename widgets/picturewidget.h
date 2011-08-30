/*#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QPainter>
#include <QResizeEvent>
#include <QLabel>
#include <QRect>
#include "photo.h"

namespace Qopo{
namespace Gui{
namespace Widgets{

class PictureWidget:public QWidget
{
    Q_OBJECT
public:
    PictureWidget(QWidget *parent = 0);

    void setImage(const QImage & image);
    QImage image();

    void setPhoto(PhotoPtr photo);
    PhotoPtr photo() const;

    void paintEvent(QPaintEvent * event);
    void autoresize();

    void resizeEvent(QResizeEvent *event);

private:
    double m_zoom;
    QImage m_image;
    QRect m_rectImageZone;
    QLabel *m_label;
    PhotoPtr m_photo;
};

}}} //NAMESPACE

#endif // PICTUREWIDGET_H*/
