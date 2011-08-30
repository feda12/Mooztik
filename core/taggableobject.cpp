#include "precompiled.h"
#include "taggableobject.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::TaggableObject, Mooztik_TaggableO)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<TaggableObject> &t)
    {

    }
}

namespace Mooztik {
namespace Core {

TaggableObject::TaggableObject()
{

}

} //Namespace Core
} //Namespace Mooztik
