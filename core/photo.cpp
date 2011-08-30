#include "precompiled.h"
#include "photo.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::photo, Mooztik_photo)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<photo> &t)
    {

    }
}

namespace Mooztik {
namespace Core {

photo::photo()
{
}

QString photo::name() const
{
    return _name;
}
void photo::setName(const QString &name)
{
    _name = name;
}

QUrl photo::originalPath() const
{
    return _originalPath;
}
void photo::setOriginalPath(const QUrl &originalPath)
{
    _originalPath = originalPath;
}

QUrl photo::editedPath() const
{
    return _editedPath;
}
void photo::setEditedPath(const QUrl &editedPath)
{
    _editedPath = editedPath;
}

} //Namespace Core
} //Namespace Mooztik
