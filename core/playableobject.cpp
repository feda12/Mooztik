#include "precompiled.h"
#include "playableobject.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::PlayableObject, Mooztik_PlayableObject)

namespace qx {
    template <> void register_class(QxClass<Mooztik::Core::PlayableObject> &t)
    {
        t.data(&Mooztik::Core::PlayableObject::_rating , "rating");
        t.data(&Mooztik::Core::PlayableObject::_favorite , "favorite");
        t.data(&Mooztik::Core::PlayableObject::_comment , "comment");
        t.data(&Mooztik::Core::PlayableObject::_nbPlays , "nb_plays");
        t.data(&Mooztik::Core::PlayableObject::_toPlay , "to_play");
        t.data(&Mooztik::Core::PlayableObject::_timelapse, "timelapse");
    }

}


namespace Mooztik {
namespace Core {

PlayableObject::PlayableObject()
{
    _rating = 0;
    _favorite = false;
    _toPlay = false;
}

int PlayableObject::rating() const
{
    return _rating;
}
void PlayableObject::setRating(int rating)
{
    _rating = rating;
}

QString PlayableObject::comment() const
{
    return _comment;
}
void PlayableObject::setComment(const QString &comment)
{
    _comment = comment;
}

bool PlayableObject::toPlay() const
{
    return _toPlay;
}
void PlayableObject::setToPlay(bool toPlay)
{
    _toPlay = toPlay;
}

bool PlayableObject::played() const
{
    return _nbPlays > 0;
}

bool PlayableObject::isFavorite() const
{
    return _favorite;
}
void PlayableObject::setFavorite(bool isFavorite)
{
    _favorite = isFavorite;
}

int PlayableObject::nbPlays() const
{
    return _nbPlays;
}
void PlayableObject::setNbPlays(int nbPlays)
{
    _nbPlays = nbPlays;
}

QTime PlayableObject::timelapse() const
{
    return _timelapse;
}
void PlayableObject::setTimelapse(const QTime &timelapse)
{
    _timelapse = timelapse;
}

} //Namespace Core
} //Namespace Mooztik
