/*! \file linkedlist.cpp
 * \brief Definitions for classes container::LinkedList and container::LinkedList::Node
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/linkedlist.cpp $
 *  $Date: 2009-06-15 14:22:55 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 413 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: linkedlist.cpp
 *   File creator:       slinford
 *   Created on:         March 19, 2009, 11:25 PM
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

#include "linkedlist.h"

namespace container {

/*********************  class LinkedList *********************/

const Object::Info* const LinkedList::TYPE_INFO = Object::typeInfoFactory("LinkedList");

LinkedList::LinkedList(): head(new Node()), tail(new Node()) {
   current = tail;

   // Point dummy nodes to each other
   head->next = tail;
   head->prev = NULL;
   tail->prev = head;
   tail->next = NULL;
}

LinkedList::LinkedList(const LinkedList& pattern) { }

LinkedList::~LinkedList() {
   purgeContents();
   delete head;
   delete tail;
}

/*********************  LinkedList Methods (protected) *********************/

bool LinkedList::toNext(Node*& cursor) {
   if (cursor == tail) return (false);
   cursor = cursor->next;
   return (cursor != tail);
}

/*********************  List Methods *********************/

bool LinkedList::isFirst() const {
   if (current == tail) return (false);
   if (current != head->next) return (false);
   return (true);
}

bool LinkedList::isLast() const {
   if (tail->prev == current) return (true);
   return (false);
}

bool LinkedList::isTail() const {
   if (current == tail) return (true);
   return (false);
}

bool LinkedList::toFirst() {
   current = head->next;
   if (current == tail) return (false);

   return (true);
}

bool LinkedList::toLast() {
   if (isEmpty()) return (false);
   current = tail->prev;

   return (true);
}

void LinkedList::toTail() {
   current = tail;
}

bool LinkedList::toNext() {
   return toNext(current);
}

bool LinkedList::toPrev() {
   if (current == head->next) return (false);
   current = current->prev;
   return (true);
}

Entity * LinkedList::currentEntity() {
   if (isTail()) return (NULL);
   return (current->entity);
}

void LinkedList::locateEntity(const Entity &key, int &index, Entity* &entity) {
   Node * node = head;
   int i = 0;
   while (toNext(node)) {
      if (key.compareKeyTo(*node->entity) == 0) {
         index = i;
         entity = node->entity;
         return;
      }
      i++;
   }
   index = NO_MATCHING_ENTITY_INDEX_FLAG;
   entity = NULL;
}

Entity* LinkedList::entityAt(int index) {
   if ((index >= getCount()) || (index < 0)) {
      return NULL;
   }

   Node * node = head;
   for (int i = 0; toNext(node); i++) {
      if (i == index) {
         return node->entity;
      }
   }

   // should never get here
   return NULL;
}

/*********************  List Methods (protected) *********************/

bool LinkedList::deleteCurrent_impl() {
   if (isTail()) return false;

   Node *doomedNode = current;
   current = doomedNode->next;
   delete doomedNode;
   return true;
}

Entity * LinkedList::extractCurrentEntity_impl() {
   if (isTail()) return NULL;

   Node *doomedNode = current;
   current = doomedNode->next;
   Entity * entity = doomedNode->extractEntity();
   delete doomedNode;
   return entity;
}

/*********************  Object Methods (public) *********************/

ostream & LinkedList::renderState(ostream& os) const {
   this->List::renderState(os);
   if (isTail()) {
      os << " TAIL<--CURSOR";
   }
   os << " contents{";
   const struct LinkedList::Node* node = head->next;

   for (int i = 0; node != tail; i++) {
      if (i > 0) {
         os << ", ";
      }
      const Entity* entity = node->entity;
      os << std::endl << "      [" << i << ']' << entity;
      if (node == current) {
         os << " <--CURSOR";
      }
      node = node->next;
   }

   return os << "}";
}

const Object::Info* LinkedList::typeInfo() const {
   return TYPE_INFO;
}

/********************* Nested class LinkedList::Node *********************/

LinkedList::Node::Node(): next(NULL), prev(NULL), entity(NULL) { }

LinkedList::Node::Node(Entity *e, Node *n): next(n), prev(n->prev), entity(e) {
   // Tell the list where this new node belongs
   next->prev = this;
   prev->next = this;
}

LinkedList::Node::~Node() {
   // Remove itself from the list
   if (prev != NULL) {
      prev->next = next;
   }

   if (next != NULL) {
      next->prev = prev;
   }

   // Delete its entity
   if (entity != NULL) {
      delete entity;
   }
}

Entity * LinkedList::Node::extractEntity() {
   Entity *e = entity;
   entity = NULL;
   return e;
}

} // namespace container
