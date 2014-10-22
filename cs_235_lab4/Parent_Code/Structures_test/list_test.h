/*! \file list_test.h
 * \brief Header file for class container_test::List_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/list_test.h $
 *  $Date: 2009-06-15 12:26:32 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 411 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: list_test.cpp
 * File creator:       slinford
 * Created on:         April 11, 2009, 6:58 PM
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

#ifndef _LIST_TEST_H
#define _LIST_TEST_H

#include "util.h"
#include "test_util.h"
#include <gtest.h>

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief Polymorphic code for testing concrete sub-classes of container::List
 *
 * There are no actual unit tests in List_test that the googletest framework
 * will recognize and execute automatically. The googletest framework doesn't
 * provide an elegant solution for testing the compliance of derived classes. 
 * This class is sub-classed by OrderedLinkedList_test and SortedLinkedList_test
 * in order to re-use common unit test code.
 */
class List_test: public testing::Test {
protected:

   static const int SOME_OTHER_KEY;
   static const int ZERO_INDEX;
   static const int NEGATIVE_INDEX;
   static const int BIG_INDEX;
   static const int SOME_OTHER_INDEX;
   static const int INDEX_NOT_FOUND;
   static const int KEY_4;
   static const string KEY_4_AS_STRING;

   /******************** Unit-test Helper Methods ********************/

   void verifyEmptyStateCoherence(List* a);

   void verifyEmptyStateCoherence(List& a);

   void verifyNonEmptyStateCoherence_tail(List* a, int count);

   void verifyNonEmptyStateCoherence_tail(List& a, int count);

   void verifyNonEmptyStateCoherence_notTail(List* a, int count);

   void verifyNonEmptyStateCoherence_notTail(List& a, int count);

   /*!
    * \brief Creates a new test data set.
    *
    * A new data array is created and a new List. Both are populated
    * with the same list of Entities. It is the responsibility of the caller
    * to release all objects created: the array of Entity pointers, the
    * List, and all the Entity objects.
    *
    * \post A new array of Entity pointers is created.
    * \post A new Linked List is created.
    * \post SIZE number if Entity objects are created.
    * \post The data array and the List will both be populated
    * with pointers to the newly created Entity objects.
    * \post The order will be the same in both the data array and the
    * List.
    */
   void generateDataAndPopulateList(Entity** &data,
                                    List* list,
                                    const int listSize,
                                    bool print = false);


   /********************  Unit-test methods for class List ********************/

   void defaultConstructor(const Object::Info* type);

   void cursorControl(const Object::Info* type);

   void purgeConents(const Object::Info* type);

   void locateEntity(const Object::Info* type);

   void entityAt(const Object::Info* type);

};

} // namespace container_test
#endif /* _LIST_TEST_H */
