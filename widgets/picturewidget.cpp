/*#include "picturewidget.h"

namespace Qopo{
namespace Gui{
namespace Widgets{

PictureWidget::PictureWidget(QWidget *parent):QWidget(parent)
{
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    setContentsMargins(0,0,0,0);
}

void PictureWidget::setImage(const QImage & image)
{
    m_image = image;
    repaint();
}

void PictureWidget::setPhoto(PhotoPtr photo)
{
    if(!photo)
    {
        m_photo = PhotoPtr();
        m_image = QImage();
        repaint();
        return;
    }
    m_photo = photo;
    m_image = QImage(photo->pathOriginal());
    repaint();
}

QImage PictureWidget::image(void){
    return m_image;
}

PhotoPtr PictureWidget::photo() const
{
    return m_photo;
}

void PictureWidget::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QImage image = m_image.scaled(width(), height(), Qt::KeepAspectRatio);
    m_rectImageZone = QRect(((width() - image.width()) / 2), ((height() - image.height()) / 2), image.width(), image.height());
    painter.drawImage(m_rectImageZone.x(), m_rectImageZone.y(), image);

}
void PictureWidget::autoresize(void)
{
    resize(m_image.width(), m_image.height());
}

void PictureWidget::resizeEvent(QResizeEvent *event)
{
    event->accept();
}

}}} //NAMESPACE */
