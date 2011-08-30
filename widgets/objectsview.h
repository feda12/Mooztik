#ifndef OBJECTSVIEW_H
#define OBJECTSVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include "objectdelegate.h"

namespace Mooztik{
namespace Gui{

class ObjectsView : public QListView
{
public:
    ObjectsView(QWidget *parent = 0);

private:
    void setModel(QAbstractItemModel *model);

    QStandardItemModel *_model;

private:
    void setItemsSize(const QSize &s);
};

} //Namespace Gui
} //Namespace Moztik

#endif // OBJECTSVIEW_H
