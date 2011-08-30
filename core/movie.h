/**
 * \file movie.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 15 juillet 2011
 *
 */
#ifndef MOVIE_H
#define MOVIE_H

#include <QString>
#include <QDate>
#include <QTime>

#include "playableobject.h"
#include "taggableobject.h"

namespace Mooztik {
namespace Core {
class MovieVideoVersion;
/*! \class Movie
 * \brief Class représentant un film
 *
 * La classe gère les différents attributs qui la compose ainsi que ses associations avec d'autres classes.
 * Les attributs qui la compose sont les suivants:
 *  - titre
 *  - titre original
 *  - date de sortie
 *  - classement
 *  - commentaire
 *  - synopsis
 *  - favori
 *  - regardé
 *  - à regarder
 *  - catégorisation du film(tout public, -10, -12, -16, etc ...)
 *  - listes de versions
 * Les principales méthodes à retenir afin d'utiliser l'objet sont save() qui permets de sauvegarder l'objet,
 * remove() qui le supprime et foreignKey() qui retourne l'id attribué dans la base de données lorsqu'il y'en a un.
 */
class movie : public PlayableObject, public TaggableObject
{
QX_REGISTER_FRIEND_CLASS(Mooztik::Core::movie)
public:
    typedef qx::dao::ptr<Mooztik::Core::movie> MoviePtr;
    typedef QList<MoviePtr> MoviePtrList;
    typedef qx::dao::ptr<Mooztik::Core::MovieVideoVersion> MovieVideoVersionPtr;
    typedef QList<MovieVideoVersionPtr> MovieVideoVersionPtrList;
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe movie
         *
         */
    movie();

    public:
    /**
     * \fn QString title() const;
     * \brief
     *
     * \return Retourne le titre du film
     */
    QString title() const;
    /**
     * \fn void setTitle(const QString &title)
     * \brief Change le titre du film
     *
     */
    void setTitle(const QString &title);

    /**
     * \fn QString titleOriginal() const;
     * \brief Méthode de la classe Film
     *
     * \return Retourne le titre original du film
     */
    QString titleOriginal() const;
    /**
     * \fn void setTitleOriginal(const QString &titleOriginal)
     * \brief Change le titre original du film
     *
     */
    void setTitleOriginal(const QString &titleOriginal);

    /**
     * \fn QDate releaseDate() const;
     * \brief Méthode de la classe Film
     *
     * \return Retourne la date de sortie du film
     */
    QDate releaseDate() const;
    /**
     * \fn void setReleaseDate(const QDate &releaseDate)
     * \brief Change la date de sortie du film
     *
     */
    void setReleaseDate(const QDate &releaseDate);

    /**
     * \fn QString overview() const;
     * \brief Méthode de la classe Film
     *
     * \return Retourne le synopsis du film
     */
    QString overview() const;
    /**
     * \fn void setOverview(const QString &overview)
     * \brief Change le synopsis du film
     *
     */
    void setOverview(const QString &overview);

    /**
     * \fn int motionPictureRating() const;
     * \brief Méthode de la classe Film
     *
     * \return Retourne le catégorisation attribué au film(peut varier selon les pays)
     */
    int motionPictureRating() const;
    /**
     * \fn void setMotionPictureRating(int motionPictureRating)
     * \brief Change la catégorisation du film
     *
     */
    void setMotionPictureRating(int motionPictureRating);

private:
    QString _title;
    QString _titleOriginal;
    QDate _releaseDate;
    QTime _timelapse;
    QString _overview;
    int _motionPictureRating;

    /* Relations */
    MovieVideoVersionPtrList *_versionsList;

};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(movie, PlayableObject, 0, Mooztik_movie)

typedef qx::dao::ptr<Mooztik::Core::movie> MoviePtr;
typedef QList<MoviePtr> MoviePtrList;

Q_DECLARE_METATYPE(Mooztik::Core::movie);
Q_DECLARE_METATYPE(Mooztik::Core::movie*);
Q_DECLARE_METATYPE(MoviePtr);

#endif // MOVIE_H
