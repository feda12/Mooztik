#include "precompiled.h"
#include "object.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::Object, Mooztik_Object)

namespace qx {
    template <> void register_class(QxClass<Mooztik::Core::Object> &t)
    {
        t.setSoftDelete(qx::QxSoftDelete("deleted_at"));
        t.id(&Mooztik::Core::Object::_id, "id", 0);
    }
}

namespace Mooztik {
namespace Core {

Object::Object()
{
}

long Object::id() const
{
    return _id;
}

void Object::setId(long id)
{
    _id = id;
}

} //Namespace Core
} //Namespace Mooztik
