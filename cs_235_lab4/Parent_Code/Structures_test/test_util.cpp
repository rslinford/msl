/*! \file test_util.cpp
 * \brief Definitions for unit-testing utility functions. Part of namespace
 * container_test.
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/test_util.cpp $
 *  $Date: 2009-06-07 18:47:33 -0400 (Sun, 07 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 378 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: test_util.cpp
 * File creator:       slinford
 * Created on:         April 27, 2009, 5:17 PM
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

#include "test_util.h"

using namespace container;

namespace container_test {

List* listFactory(const Object::Info* type) {
   List *list = orderedListFactory(type);
   if (list != NULL) {
      return list;
   }

   return sortedListFactory(type);
}

OrderedList* orderedListFactory(const Object::Info* type) {
   if (type == OrderedLinkedList::TYPE_INFO) {
      return new OrderedLinkedList();
   } else if (type == OrderedArrayList::TYPE_INFO) {
      return new OrderedArrayList();
   } else {
      return NULL;
   }
}

SortedList* sortedListFactory(const Object::Info* type) {
   if (type == SortedLinkedList::TYPE_INFO) {
      return new SortedLinkedList();
   } else if (type == SortedArrayList::TYPE_INFO) {
      return new SortedArrayList();
   } else {
      return NULL;
   }
}

} // namespace container_test
