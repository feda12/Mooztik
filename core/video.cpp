#include "precompiled.h"
#include "video.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::video, Mooztik_video)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<video> &t)
    {
    }
}

namespace Mooztik {
namespace Core {

video::video()
{
}

QString video::name() const
{
    return _name;
}
void video::setName(const QString &name)
{
    _name = name;
}


QUrl video::path() const
{
    return _path;
}
void video::setPath(const QUrl &path)
{
    _path = path;
}

QTime video::timelapse() const
{
    return _timelapse;
}
void video::setTimelapse(const QTime &timelapse)
{
    _timelapse = timelapse;
}

} //Namespace Core
} //Namespace Mooztik
