/*! \file arraylist.cpp
 *  \brief Definition for class container::ArrayList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/arraylist.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: arraylist.cpp
 * File creator:       slinford
 * Created on:         May 3, 2009, 3:04 PM
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

#include "arraylist.h"

namespace container {

const Object::Info * const ArrayList::TYPE_INFO = Object::typeInfoFactory("ArrayList");

/*! \brief Initial capacity of the underlying array
 *
 * It's set to a small value for testing the dynamic growth behavior.
 */
const int ArrayList::DEFAULT_INITIAL_CAPACITY = 4;

/*! \brief The increment that will be added to \a capacity when the array
 *  needs to grow
 *
 * It's set to a small value for testing the dynamic growth behavior.
 */
const int ArrayList::DEFAULT_ADDITIONAL_CAPACITY = 2;
const int ArrayList::BASE_INDEX = 0;

ArrayList::ArrayList(): capacity(DEFAULT_INITIAL_CAPACITY),
additionalCapacity(DEFAULT_ADDITIONAL_CAPACITY), array(NULL) {
   current = getCount();
   allocateArray();
}

ArrayList::ArrayList(int initCapacity, int addCapacity): capacity(initCapacity),
additionalCapacity(addCapacity), array(NULL) {
   current = getCount();
   allocateArray();
}

ArrayList::ArrayList(const ArrayList& pattern) {
   copyConstructor(pattern);
}

ArrayList::ArrayList(const ArrayList& pattern, bool deepCopy) {
   copyConstructor(pattern, deepCopy);
}

void ArrayList::copyConstructor(const ArrayList& pattern, bool deepCopy) {
   setCount(pattern.getCount());
   additionalCapacity = pattern.additionalCapacity;
   current = pattern.current;
   capacity = pattern.getCount();
   if (capacity == 0) {
      capacity = DEFAULT_INITIAL_CAPACITY;
   }
   array = new Entity*[capacity];

   for (int i = 0; i < pattern.getCount(); i++) {
      if (deepCopy) {
         // point to copies of existing Entities
         array[i] = dynamic_cast<Entity*>(pattern.array[i]->clone(deepCopy));
      } else {
         // point to existing Entities (shallow copy)
         array[i] = pattern.array[i];
      }
   }

   // Initialize the rest to NULL
   for (int i = getCount(); i < capacity; i++) {
      array[i] = NULL;
   }
}

ArrayList::~ArrayList() {
   purgeContents();
   delete array;
}

/*********************  ArrayList Methods (protected) *********************/

void ArrayList::allocateArray() {
   Entity ** oldArray = array;

   if (oldArray != NULL) {
      capacity += additionalCapacity;
   }

   array = new Entity*[capacity];

   // Copying old values
   for (int i = 0; i < getCount(); i++) {
      array[i] = oldArray[i];
   }

   // Initialize the rest to NULL
   for (int i = getCount(); i < capacity; i++) {
      array[i] = NULL;
   }

   if (oldArray != NULL) {
      delete [] oldArray;
   }
}

void ArrayList::closeGap() {
   closeGap(current);
}

void ArrayList::closeGap(int index) {
   if (isTail()) {
      return;
   }

   if (current > index) {
      current--;
   }

   const int lastElementIndex = getCount() - 1;

   for (int i = index; i < lastElementIndex; i++) {
      array[i] = array[i + 1];
   }

   array[lastElementIndex] = NULL;
}

void ArrayList::openGap(int index) {
   if (isAtCapacity()) {
      allocateArray();
   }

   for (int i = getCount(); i > index; i--) {
      array[i] = array[i - 1];
   }

   if (current >= index) {
      current++;
   }
}

inline bool ArrayList::isAtCapacity() const {
   return capacity == getCount();
}

/*********************  List Methods (protected) *********************/

bool ArrayList::deleteCurrent_impl() {
   if (isTail()) return false;

   Entity * entity = array[current];
   closeGap();
   delete entity;
   return true;
}

Entity * ArrayList::extractCurrentEntity_impl() {
   if (isTail()) return NULL;

   Entity * entity = array[current];
   closeGap();
   return entity;
}

/*********************  Object Methods (public) *********************/

ostream & ArrayList::renderState(ostream& os) const {
   this->List::renderState(os);
   os << " capacity(" << capacity << ")";
   if (isTail()) {
      os << " TAIL<--CURSOR";
   }
   os << " contents{";

   int first = BASE_INDEX;
   for (int i = first; i < getCount(); i++) {
      if (i > first) {
         os << ", ";
      }
      os << std::endl << "      [" << i << ']' << array[i];
      if (i == current) {
         os << " <--CURSOR";
      }
   }

   return os << "}";
}

const Object::Info* ArrayList::typeInfo() const {
   return TYPE_INFO;
}

/*********************  List Methods (public) *********************/

bool ArrayList::isFirst() const {
   if (isEmpty()) {
      return false;
   }

   return current == BASE_INDEX;
}

bool ArrayList::isLast() const {
   if (isEmpty()) {
      return false;
   }

   return current == (getCount() - 1);
}

bool ArrayList::isTail() const {
   return current == getCount();
}

bool ArrayList::toFirst() {
   if (isEmpty()) {
      return false;
   }

   current = BASE_INDEX;
   return true;
}

bool ArrayList::toLast() {
   if (isEmpty()) {
      return false;
   }

   current = getCount() - 1;
   return true;
}

void ArrayList::toTail() {
   current = getCount();
}

bool ArrayList::toNext() {
   if (isTail()) {
      return false;
   }

   current++;
   return !isTail();
}

bool ArrayList::toPrev() {
   if (isFirst() || isEmpty()) {
      return false;
   }

   current--;
   return true;
}

Entity * ArrayList::currentEntity() {
   if (isTail()) return (NULL);
   return (array[current]);
}

void ArrayList::locateEntity(const Entity &key, int &index, Entity* &entity) {
   for (int i = 0; i < getCount(); i++) {
      if (key.compareKeyTo(*array[i]) == 0) {
         index = i;
         entity = array[i];
         return;
      }
   }

   index = NO_MATCHING_ENTITY_INDEX_FLAG;
   entity = NULL;
}

Entity* ArrayList::entityAt(int index) {
   if ((index >= getCount()) || (index < BASE_INDEX)) {
      return NULL;
   }

   return array[index];
}

} // namespace container
