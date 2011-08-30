/**
 * \file specializedobject.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 16 juillet 2011
 *
 */

#ifndef SPECIALIZEDOBJECT_H
#define SPECIALIZEDOBJECT_H

#include "object.h"

namespace Mooztik {
namespace Core {
/*! \class SpecializedObject
 * \brief Class représentant un objet qui peut-être spécialisé à un autre objet
 *
 * Si l'objet est spécialisé, alors le premier objet qui l'initialise sera le seul porteur de l'objet.
 * (Il ne sera pas chargé par la librairie si il est spécialisé).
 *
 */
class SpecializedObject : public Object
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::SpecializedObject)
public:
        typedef qx::dao::ptr<Mooztik::Core::SpecializedObject> SpecializedObjectPtr;
        typedef QList<SpecializedObjectPtr> SpecializedObjectPtrList;
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe SpecializedObject
         *
         */
    SpecializedObject();

public:
    /**
     * \fn bool specialized() const;
     * \brief
     *
     * \return Retourne si l'objet est spécialisé
     */
    bool specialized() const;
    /**
     * \fn void setSpecialized(bool specialized)
     * \brief Spécialise l'objet en fonction du paramètre donné.
     *
     */
    void setSpecialized(bool specialized);

private:
    bool _specialized;
};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(SpecializedObject, Object, 0, Mooztik_SpecializedObject)

typedef qx::dao::ptr<Mooztik::Core::SpecializedObject> SpecializedObjectPtr;
typedef QList<SpecializedObjectPtr> SpecializedObjectPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::SpecializedObject);
Q_DECLARE_METATYPE(Mooztik::Core::SpecializedObject*);
Q_DECLARE_METATYPE(SpecializedObjectPtr);

#endif // OBJECT_H
