/*! \file orderedarraylist_test.cpp
 *  \brief Definitions for class container_test::OrderedArrayList_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/orderedarraylist_test.cpp $
 *  $Date: 2009-05-07 22:56:28 -0400 (Thu, 07 May 2009) $
 *  $Author: slinford $
 *  $Revision: 362 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: orderedarraylist_test.cpp
 * File creator:       slinford
 * Created on:         May 7, 2009, 10:31 PM
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

#include "orderedlist_test.h"

using namespace container;

namespace container_test {

/*!
 * \brief Test cases for concrete class container::OrderedArrayList
 */
class OrderedArrayList_test: public OrderedList_test {

};

TEST_F(OrderedArrayList_test, DefaultConstructor) {
   defaultConstructor(OrderedArrayList::TYPE_INFO);
}

TEST_F(OrderedArrayList_test, append) {
   append(OrderedArrayList::TYPE_INFO);
}

TEST_F(OrderedArrayList_test, cursorControl) {
   cursorControl(OrderedArrayList::TYPE_INFO);
}

TEST_F(OrderedArrayList_test, insertingAndRemoving) {
   insertingAndRemoving(OrderedArrayList::TYPE_INFO);
}

TEST_F(OrderedArrayList_test, purgeConents) {
   purgeConents(OrderedArrayList::TYPE_INFO);
}

TEST_F(OrderedArrayList_test, locateEntity) {
   locateEntity(OrderedArrayList::TYPE_INFO);
}

TEST_F(OrderedArrayList_test, entityAt) {
   locateEntity(OrderedArrayList::TYPE_INFO);
}

} // namespace container_test
