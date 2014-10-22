/*! \file orderedlinkedlist_test.cpp
 * \brief Definitions for class container_test::OrderedLinkedList_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/orderedlinkedlist_test.cpp $
 *  $Date: 2009-05-07 22:56:28 -0400 (Thu, 07 May 2009) $
 *  $Author: slinford $
 *  $Revision: 362 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: linkedlist_test.cpp
 *   File creator:       slinford
 *   Created on:         March 24, 2009, 7:52 PM
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

#include "orderedlinkedlist_test.h"
#include <gtest.h>

using namespace container;
using namespace std;

namespace container_test {

TEST_F(OrderedLinkedList_test, DefaultConstructor) {
   defaultConstructor(OrderedLinkedList::TYPE_INFO);
}

TEST_F(OrderedLinkedList_test, append) {
   append(OrderedLinkedList::TYPE_INFO);
}

TEST_F(OrderedLinkedList_test, cursorControl) {
   cursorControl(OrderedLinkedList::TYPE_INFO);
}

TEST_F(OrderedLinkedList_test, insertingAndRemoving) {
   insertingAndRemoving(OrderedLinkedList::TYPE_INFO);
}

TEST_F(OrderedLinkedList_test, purgeConents) {
   purgeConents(OrderedLinkedList::TYPE_INFO);
}

TEST_F(OrderedLinkedList_test, locateEntity) {
   locateEntity(OrderedLinkedList::TYPE_INFO);
}

TEST_F(OrderedLinkedList_test, entityAt) {
   locateEntity(OrderedLinkedList::TYPE_INFO);
}

} // namespace container_test
