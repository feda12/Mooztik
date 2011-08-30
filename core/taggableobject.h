/**
 * \file taggableobject.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 16 juillet 2011
 *
 */

#ifndef TAGGABLEOBJECT_H
#define TAGGABLEOBJECT_H

#include <QList>
#include "object.h"

namespace Mooztik {
namespace Core {

/*! \class TaggableObject
 * \brief Objet pouvant posséder un ou plusieurs tags.
 *
 * L'ajout, suppression de tags est fourni uniquement par cette classe.
 *
 */
class TaggableObject : public Object
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::TaggableObject)
public:
        typedef qx::dao::ptr<Mooztik::Core::TaggableObject> TaggableObjectPtr;
        typedef QList<TaggableObjectPtr> TaggableObjectPtrList;
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe TaggableObject
         *
         */
    TaggableObject();

private:
};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(TaggableObject, Object, 0, Mooztik_TaggableO)

typedef qx::dao::ptr<Mooztik::Core::TaggableObject> TaggableObjectPtr;
typedef QList<TaggableObjectPtr> TaggableObjectPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::TaggableObject);
Q_DECLARE_METATYPE(Mooztik::Core::TaggableObject*);
Q_DECLARE_METATYPE(TaggableObjectPtr);

#endif // TAGGABLEOBJECT_H
