/*! \file arraylist.h
 *  \brief Header file for for class container::ArrayList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/arraylist.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: arraylist.h
 * File creator:       slinford
 * Created on:         May 3, 2009, 3:04 PM
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

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "list.h"

using std::ostream;

namespace container {

/*!
 * \brief A mostly complete array-list implementation of List.
 *
 * Derived directly from List, ArrayList is an abstract class that implements
 * most of List using an array of Entity objects. The array grows as needed. 
 * Currently it does not contract. It never leaves gaps, i.e.,
 * all array elements less than Container::getCount() are populated.
 */
class ArrayList: public virtual List {
public:

   const static Info* const TYPE_INFO;

protected:

   const static int DEFAULT_INITIAL_CAPACITY;
   const static int DEFAULT_ADDITIONAL_CAPACITY;
   const static int BASE_INDEX;

   /*!
    * \brief The current capacity of this ArrayList. Reflects the current
    * number of elements allocated for #array
    */
   int capacity;

   /*!
    * \brief The number of elements that will be added to #capacity
    * when #array needs to grow
    */
   int additionalCapacity;

   /*!
    * \brief An array of pointers to Entity objects
    */
   Entity ** array;

   /*!
    * \brief An index that serves as the List cursor
    *
    * Points to the current Entity
    */
   int current;

   /*!
    * \brief Creates an empty list with the default #DEFAULT_INITIAL_CAPACITY
    *
    * When the current capacity is exceeded the underlying array will grow
    * by the #DEFAULT_ADDITIONAL_CAPACITY.
    */
   ArrayList();

   /*!
    * \brief Creates an empty list with the specified \a initialCapacity
    *
    * When the current capacity is exceeded the underlying array will grow
    * by the specified \a additionalCapacity.
    */
   ArrayList(int initialCapacity, int additionalCapacity);

   /*!
    * \brief Create a shallow copy of the \a pattern list
    *
    * A new underlying array of pointers will be allocated. The new array will
    * point to the existing Entity objects from \a pattern.
    *
    * \pre \a pattern is a valid ArrayList
    * \post \a this ArrayList is logically equivelent to \a pattern
    * \post \a this ArrayList and \a pattern will share the same Entity
    * instances.
    */
   ArrayList(const ArrayList& pattern);

   /*!
    * \brief Create a shallow or deep copy of the \a pattern list
    *
    * A new underlying array of pointers will be allocated. If \a deepCopy is
    * false the new array will point to the existing Entity objects
    * from \a pattern. If \a deepCopy is true then independent copies of
    * Entity will be created.
    *
    * \pre \a pattern is a valid ArrayList
    * \post \a this ArrayList is logically equivelent to \a pattern
    * \post If deepCopy was true then \this ArrayList is completely independent
    * from the \a pattern list
    */
   ArrayList(const ArrayList& pattern, bool deepCopy);

private:

   /*!
    * \brief Helper method; does actual work of the copy constructors
    */
   void copyConstructor(const ArrayList& pattern, bool deepCopy = false);

public:

   /*!
    * \brief Free all memory associated with this list
    *
    * Calls purgeContents(), so all Entity objects in the list will be deleted.
    */
   virtual ~ArrayList();

protected:

   /*********************  ArrayList Methods (protected) *********************/

   void allocateArray();

   /*!
    * \brief Close the gap at the list cursor by shifting Enity objects up in
    * the List
    */
   void closeGap();

   /*!
    * \brief Close the gap at \a index by shifting Enity objects up in
    * the List
    */
   void closeGap(int index);

   /*!
    * \brief Open a new gap at \a index by shifting Enity objects down in
    * the List
    */
   void openGap(int index);

   bool isAtCapacity() const;

public:

   /*********************  List Methods (public) *********************/

   virtual bool isFirst() const;

   virtual bool isLast() const;

   virtual bool isTail() const;

   virtual bool toFirst();

   virtual bool toLast();

   virtual void toTail();

   virtual bool toNext();

   virtual bool toPrev();

   virtual Entity * currentEntity();

   virtual void locateEntity(const Entity &key, int &index, Entity* &entity);

   virtual Entity* entityAt(int index);

protected:

   /*********************  List Methods (protected) *********************/

   virtual bool deleteCurrent_impl();

   virtual Entity * extractCurrentEntity_impl();

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const = 0;

};

} // namespace container
#endif /* _ARRAYLIST_H */
