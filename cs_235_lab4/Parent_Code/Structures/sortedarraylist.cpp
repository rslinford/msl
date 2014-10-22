/*! \file sortedarraylist.cpp
 *  \brief Definitions for class container::SortedArrayList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/sortedarraylist.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: sortedarraylist.cpp
 * File creator:       slinford
 * Created on:         May 9, 2009, 6:50 PM
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

#include "sortedarraylist.h"

namespace container {

const Object::Info* const SortedArrayList::TYPE_INFO =
      Object::typeInfoFactory("SortedArrayList");

SortedArrayList::SortedArrayList() { }

SortedArrayList::SortedArrayList(const SortedArrayList& orig) { }

SortedArrayList::~SortedArrayList() { }

/*********************  SortedArrayList Methods (private) *********************/

bool SortedArrayList::binarySearch(const Entity &key, int& index) const {
   int tIndex = BASE_INDEX;
   int bIndex = getCount() - 1;
   index = BASE_INDEX; // default to first element for empty list

   for (int range = bIndex - tIndex; range >= 0; range = bIndex - tIndex) {
      index = (range / 2) + tIndex;

      int delta = key.compareKeyTo(*array[index]);
      if (delta > 0) {
         tIndex = ++index;
      } else if (delta < 0) {
         bIndex = index - 1;
      } else {
         return true;
      }
   }

   return false;
}

/*********************  SortedList Methods (protected) *********************/

bool SortedArrayList::insertSorted_impl(Entity* entity) {
   int targetIndex = 0;
   if (binarySearch(*entity, targetIndex)) {
      return false;
   }
   openGap(targetIndex);
   array[targetIndex] = entity;
   return true;
}

/*********************  List Methods (public) *********************/

void SortedArrayList::locateEntity(const Entity &key, int &index, Entity* &entity) {
   int i = 0;
   if (binarySearch(key, i)) {
      index = i;
      entity = array[i];
   } else {
      index = NO_MATCHING_ENTITY_INDEX_FLAG;
      entity = NULL;
   }
}

/*********************  List Methods (protected) *********************/

bool SortedArrayList::add_impl(Entity* entity) {
   return insertSorted_impl(entity);
}

/*********************  Object Methods (public) *********************/

ostream & SortedArrayList::renderState(ostream& os) const {
   return this->ArrayList::renderState(os);
}

const Object::Info* SortedArrayList::typeInfo() const {
   return TYPE_INFO;
}

Object* SortedArrayList::clone(bool deepCopy) const { }

} // namespace container
