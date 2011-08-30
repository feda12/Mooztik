#include "movie.h"
#include "precompiled.h"
#include "movievideoversion.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::MovieVideoVersion, Mooztik_MovieVideoVersion)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<MovieVideoVersion> &t)
    {
        t.relationManyToOne(&MovieVideoVersion::_movie, "version_id");
    }
}

namespace Mooztik {
namespace Core {

MovieVideoVersion::MovieVideoVersion()
{
}

} //Namespace Core
} //Namespace Mooztik
