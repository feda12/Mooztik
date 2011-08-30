#include "movievideoversion.h"
#include "precompiled.h"
#include "movie.h"

#include <QxMemLeak.h>

QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MOOZTIK(Mooztik::Core::movie, Mooztik_movie)

namespace qx {
    using namespace Mooztik::Core;
    template <> void register_class(QxClass<movie> &t)
    {

        t.data(&movie::_title , "title");
        t.data(&movie::_titleOriginal , "title_original");
        t.data(&movie::_releaseDate , "release_date");
        t.data(&movie::_timelapse , "time_lapse");
        t.data(&movie::_overview , "overview");
        t.data(&movie::_motionPictureRating , "motion_picture_rating");

        t.relationOneToMany(&movie::_versionsList, "list_movies_versions", "movie_id");
    }
}

namespace Mooztik {
namespace Core {

movie::movie()
{
    _motionPictureRating = 0;
}

QString movie::title() const
{
    return _title;
}
void movie::setTitle(const QString &title)
{
    _title = title;
}

QString movie::titleOriginal() const
{
    return _titleOriginal;
}
void movie::setTitleOriginal(const QString &titleOriginal)
{
    _titleOriginal = titleOriginal;
}

QDate movie::releaseDate() const
{
    return _releaseDate;
}
void movie::setReleaseDate(const QDate &releaseDate)
{
    _releaseDate = releaseDate;
}

QString movie::overview() const
{
    return _overview;
}
void movie::setOverview(const QString &overview)
{
    _overview = overview;
}

int movie::motionPictureRating() const
{
    return _motionPictureRating;
}
void movie::setMotionPictureRating(int motionPictureRating)
{
    _motionPictureRating = motionPictureRating;
}

} //Namespace Core
} //Namespace Mooztik
