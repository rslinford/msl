/*! \file queueimpl.h
 *  \brief Header file for class container::QueueImpl
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/queueimpl.h $
 *  $Date: 2009-06-16 23:12:25 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 422 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: queueimpl.h
 * File creator:       slinford
 * Created on:         June 10, 2009, 6:30 PM
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

#ifndef _QUEUEIMPL_H
#define	_QUEUEIMPL_H

#include "queue.h"
#include "orderedlist.h"

using std::string;

namespace container {

/*!
 * \brief An implementation of Queue that based on an OrderedList
 *
 * Two factory methods are provided: #factoryLinkedComposition() and
 * #factoryArrayComposition(). The first creates a Queue with an underlying
 * OrderedLinkedList and the second with an underlying OrderedArrayList.
 * Since both satisfy the OrderedList contract, no special handling was
 * required for the either type.
 */
class QueueImpl: public Queue {
public:

   const static Info * const TYPE_INFO;

private:
   OrderedList * const list;

   QueueImpl(OrderedList* list);

public:

   QueueImpl(const QueueImpl& orig);

   QueueImpl(const QueueImpl& orig, bool deepCopy);

   virtual ~QueueImpl();


   /*********************  QueueImpl Methods (public) *********************/

   /*!
    * \brief Constructs an QueueImpl with an underlying OrderedLinkedList
    */
   static Queue* factoryLinkedComposition();

   /*!
    * \brief Constructs a QueueImpl with an underlying OrderedArrayList
    */
   static Queue* factoryArrayComposition();

protected:

   /*********************  Queue Methods (protected) *********************/

   virtual void enqueue_impl(Entity* entity);

   virtual Entity * dequeue_impl();

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const;

};

} // namespace container
#endif /* _QUEUEIMPL_H */
