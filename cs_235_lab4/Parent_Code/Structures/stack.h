/*! \file stack.h
 *  \brief Header file for class container::Stack
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/stack.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: stack.h
 * File creator:       slinford
 * Created on:         June 14, 2009, 2:52 PM
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

#ifndef _STACK_H
#define	_STACK_H

#include "container.h"

using std::string;

namespace container {

/*!
 * \brief Abstract base class for all stack containers
 *
 * Allows duplicates. Is unbounded.
 */
class Stack: public Container {
public:

   const static Info * const TYPE_INFO;

protected:

   Stack();
   Stack(const Stack& orig);

public:

   virtual ~Stack();

   /*********************  Stack Methods (public) *********************/

   /*!
    * \brief Add an Entity onto the top of the Stack
    *
    * A template method that calls the #push_impl method of the the derived
    * class.
    *
    * \pre The specified \a entity pointer is not null
    * \post The specified \a entity is the top item on the Stack
    * \post The Container's #count is greater by one
    */
   void push(Entity* entity);

   /*!
    * \brief Remove the top Entity from the Stack and return a pointer to the
    * Entity
    *
    * A template method that calls the #pop_impl method of the the derived class.
    *
    * \return A pointer to the Entity that was removed from the top of the
    * stack
    *
    * \pre There is at least one item in the Stack
    * \post The Entity (formerly the top item) is not in the list
    * \post The caller is responsible for deleting the extracted Entity
    * \post The Container's #count is lesser by one
    * \post If the Stack had 2 or more items, then the formerly 2nd Entity is
    * the top item
    * \post If the Stack had only 1 item, then the Stack is empty
    */
   Entity * pop();

protected:

   /*********************  Stack Methods (protected) *********************/

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in method #push
    */
   virtual void push_impl(Entity* entity) = 0;

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in method #pop
    */
   virtual Entity * pop_impl() = 0;

public:

   /*********************  Container Methods (public) *********************/

   int purgeContents();

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

#endif /* _STACK_H */
