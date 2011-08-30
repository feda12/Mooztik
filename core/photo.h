/**
 * \file photo.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 19 juillet 2011
 *
 */
#ifndef PHOTO_H
#define PHOTO_H

#include <QString>
#include <QUrl>
#include <QSize>

#include "specializedobject.h"

namespace Mooztik {
namespace Core {
/*! \class photo
 * \brief Class représentant une photo
 * La Photo s'occupe de retourner les thumbnails en fonction de la taille souhaité.
 */
class photo : public SpecializedObject
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::photo)
public:
        typedef qx::dao::ptr<Mooztik::Core::photo> PhotoPtr;
        typedef QList<PhotoPtr> PhotoPtrList;
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Photo
         *
         */
    photo();

    /**
     * \fn QString name() const;
     * \return Retourne le nom de la photo
     */
    QString name() const;
    /**
     * \fn void setName(const QString &name)
     * \brief Change le nom de la photo
     *
     */
    void setName(const QString &name);

    /**
     * \fn QUrl originalPath() const;
     * \return Retourne l'emplacement de l'image
     */
    QUrl originalPath() const;
    /**
     * \fn void setOriginalPath(const QUrl &originalPath)
     * \brief Change l'emplacement de l'image
     *
     */
    void setOriginalPath(const QUrl &originalPath);

    /**
     * \fn QString editedPath() const;
     * \return Retourne l'emplacement de l'image édité
     */
    QUrl editedPath() const;
    /**
     * \fn void setEditedPath(const QUrl &editedPath)
     * \brief Change l'emplacement du fichier édité
     *
     */
    void setEditedPath(const QUrl &editedPath);
private:
    QString _name;
    QUrl _originalPath;
    QUrl _editedPath;
    QMap<QSize, QUrl> _thumbnailsPaths;
};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(photo, Object, 0, Mooztik_photo)

typedef qx::dao::ptr<Mooztik::Core::photo> PhotoPtr;
typedef QList<PhotoPtr> PhotoPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::photo);
Q_DECLARE_METATYPE(Mooztik::Core::photo*);
Q_DECLARE_METATYPE(PhotoPtr);

#endif // PHOTO_H
