/*! \file entity.h
 * \brief Header file for class container::Entity
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/entity.h $
 *  $Date: 2009-06-16 22:02:57 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 421 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: entity.h
 * File creator:       slinford
 * Created on:         March 22, 2009, 4:29 PM
 * </pre>
 * \section course Course Information
 * <pre>
 *   CS-217 Data Structures and Algorithms I
 *   Daniel Webster College - Nashua
 *   03/18/2009 - 05/05/2009
 *   Independent Study
 *
 * Instructor: Robert Schaefer
 *
 * Description:
 *
 *   Students will be responsible for the specification, design,
 *   implementation and practical demonstration of correctness of the
 *   abstract data type sets, functions, sequences, stacks, queues, and
 *   strings. Special emphasis will be given to searching and sorting
 *   algorithms. Other algorithms covered may include compression,
 *   encryption, hashing, and sorting, and sampling.
 *
 * Student:
 *
 *   R. Scott Linford
 * </pre>
 */

#ifndef _ENTITY_H
#define _ENTITY_H

#include "object.h"
#include <string>

using std::ostream;
using std::string;

namespace container {

/*!
 * \brief The base class of all items that can be stored in a Container.
 */
class Entity: public Object {
public:

   const static Info * const TYPE_INFO;

protected:

   const static int COMPARE_KEY_TO_NULL_RVAL;

private:

   static int nextDefaultKey;

   int defaultKey;
   mutable string* keyAsString;

public:

   Entity();

   /*!
    * \brief Constructor for creating an Entity with a specific \a key
    * 
    * \post Does not reference or change nextDefaultKey
    */
   Entity(int key);

   Entity(const Entity& pattern);
   virtual ~Entity();

   Entity & operator=(const Entity& second);

   /*********************  Entity Methods (public) *********************/

   /*!
    * \brief Compare \a this Entity with \a second
    *
    * Used to determine the sort order of a collection of Entity objects.
    * Sub-classes should override compareKeyTo to provide their own concept
    * of less-than, equal, and greater-than. This method is used by Container
    * classes to sort Entity objects and to determine whether two instances are
    * duplicates.
    *
    * \return An integer less than zero if: \a this < \a second
    * \return Zero if: \a this == \a second
    * \return An integer greater than zero if: \a this > \a second
    *
    * \pre \a second is the same type as \a this Entity
    * \post Neither Entity has changed state
    */
   virtual int compareKeyTo(const Entity& second) const;

   /*!
    * \brief Return an Entity object's key in a string representation
    *
    * The key itself may be of a single type or a combination of member
    * variables. For the sake of efficiency the string representation
    * will be generated lazily and stored for future reference. getKeyAsString
    * should not be overridden by sub-classes. This method calls the
    * protected member #generateKeyAsString to allow sub-classes of Entity
    * to control the string representation.
    */
   const string& getKeyAsString() const;

protected:

   /*********************  Entity Methods (protected) *********************/

   int getDefaultKey();

   void invalidateKeyAsString();

   virtual string* generateKeyAsString() const;

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const;

};

} // namespace container
#endif /* _ENTITY_H */
