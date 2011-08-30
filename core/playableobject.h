/**
 * \file playableobject.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 16 juillet 2011
 *
 */
#ifndef PLAYABLEOBJECT_H
#define PLAYABLEOBJECT_H

#include <QString>

#include "object.h"

namespace Mooztik {
namespace Core {
/*! \class PlayableObject
 * \brief Class représentant un objet qui peut-être joué.
 *
 * Il comporte les attributs classement, commentaire, à jouer, joué et favori.
 *
 */
class PlayableObject : public Object
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::PlayableObject)
public:
        typedef qx::dao::ptr<Mooztik::Core::PlayableObject> PlayableObjectPtr;
        typedef QList<PlayableObjectPtr> PlayableObjectPtrList;
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe PlayableObject
         *
         */
    PlayableObject();


    /**
     * \fn int rating() const;
     * \brief Méthode de la classe PlayableObject
     *
     * \return Retourne la note attribuée à l'objet
     */
    int rating() const;
    /**
     * \fn void setRating(int rating)
     * \brief Change la note attribuée à l'objet
     *
     */
    void setRating(int rating);

    /**
     * \fn QString comment() const;
     * \brief Méthode de la classe PlayableObject
     *
     * \return Retourne le commentaire donné à l'objet
     */
    QString comment() const;
    /**
     * \fn void setComment(const QString &comment)
     * \brief Change le commentaire attribué à l'objet
     *
     */
    void setComment(const QString &comment);

    /**
     * \fn bool toPlay() const;
     * \brief Méthode de la classe PlayableObject
     *
     * \return Retourne si oui ou non le film a été ajouté à la list des objets à jouer
     */
    bool toPlay() const;
    /**
     * \fn void setToPlay(bool toPlay)
     * \brief Ajoute l'objet ou non à la liste des objets à jouer
     *
     */
    void setToPlay(bool toPlay);

    /**
     * \fn bool played() const;
     * \brief Méthode de la classe PlayableObject
     *
     * \return Retourne si oui ou non l'objet a été joué (indépendant de la méthode toPlay())
     */
    bool played() const;

    /**
     * \fn bool isFavorite() const;
     * \brief Méthode de la classe PlayableObject
     *
     * \return Retourne si oui ou non l'objet est favori
     */
    bool isFavorite() const;
    /**
     * \fn void setFavori(bool isFavorite)
     * \brief Attribut le statut de favori ou non donné en paramètre à l'objet
     *
     */
    void setFavorite(bool isFavorite);

    /**
     * \fn int nbPlays() const;
     * \brief Méthode de la classe PlayableObject
     *
     * \return Retourne le nombre de fois que l'objet a été joué
     */
    int nbPlays() const;
    /**
     * \fn void setNbPlays(int nbPlays)
     * \brief Attribut le nombre de fois joués
     *
     */
    void setNbPlays(int nbPlays);

    /**
     * \fn QTime timelapse() const;
     * \brief Méthode de la classe PlayableObject
     *
     * \return Retourne la durée de l'objet
     */
    QTime timelapse() const;
    /**
     * \fn void setTimelapse(const QTime &timelapse)
     * \brief Attribut la durée de l'objet
     *
     */
    void setTimelapse(const QTime &timelapse);
private:
    int _rating;
    QString _comment;
    bool _favorite;
    bool _toPlay;
    int _nbPlays;
    QTime _timelapse;
};

} //Namespace Core
} //Namespace Mooztik

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(Mooztik::Core::PlayableObject, Mooztik::Core::Object, 0, Mooztik_PlayableObject)

typedef qx::dao::ptr<Mooztik::Core::PlayableObject> PlayableObjectPtr;
typedef QList<PlayableObjectPtr> PlayableObjectPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::PlayableObject);
Q_DECLARE_METATYPE(Mooztik::Core::PlayableObject*);
Q_DECLARE_METATYPE(PlayableObjectPtr);

#endif // PLAYABLEOBJECT_H
