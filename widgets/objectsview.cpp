#include "objectsview.h"

namespace Mooztik {
namespace Gui {

ObjectsView::ObjectsView(QWidget *parent):
    QListView(parent)
{
    _model = new QStandardItemModel(this);
    setModel(_model);
    setItemDelegate(new ObjectDelegate(this));
    setAttribute(Qt::WA_MacShowFocusRect, false);
    setStyleSheet("border:none");
}

void ObjectsView::setModel(QAbstractItemModel *model)
{
    QListView::setModel(model);
}

void ObjectsView::setItemsSize(const QSize &s)
{
    if(model()){
        this->model()->setProperty("item_width", QVariant::fromValue(s.width()));
        this->model()->setProperty("item_height", QVariant::fromValue(s.height()));
    }

    this->setGridSize(QSize(s.width()+5, s.height()+5));
    this->setMinimumSize(QSize(gridSize().width()+20, gridSize().height()+10));
}
} //Namespace Mooztik
} //Namespace Gui
