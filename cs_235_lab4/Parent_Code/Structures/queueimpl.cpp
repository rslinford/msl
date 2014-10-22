/*! \file queueimpl.cpp
 *  \brief Definitions for class container::QueueImpl
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/queueimpl.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: queueimpl.cpp
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

#include "queueimpl.h"
#include "orderedlinkedlist.h"
#include "orderedarraylist.h"

namespace container {

const Object::Info * const QueueImpl::TYPE_INFO =
      Object::typeInfoFactory("QueueImpl");

QueueImpl::QueueImpl(OrderedList * lst): list(lst) { }

QueueImpl::QueueImpl(const QueueImpl& orig): Queue(orig),
list(dynamic_cast<OrderedList * const>(orig.list->clone())) { }

QueueImpl::QueueImpl(const QueueImpl& orig, bool deepCopy): Queue(orig),
list(dynamic_cast<OrderedList * const>(orig.list->clone(deepCopy))) { }

QueueImpl::~QueueImpl() {
   delete list;
}

/*********************  QueueImpl Methods (public) *********************/

Queue* QueueImpl::factoryLinkedComposition() {
   return new QueueImpl(new OrderedLinkedList());
}

Queue* QueueImpl::factoryArrayComposition() {
   return new QueueImpl(new OrderedArrayList());
}

/*********************  Queue Methods (protected) *********************/

void QueueImpl::enqueue_impl(Entity* entity) {
   list->append(entity);
}

Entity * QueueImpl::dequeue_impl() {
   if (list->toFirst()) {
      return list->extractCurrentEntity();
   } else {
      return NULL;
   }
}

/*********************  Object Methods (public) *********************/

ostream & QueueImpl::renderState(ostream& os) const {

   this->Queue::renderState(os);
   os << " composed with an " << list->typeInfo()->typeName << " contents{";
   int i = 0;
   for (list->toFirst(); !list->isTail(); list->toNext()) {
      os << std::endl << "      [" << i << ']' << list->currentEntity();
      if (list->getCount() > 1) {
         if (list->isFirst()) {
            os << " <--FIRST";
         } else if (list->isLast()) {
            os << " <--LAST";
         }
      }
      i++;
   }
   return os << "}";
}

const Object::Info* QueueImpl::typeInfo() const {
   return TYPE_INFO;
}

Object* QueueImpl::clone(bool deepCopy) const {
   return new QueueImpl(*this, deepCopy);
}

} // namespace container
