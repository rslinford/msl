/*! \file sortedlinkedlist.cpp
 *  \brief Definitions for class container::SortedLinkedList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/sortedlinkedlist.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: sortedlinkedlist.cpp
 * File creator:       slinford
 * Created on:         April 11, 2009, 6:23 PM
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

#include "sortedlinkedlist.h"

namespace container {

const Object::Info * const SortedLinkedList::TYPE_INFO =
      Object::typeInfoFactory("SortedLinkedList");

SortedLinkedList::SortedLinkedList() { }

SortedLinkedList::SortedLinkedList(const SortedLinkedList& orig) { }

SortedLinkedList::~SortedLinkedList() { }

/*********************  SortedList Methods (protected) *********************/

bool SortedLinkedList::insertSorted_impl(Entity* entity) {
   Entity& newEntity = *entity;
   for (struct Node* node = head->next; node != tail; node = node->next) {
      Entity& existingEntity = *node->entity;
      int delta = newEntity.compareKeyTo(existingEntity);

      if (delta < 0) {
         new Node(entity, node);
         return true;
      }

      if (delta == 0) {
         return false;
      }
   }

   new Node(entity, tail);
   return true;
}

/*********************  List Methods (protected) *********************/

bool SortedLinkedList::add_impl(Entity* entity) {
   return insertSorted_impl(entity);
}

/*********************  Object Methods (public) *********************/

ostream & SortedLinkedList::renderState(ostream& os) const {
   return this->LinkedList::renderState(os);
}

const Object::Info* SortedLinkedList::typeInfo() const {
   return TYPE_INFO;
}

Object* SortedLinkedList::clone(bool deepCopy) const { }

} // namespace container
