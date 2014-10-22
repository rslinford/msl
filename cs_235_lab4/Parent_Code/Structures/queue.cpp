/*! \file queue.cpp
 *  \brief Definitions for class container::Queue
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/queue.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: queue.cpp
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

#include "queue.h"

namespace container {

const Object::Info * const Queue::TYPE_INFO = Object::typeInfoFactory("Queue");

Queue::Queue() { }

Queue::Queue(const Queue& orig): Container(orig) { }

Queue::~Queue() { }

/*********************  Queue Methods (public) *********************/

void Queue::enqueue(Entity* entity) {
   if (entity == NULL) {
      return;
   }
   enqueue_impl(entity);
   incCount();
}

Entity * Queue::dequeue() {
   if (getCount() == 0) {
      return NULL;
   }
   Entity * e = dequeue_impl();
   decCount();
   return e;
}

/*********************  Container Methods (public) *********************/

int Queue::purgeContents() {
   int n = 0;
   for (Entity* e = dequeue(); e != NULL; e = dequeue()) {
      delete e;
      n++;
   }
   return n;
}

/*********************  Object Methods  *********************/

ostream & Queue::renderState(ostream& os) const {
   return this->Container::renderState(os);
}

const Object::Info* Queue::typeInfo() const {
   return TYPE_INFO;
}

} // namespace container
