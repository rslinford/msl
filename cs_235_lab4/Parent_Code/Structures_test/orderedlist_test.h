/*! \file orderedlist_test.h
 *  \brief Header file for class container_test::OrderedList_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/orderedlist_test.h $
 *  $Date: 2009-06-15 12:26:32 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 411 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: orderedlist_test.h
 * File creator:       slinford
 * Created on:         May 6, 2009, 8:35 PM
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

#ifndef _ORDEREDLIST_TEST_H
#define _ORDEREDLIST_TEST_H

#include "list_test.h"

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief Polymorphic code for testing concrete sub-classes of
 * container::OrderedList
 *
 * There are no actual unit tests in OrderedList_test that the googletest framework
 * will recognize and execute automatically. The googletest framework doesn't
 * provide an elegant solution for testing the compliance of derived classes.
 * This class is sub-classed by OrderedLinkedList_test and OrderedArrayList_test
 * in order to re-use common unit test code.
 */
class OrderedList_test: public List_test {
protected:

   /******************** Unit-test Helper Methods ********************/

   /********************  Unit-test methods for class OrderedList ********************/

   void append(const Object::Info* type);

   void insertingAndRemoving(const Object::Info* type);

};

} // namespace container_test
#endif /* _ORDEREDLIST_TEST_H */
