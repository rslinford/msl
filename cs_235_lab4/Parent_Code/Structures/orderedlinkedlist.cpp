/*! \file orderedlinkedlist.cpp
 *  \brief Definitions for class container::OrderedLinkedList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/orderedlinkedlist.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: orderedlinkedlist.cpp
 * File creator:       slinford
 * Created on:         April 11, 2009, 11:18 PM
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

#include "orderedlinkedlist.h"

namespace container {

const Object::Info * const OrderedLinkedList::TYPE_INFO = Object::typeInfoFactory("OrderedLinkedList");

OrderedLinkedList::OrderedLinkedList() { }

OrderedLinkedList::OrderedLinkedList(const OrderedLinkedList& orig) { }

OrderedLinkedList::~OrderedLinkedList() { }

/*********************  OrderedList Methods (protected) *********************/

void OrderedLinkedList::append_impl(Entity* entity) {
   new Node(entity, tail);
}

void OrderedLinkedList::insertBefore_impl(Entity* entity) {
   new Node(entity, current);
}

/*********************  List Methods  (protected) *********************/

bool OrderedLinkedList::add_impl(Entity* entity) {
   append_impl(entity);
   return true;
}

/*********************  Object Methods (public) *********************/

ostream & OrderedLinkedList::renderState(ostream& os) const {
   return this->LinkedList::renderState(os);
}

const Object::Info* OrderedLinkedList::typeInfo() const {
   return TYPE_INFO;
}

Object* OrderedLinkedList::clone(bool deepCopy) const { }

} // namespace container
