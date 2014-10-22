/*! \file list.cpp
 * \brief Definitions for class container::List
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/list.cpp $
 *  $Date: 2009-06-10 21:54:03 -0400 (Wed, 10 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 385 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: list.cpp
 *   File creator:       slinford
 *   Created on:         March 30, 2009, 11:39 PM
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

#include "list.h"

namespace container {

const Object::Info* const List::TYPE_INFO = Object::typeInfoFactory("List");

const int List::NO_MATCHING_ENTITY_INDEX_FLAG = -1;

List::List() { }

List::List(const List& orig) { }

List::~List() { }

/*********************  List Methods (public) *********************/

bool List::add(Entity* entity) {
   int oldCount = getCount();
   if (add_impl(entity)) {
      if (oldCount == getCount()) {
         incCount();
      }
      return true;
   }

   return false;
}

bool List::deleteCurrent() {
   if (deleteCurrent_impl()) {
      decCount();
      return true;
   }

   return false;
}

Entity * List::extractCurrentEntity() {
   Entity * e = extractCurrentEntity_impl();
   decCount();
   return e;
}

int List::purgeContents() {
   if (!toFirst()) return 0;
   int i = 0;
   while (deleteCurrent()) {
      i++;
   }
   return i;
}

/*********************  Object Methods  *********************/

ostream & List::renderState(ostream& os) const {
   return this->Container::renderState(os);
}

const Object::Info* List::typeInfo() const {
   return TYPE_INFO;
}

} // namespace container
