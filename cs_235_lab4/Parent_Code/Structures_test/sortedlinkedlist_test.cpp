/*! \file sortedlinkedlist_test.cpp
 *  \brief Definitions for class container_test::SortedLinkedList_test
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/sortedlinkedlist_test.cpp $
 *  $Date: 2009-06-07 19:10:14 -0400 (Sun, 07 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 379 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: sortedlinkedlist_test.cpp
 * File creator:       slinford
 * Created on:         April 11, 2009, 6:38 PM
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

#include "util.h"
#include "sortedlist_test.h"

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief Unit tests for SortedLinkedList
 */
class SortedLinkedList_test: public SortedList_test {
protected:

   // If the constructor and destructor are not enough for setting up
   // and cleaning up each test, you can define the following methods:

   virtual void SetUp() {
      // Code here will be called immediately after the constructor (right
      // before each test).
   }

   virtual void TearDown() {
      // Code here will be called immediately after each test (right
      // before the destructor).
   }

   // Objects declared here can be used by all tests in the test case for Foo.

};

TEST_F(SortedLinkedList_test, DefaultConstructor) {
   defaultConstructor(SortedLinkedList::TYPE_INFO);
}

TEST_F(SortedLinkedList_test, cursorControl) {
   cursorControl(SortedLinkedList::TYPE_INFO);
}

TEST_F(SortedLinkedList_test, insertSorted) {
   insertSorted(SortedLinkedList::TYPE_INFO);
}

TEST_F(SortedLinkedList_test, insertingAndRemoving) {
   insertingAndRemoving(SortedLinkedList::TYPE_INFO);
}

TEST_F(SortedLinkedList_test, purgeConents) {
   purgeConents(SortedLinkedList::TYPE_INFO);
}

TEST_F(SortedLinkedList_test, locateEntity) {
   locateEntity(SortedLinkedList::TYPE_INFO);
}

TEST_F(SortedLinkedList_test, entityAt) {
   locateEntity(SortedLinkedList::TYPE_INFO);
}

} // namespace container_test
