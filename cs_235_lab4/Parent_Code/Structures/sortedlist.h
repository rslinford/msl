/*! \file sortedlist.h
 * \brief Header file for class container::SortedList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/sortedlist.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: sortedlist.h
 *   File creator:       slinford
 *   Created on:         March 30, 2009, 11:45 PM
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

#ifndef _SORTEDLIST_H
#define	_SORTEDLIST_H

#include "list.h"

namespace container {

/*!
 * \brief Abstract base class for all sorted lists
 *
 * Does not allow duplicate Entity objects.
 */
class SortedList: public virtual List {
public:

   const static Info * const TYPE_INFO;

protected:

   SortedList();
   SortedList(const SortedList& orig);

public:

   virtual ~SortedList();

   /*********************  SortedList Methods (public) *********************/

   /*!
    * \brief Insert an Entity into the List maintaining a sorted order
    *
    * The position of \a entity will be determined by the Entity class'
    * implementation of compareKeyTo(const Entity&). Duplicate keys will
    * be rejected, i.e., if Entity::compareKeyTo(const Entity&) returns 0
    * for any item in the SortedList the insertion will not take place.
    *
    * \return true if the Entity was added; otherwise false
    *
    * \pre The List is sorted and does not contain duplicate entries
    * \post The new Entity is in the list and #count is incremented
    * \post The List is sorted and does not contain duplicate entries
    * \post The cursor remains unchanged, pointing to the same, pre-existing
    * Entity or to the tail of the list
    */
   bool insertSorted(Entity* entity);

protected:

   /*********************  SortedList Methods (protected) *********************/

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in SortedList::insertSorted
    */
   virtual bool insertSorted_impl(Entity* entity) = 0;

private:

   /*********************  Container Methods (private - reduced visibility) *********************/

   /*!
    * \brief Hide from sub-classes
    */
   inline void setCount(int c) {
      Container::setCount(c);
   }

   /*!
    * \brief Hide from sub-classes
    */
   inline void incCount() {
      Container::incCount();
   }

   /*!
    * \brief Hide from sub-classes
    */
   inline void decCount() {
      Container::decCount();
   }

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const = 0;

};

} // namespace container
#endif	/* _SORTEDLIST_H */
