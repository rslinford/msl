/*! \file sortedlist_test.h
 *  \brief Header file for class container_test::SortedList_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/sortedlist_test.h $
 *  $Date: 2009-06-15 12:26:32 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 411 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: sortedlist_test.h
 * File creator:       slinford
 * Created on:         June 6, 2009, 8:57 PM
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

#ifndef _SORTEDLIST_TEST_H
#define _SORTEDLIST_TEST_H

#include "list_test.h"
#include "person.h"
#include <gtest.h>

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief Polymorphic code for testing concrete sub-classes of
 * container::SortedList
 *
 * There are no actual unit tests in SortedList_test that the googletest framework
 * will recognize and execute automatically. The googletest framework doesn't
 * provide an elegant solution for testing the compliance of derived classes.
 * This class is sub-classed by SortedLinkedList_test and SortedArrayList_test
 * in order to re-use common unit test code.
 */
class SortedList_test: public List_test {
protected:
   // You can remove any or all of the following functions if its body
   // is empty.

   OrderedLinkedList unsortedGroup;
   OrderedLinkedList sortedGroup;
   Person *joeSmith;
   Person *janeSmith;
   Person *fredHarris;
   Person *joseGonzales;
   Person *fernandaMijares;

   OrderedLinkedList otherUnsortedGroup;
   OrderedLinkedList otherSortedGroup;
   Person *otherJoeSmith;
   Person *otherJaneSmith;
   Person *otherFredHarris;
   Person *otherJoseGonzales;
   Person *otherFernandaMijares;

   SortedList_test();

   virtual ~SortedList_test();

   /******************** Unit-test Helper Methods ********************/

   /********************  Unit-test methods for class SortedList ********************/

   void insertSorted(const Object::Info* type);

   void insertingAndRemoving(const Object::Info* type);

};

} // namespace container_test
#endif /* _SORTEDLIST_TEST_H */
