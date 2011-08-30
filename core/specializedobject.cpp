#include "precompiled.h"
#include "specializedobject.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::SpecializedObject, Mooztik_SpecializedObject)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<SpecializedObject> &t)
    {
        t.data(&SpecializedObject::_specialized, "specialized");
    }
}

namespace Mooztik {
namespace Core {

SpecializedObject::SpecializedObject()
{
    _specialized = false;
}

void SpecializedObject::setSpecialized(bool specialized)
{
    _specialized = specialized;
}
bool SpecializedObject::specialized() const
{
    return _specialized;
}

} //Namespace Core
} //Namespace Mooztik
