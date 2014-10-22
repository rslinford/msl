/*! \file orderedlist_test.cpp
 *  \brief Definitions for class container_test::OrderedList_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/orderedlist_test.cpp $
 *  $Date: 2009-06-06 22:08:05 -0400 (Sat, 06 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 373 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: orderedlist_test.cpp
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

#include "orderedlist_test.h"

using namespace container;

namespace container_test {

/******************** Unit-test Helper Methods ********************/

/********************  Unit-test methods for class OrderedList ********************/

void OrderedList_test::append(const Object::Info* type) {
   // Null check, probably not necessary, but I'm just trying to figure
   // out this new framework.
   OrderedList* a = orderedListFactory(type);

   cout << "List a is empty" << endl;
   cout << "  " << a << endl;
   EXPECT_TRUE(a->isEmpty());

   Entity* e1 = new Entity();
   a->append(e1);
   cout << "List a has one item." << endl;
   cout << "  " << a << endl;
   EXPECT_FALSE(a->isEmpty());

   delete a;
}

void OrderedList_test::insertingAndRemoving(const Object::Info* type) {
   OrderedList* a = orderedListFactory(type);

   const int LIST_SIZE = 5;
   Entity ** data;
   generateDataAndPopulateList(data, a, LIST_SIZE, true);

   EXPECT_TRUE(a->toFirst());
   cout << "Iterating from first to last." << endl;
   for (int i = 0; !a->isTail(); i++ + a->toNext()) {
      cout << "  node[" << i << "] contains: " << *a->currentEntity() << endl;
      EXPECT_EQ(data[i], a->currentEntity());
      EXPECT_TRUE(data[i] == a->currentEntity());
      verifyNonEmptyStateCoherence_notTail(*a, LIST_SIZE);
   }
   verifyNonEmptyStateCoherence_tail(*a, LIST_SIZE);

   cout << "Iterating from last to first." << endl;
   for (int i = (LIST_SIZE - 1); a->toPrev(); i--) {
      cout << "  node[" << i << "] contains: " << *a->currentEntity() << endl;
      EXPECT_EQ(data[i], a->currentEntity());
      EXPECT_TRUE(data[i]->compareKeyTo(*a->currentEntity()) == 0);
      verifyNonEmptyStateCoherence_notTail(*a, LIST_SIZE);
   }
   EXPECT_TRUE(a->isFirst());
   verifyNonEmptyStateCoherence_notTail(*a, LIST_SIZE);

   cout << "Extracting from first to last." << endl;
   int index = 0;
   do {
      Entity *e = a->extractCurrentEntity();
      cout << "  extracted " << *e << endl;
      cout << "    " << a << endl;
      EXPECT_EQ(data[index], e);
      EXPECT_TRUE(data[index]->compareKeyTo(*e) == 0);
      if (index < (LIST_SIZE - 1)) {
         verifyNonEmptyStateCoherence_notTail(*a, LIST_SIZE - index - 1);
      } else {
         verifyEmptyStateCoherence(*a);
      }
      index++;
   } while (!a->isTail());

   cout << "Repopulating same list with extracted Entities" << endl;
   cout << "  " << a << endl;
   for (int i = 0; i < LIST_SIZE; i++) {
      a->insertBefore(data[i]); // should work the same as append() in this case
      cout << "  After insertBefore() " << *data[i] << endl;
      cout << "    " << a << endl;
      verifyNonEmptyStateCoherence_tail(*a, i + 1);
   }

   cout << "Deleting from first to last." << endl;
   index = 0;
   a->toFirst();
   do {
      EXPECT_EQ(data[index], a->currentEntity());
      EXPECT_TRUE(a->deleteCurrent());
      cout << "  deleteCurrent()" << endl;
      cout << "    " << a << endl;
      if (index < (LIST_SIZE - 1)) {
         verifyNonEmptyStateCoherence_notTail(*a, LIST_SIZE - index - 1);
      } else {
         verifyEmptyStateCoherence(*a);
      }
      index++;
   } while (!a->isTail());

   delete a;
   delete data;
}

} // namespace container_test
