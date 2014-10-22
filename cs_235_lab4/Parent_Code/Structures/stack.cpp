/*! \file stack.cpp
 *  \brief Definitions for class container::Stack
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/stack.cpp $
 *  $Date: 2009-06-15 17:17:31 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 414 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: stack.cpp
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

#include "stack.h"

namespace container {

const Object::Info * const Stack::TYPE_INFO = Object::typeInfoFactory("Stack");

Stack::Stack() { }

Stack::Stack(const Stack& orig) { }

Stack::~Stack() { }

/*********************  Stack Methods (public) *********************/

void Stack::push(Entity* entity) {
   if (entity == NULL) {
      return;
   }
   push_impl(entity);
   incCount();
}

Entity * Stack::pop() {
   if (getCount() == 0) {
      return NULL;
   }
   Entity * e = pop_impl();
   decCount();
   return e;
}

/*********************  Container Methods (public) *********************/

int Stack::purgeContents() {
   int n = 0;
   for (Entity* e = pop(); e != NULL; e = pop()) {
      delete e;
      n++;
   }
   return n;
}

/*********************  Object Methods  *********************/

ostream & Stack::renderState(ostream& os) const {
   return this->Container::renderState(os);
}

const Object::Info* Stack::typeInfo() const {
   return TYPE_INFO;
}

} // namespace container
