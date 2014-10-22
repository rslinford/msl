/*! \file queue.h
 *  \brief Header file for class container::Queue
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/queue.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: queue.h
 * File creator:       slinford
 * Created on:         June 9, 2009, 9:46 PM
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

#ifndef _QUEUE_H
#define	_QUEUE_H

#include "container.h"

using std::string;

namespace container {

/*!
 * \brief Abstract base class for all queue containers
 *
 * Allows duplicates. Is unbounded.
 */
class Queue: public Container {
public:

   const static Info * const TYPE_INFO;

protected:

   Queue();
   Queue(const Queue& orig);

public:

   virtual ~Queue();

   /*********************  Queue Methods (public) *********************/

   /*!
    * \brief Add an Entity onto the end of the Queue
    *
    * A template method that calls the #enqueue_impl method of the the derived
    * class.
    *
    * \pre The specified \a entity pointer is not null
    * \post If there were already 1 or more items in the queue, the specified
    * \a entity is the last item in the Queue
    * \post If the queue was empty, the specified \a entity can be considered
    * to be both the first and last item in the queue
    * \post The Container's #count is greater by one
    */
   void enqueue(Entity* entity);

   /*!
    * \brief Remove the first Entity from the Queue and return a pointer to the
    * Entity
    *
    * A template method that calls the #dequeue_impl method of the the derived
    * class.
    *
    * \return A pointer to the Entity that was removed from the first position
    * of the queue
    *
    * \pre There is at least one item in the Queue
    * \post The Entity (formerly the first item) is not in the list
    * \post The caller is responsible for deleting the extracted Entity
    * \post The Container's #count is lesser by one
    * \post If the Queue had 2 or more items, then the formerly 2nd Entity is
    * the first item
    * \post If the Queue had only 1 item, then the Queue is empty
    */
   Entity * dequeue();

protected:

   /*********************  Queue Methods (protected) *********************/

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in method #enqueue
    */
   virtual void enqueue_impl(Entity* entity) = 0;

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in method #dequeue
    */
   virtual Entity * dequeue_impl() = 0;

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
#endif	/* _QUEUE_H */
