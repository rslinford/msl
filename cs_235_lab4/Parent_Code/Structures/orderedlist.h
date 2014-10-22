/*! \file orderedlist.h
 *  \brief Header file for class container::OrderedList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/orderedlist.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: orderedlist.h
 *   File creator:       slinford
 *   Created on:         March 19, 2009, 9:59 PM
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

#ifndef _ORDEREDLIST_H
#define _ORDEREDLIST_H

#include "list.h"

using std::ostream;
using std::string;

namespace container {

/*!
 * \brief An ADT that represents a list of items
 * 
 * An OrderedList maintains an order but no sorting is performed or enforced.
 * It is left to the user of the class to order the list as desired with the
 * provided mutators.
 */
class OrderedList: public virtual List {
public:

   const static Info* const TYPE_INFO;

protected:

   OrderedList();
   OrderedList(const OrderedList& pattern);

public:

   virtual ~OrderedList();

   /*********************  OrderedList Methods (public) *********************/

   /*!
    * \brief Add an Entity to the end of the list
    *
    * No copy of the Entity is made; the list takes on the responsibility of
    * deleting the Entity. The list relinquishes the responsibility to
    * delete the Entity only if it is extracted from the list using
    * extractCurrentEntity().
    *
    * This method is a template function that enforces the correct value for
    * #count. Concrete sub-classes must implement append_impl(Entity*) to do the
    * work of adding an Entity.
    */
   void append(Entity* entity);

   /*!
    * \brief Inserts the new Entity relative to the list cursor
    * 
    * \post The new Entity is in the list located before the cursor
    * \post The cursor remains unchanged, pointing to the same, pre-existing
    * Entity  or to the tail of the list
    */
   void insertBefore(Entity* entity);

protected:

   /*********************  OrderedList Methods (protected) *********************/

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in OrderedList::append
    */
   virtual void append_impl(Entity* entity) = 0;

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in OrderedList::insertBefore
    */
   virtual void insertBefore_impl(Entity* entity) = 0;

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

   /*********************  Object Methods (public)  *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const = 0;
};

} // namespace container

#endif /* _ORDEREDLIST_H */
