/**
 * \file person.h
 * \brief Classe de sauvegarde
 * \author Benjamin Le Cam
 * \version 0.1
 * \date 20 juillet 2011
 *
 */

#ifndef PERSON_H
#define PERSON_H

#include "object.h"

namespace Mooztik {
namespace Core {
/*! \class Person
 * \brief Class représentant une personne
 * Stocje l'identité d'une personne, actuellement seul le nom et prénom, mais prendra plus d'importances à l'avenir.
 */
class person : public Object
{
    QX_REGISTER_FRIEND_CLASS(Mooztik::Core::person)
public:
        typedef qx::dao::ptr<Mooztik::Core::person> PersonPtr;
        typedef QList<PersonPtr> PersonPtrList;
    /*!
         *  \brief Constructeur
         *  Constructeur de la classe Person
         */
    person();

    /**
     * \fn void setLastName(const QString &lastName)
     * \brief Change l'emplacement du fichier édité
     *
     */
    void setLastName(const QString &lastName);
    /**
     * \fn QString lastName() const;
     * \return Retourne le nom de famille de la personne
     */
    QString lastName() const;

    void setFirstName(const QString &firstName);
    /**
     * \fn QString firstName() const;
     * \return Retourne le prénom de la personne
     */
    QString firstName() const;

    /**
     * \fn bool played() const;
     * \return Retourne le prénom et le nom de famille séparé par un espace
     */
    QString name() const;

private:
    QString _lastName;
    QString _firstName;
};

} //Namespace Core
} //Namespace Mooztik

using namespace Mooztik::Core;
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MOOZTIK(person, Object, 0, Mooztik_person)

typedef qx::dao::ptr<Mooztik::Core::person> PersonPtr;
typedef QList<PersonPtr> PersonPtrList;

Q_DECLARE_METATYPE(Mooztik::Core::person);
Q_DECLARE_METATYPE(Mooztik::Core::person*);
Q_DECLARE_METATYPE(PersonPtr);


#endif // PERSON_H
