#ifndef OBJECTDELEGATE_H
#define OBJECTDELEGATE_H

#include <QStyledItemDelegate>
#include "movie.h"
namespace Mooztik {
namespace Gui {

class ObjectDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ObjectDelegate(QObject *parent = 0);
};

} //Namespace Gui
} //Namespace Moztik

#endif // OBJECTDELEGATE_H
