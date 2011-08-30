/**
 * \file tag.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 16 juillet 2011
 *
 */

#ifndef TAG_H
#define TAG_H

#include <QString>
#include "object.h"

namespace Mooztik {
namespace Core {

/*! \class Tag
 * \brief Class représentant un tag
 *
 * L'objet possède uniquement un attribut.
 *
 */
class tag : public Object
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::tag)
public:
        typedef qx::dao::ptr<Mooztik::Core::tag> TagPtr;
        typedef QList<TagPtr> TagPtrList;
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Tag
         *
         */
    tag();

public:
    /**
     * \fn QString value() const;
     * \brief
     *
     * \return Retourne la valeur contenue dans l'objet Tag
     */
    QString value() const;
    /**
     * \fn void setValue(const QString &value)
     * \brief Change la valeur contenue dans l'objet
     *
     */
    void setValue(const QString &value);

private:
    QString _value;
};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(tag, Object, 0, Mooztik_tag)

typedef qx::dao::ptr<Mooztik::Core::tag> TagPtr;
typedef QList<TagPtr> TagPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::tag);
Q_DECLARE_METATYPE(Mooztik::Core::tag*);
Q_DECLARE_METATYPE(TagPtr);

#endif // TAG_H
