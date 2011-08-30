#include "precompiled.h"
#include "person.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::person, Mooztik_person)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<person> &t)
    {
        t.data(&person::_firstName , "firstname");
        t.data(&person::_lastName , "lastname");
    }
}

namespace Mooztik {
namespace Core {

person::person()
{
}

QString person::firstName() const
{
    return _firstName;
}
void person::setFirstName(const QString &firstName)
{
    _firstName = firstName;
}

QString person::lastName() const
{
    return _lastName;
}
void person::setLastName(const QString &lastName)
{
    _lastName = lastName;
}
QString person::name() const
{
    return _firstName+" "+_lastName;
}
} //Namespace Core
} //Namespace Mooztik
