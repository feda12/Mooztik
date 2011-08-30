/**
 * \file vidéo.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 15 juillet 2011
 *
 */

#ifndef VIDEO_H
#define VIDEO_H

#include <QString>
#include <QUrl>
#include <QTime>
#include "playableobject.h"

namespace Mooztik {
namespace Core {
/*! \class Video
 * \brief Class représentant une vidéo
 *
 * La classe gère les différents attributs qui la compose ainsi que ses associations avec d'autres classes.
 * Les attributs qui la compose sont les suivants:
 *
 * Les principales méthodes à retenir afin d'utiliser l'objet sont save() qui permets de sauvegarder l'objet,
 * remove() qui le supprime et foreignKey() qui retourne l'id attribué dans la base de données lorsqu'il y'en a un.
 */
class video : public Object
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::video)
public:
        typedef qx::dao::ptr<Mooztik::Core::video> VideoPtr;
        typedef QList<VideoPtr> VideoPtrList;
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Video
         *
         */
    video();

public:
    /**
     * \fn QString name() const;
     * \brief
     *
     * \return Retourne le nom de la vidéo
     */
    QString name() const;
    /**
     * \fn void setName(const QString &name)
     * \brief Change le nom de la vidéo
     *
     */
    void setName(const QString &name);

    /**
     * \fn QUrl path() const
     * \brief
     *
     * \return Retourne l'emplacement du fichier vidéo
     */
    QUrl path() const;
    /**
     * \fn void setPath(const QUrl &path)
     * \brief Change l'emplacement du fichier vidéo
     *
     */
    void setPath(const QUrl &path);

    /**
     * \fn QTime timelapse() const;
     * \brief
     *
     * \return Retourne la durée du fichier vidéo
     */
    QTime timelapse() const;
    /**
     * \fn void setTimelapse(const QTime &timelapse)
     * \brief Change la durée du fichier vidéo
     *
     */
    void setTimelapse(const QTime &timelapse);

private:
    QString _name;
    QString _urlFrom;
    QUrl _path;
    QTime _timelapse;

};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(video, Object, 0, Mooztik_video)

typedef qx::dao::ptr<Mooztik::Core::video> VideoPtr;
typedef QList<VideoPtr> VideoPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::video);
Q_DECLARE_METATYPE(Mooztik::Core::video*);
Q_DECLARE_METATYPE(VideoPtr);

#endif // VIDEO_H
