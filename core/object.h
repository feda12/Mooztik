/**
 * \file object.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 15 juillet 2011
 *
 */
#ifndef OBJECT_H
#define OBJECT_H

#include "precompiled.h"

namespace Mooztik {
namespace Core {
/*! \class Object
 * \brief Class représentant un objet quelconque
 * Base de tous les objets.
 */
class Object
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::Object)
public:
        typedef qx::dao::ptr<Mooztik::Core::Object> ObjectPtr;
        typedef QList<ObjectPtr> ObjectPtrList;
    /*!
         *  \brief Constructeur
         *  Constructeur de la classe Object
         */
    Object();

    long id() const;
    void setId(long id);

    virtual QString objectName() { return "Object"; }
   private:
    long _id;
};

} //Namespace Core
} //Namespace Mooztik

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(Mooztik::Core::Object, qx::trait::no_base_class_defined, 0, Mooztik_Object)

typedef qx::dao::ptr<Mooztik::Core::Object> ObjectPtr;
typedef QList<ObjectPtr> ObjectPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::Object);
Q_DECLARE_METATYPE(Mooztik::Core::Object*);
Q_DECLARE_METATYPE(ObjectPtr);

#endif // OBJECT_H
