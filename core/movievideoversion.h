#ifndef MOVIEVIDEOVERSION_H
#define MOVIEVIDEOVERSION_H

#include "playableobject.h"

namespace Mooztik {
namespace Core {

class movie;
class MovieVideoVersion : public PlayableObject
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::MovieVideoVersion)
    public:
        typedef qx::dao::ptr<Mooztik::Core::MovieVideoVersion> MovieVideoVersionPtr;
        typedef QList<MovieVideoVersionPtr> MovieVideoVersionPtrList;
    typedef qx::dao::ptr<Mooztik::Core::movie> MoviePtr;
public:
    MovieVideoVersion();

private:
    MoviePtr _movie;
};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(MovieVideoVersion, PlayableObject, 0, Mooztik_MovieVideoVersion)

typedef qx::dao::ptr<Mooztik::Core::MovieVideoVersion> MovieVideoVersionPtr;
typedef QList<MovieVideoVersionPtr> MovieVideoVersionPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::MovieVideoVersion);
Q_DECLARE_METATYPE(Mooztik::Core::MovieVideoVersion*);
Q_DECLARE_METATYPE(MovieVideoVersionPtr);

#endif // MOVIEVIDEOVERSION_H
