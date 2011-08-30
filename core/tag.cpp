#include "precompiled.h"
#include "tag.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::tag, Mooztik_tag)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<tag> &t)
    {
        t.data(&tag::_value, "value");
    }
}
namespace Mooztik {
namespace Core {

tag::tag()
{
}

QString tag::value() const
{
    return _value;
}
void tag::setValue(const QString &value)
{
    _value = value;
}

} //Namespace Core
} //Namespace Mooztik
