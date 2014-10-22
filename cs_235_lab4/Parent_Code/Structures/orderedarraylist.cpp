/*! \file orderedarraylist.cpp
 *  \brief Definitions for class container::OrderedArrayList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/orderedarraylist.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: orderedarraylist.cpp
 * File creator:       slinford
 * Created on:         May 5, 2009, 8:14 PM
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

#include "orderedarraylist.h"

namespace container {

const Object::Info * const OrderedArrayList::TYPE_INFO =
      Object::typeInfoFactory("OrderedArrayList");

OrderedArrayList::OrderedArrayList() { }

OrderedArrayList::OrderedArrayList(int initCapacity,
                                   int addCapacity = DEFAULT_ADDITIONAL_CAPACITY):
ArrayList(initCapacity, addCapacity) { }

OrderedArrayList::OrderedArrayList(const OrderedArrayList& orig): ArrayList(orig) { }

OrderedArrayList::OrderedArrayList(const OrderedArrayList& orig, bool deepCopy):
ArrayList(orig, deepCopy) { }


//int capacity = orig.list->getCount();
//if (capacity == 0) {
//   capacity = ArrayList::DEFAULT_INITIAL_CAPACITY;
//}

OrderedArrayList::~OrderedArrayList() { }

/*********************  OrderedList Methods (protected) *********************/

void OrderedArrayList::append_impl(Entity* entity) {
   const int targetIndex = getCount();
   openGap(targetIndex);
   array[targetIndex] = entity;
}

void OrderedArrayList::insertBefore_impl(Entity* entity) {
   const int targetIndex = current;
   openGap(targetIndex);
   array[targetIndex] = entity;
}

/*********************  List Methods  (protected) *********************/

bool OrderedArrayList::add_impl(Entity* entity) {
   append_impl(entity);
   return true;
}

/*********************  Object Methods (public) *********************/

ostream & OrderedArrayList::renderState(ostream& os) const {
   return this->ArrayList::renderState(os);
}

const Object::Info* OrderedArrayList::typeInfo() const {
   return TYPE_INFO;
}

Object* OrderedArrayList::clone(bool deepCopy) const {
   return new OrderedArrayList(*this, deepCopy);
}

} // namespace container
