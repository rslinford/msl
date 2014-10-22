/*! \file orderedlist.cpp
 * \brief Definitions for class container::OrderedList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/orderedlist.cpp $
 *  $Date: 2009-06-10 21:54:03 -0400 (Wed, 10 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 385 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: orderedlist.cpp
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

#include "orderedlist.h"

namespace container {

const Object::Info* const OrderedList::TYPE_INFO = Object::typeInfoFactory("OrderedList");

OrderedList::OrderedList() { }

OrderedList::OrderedList(const OrderedList& pattern) { }

/*!
 * \brief Destructor
 */
OrderedList::~OrderedList() { }

/*********************  OrderedList Methods (protected) *********************/

void OrderedList::append(Entity* entity) {
   append_impl(entity);
   incCount();
}

void OrderedList::insertBefore(Entity* entity) {
   insertBefore_impl(entity);
   incCount();
}

/*********************  Object Methods (public)  *********************/

ostream & OrderedList::renderState(ostream& os) const {
   return this->List::renderState(os);
}

const Object::Info* OrderedList::typeInfo() const {
   return TYPE_INFO;
}

} // namespace container
