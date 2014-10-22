/*! \file sortedlist_test.cpp
 *  \brief Definitions for class container_test::SortedList_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/sortedlist_test.cpp $
 *  $Date: 2009-06-15 17:17:40 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 415 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: sortedlist_test.cpp
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

#include "sortedlist_test.h"

using namespace container;

namespace container_test {

SortedList_test::SortedList_test() {
   string joe = "Joe";
   string smith = "Smith";
   string jane = "Jane";
   string fred = "Fred";
   string harris = "Harris";
   string jose = "Jose";
   string gonzales = "Gonzales";
   string fernanda = "Fernanda";
   string mijares = "Mijares";
   joeSmith = new Person(joe, smith);
   janeSmith = new Person(jane, smith);
   fredHarris = new Person(fred, harris);
   joseGonzales = new Person(jose, gonzales);
   fernandaMijares = new Person(fernanda, mijares);

   unsortedGroup.add(joeSmith);
   unsortedGroup.add(janeSmith);
   unsortedGroup.add(fredHarris);
   unsortedGroup.add(joseGonzales);
   unsortedGroup.add(fernandaMijares);

   sortedGroup.add(joseGonzales);
   sortedGroup.add(fredHarris);
   sortedGroup.add(fernandaMijares);
   sortedGroup.add(janeSmith);
   sortedGroup.add(joeSmith);

   otherJoeSmith = new Person(joe, smith);
   otherJaneSmith = new Person(jane, smith);
   otherFredHarris = new Person(fred, harris);
   otherJoseGonzales = new Person(jose, gonzales);
   otherFernandaMijares = new Person(fernanda, mijares);

   otherUnsortedGroup.add(otherJoeSmith);
   otherUnsortedGroup.add(otherJaneSmith);
   otherUnsortedGroup.add(otherFredHarris);
   otherUnsortedGroup.add(otherJoseGonzales);
   otherUnsortedGroup.add(otherFernandaMijares);

   otherSortedGroup.add(otherJoseGonzales);
   otherSortedGroup.add(otherFredHarris);
   otherSortedGroup.add(otherFernandaMijares);
   otherSortedGroup.add(otherJaneSmith);
   otherSortedGroup.add(otherJoeSmith);
}

SortedList_test::~SortedList_test() {
   // You can do clean-up work that doesn't throw exceptions here.
   while (sortedGroup.toFirst()) {
      sortedGroup.extractCurrentEntity();
   }
   while (otherSortedGroup.toFirst()) {
      otherSortedGroup.extractCurrentEntity();
   }
}

/******************** Unit-test Helper Methods ********************/

/********************  Unit-test methods for class SortedList ********************/

void SortedList_test::insertSorted(const Object::Info* type) {
   SortedList *a = sortedListFactory(type);
   cout << "Starting with an empty " << type->typeName << ":" << endl;
   cout << "  " << a << endl;
   int i = 0;
   for (unsortedGroup.toFirst(); !unsortedGroup.isTail(); unsortedGroup.toNext()) {
      cout << "  Adding " << unsortedGroup.currentEntity()->getKeyAsString();
      EXPECT_TRUE(a->insertSorted(unsortedGroup.currentEntity()));
      i++;
      cout << "; result: " << a << endl;
      verifyNonEmptyStateCoherence_tail(a, i);

      // Verify that all added Person objects can be located and that ones
      // yet to be added cannot be located.
      for (int j = 0; j < unsortedGroup.getCount(); j++) {
         Entity* e1 = unsortedGroup.entityAt(j);
         Entity* oe1 = otherUnsortedGroup.entityAt(j);
         // The content of otherUnsortedGroup should match unsortedGroup but
         // should contain unique instances.
         EXPECT_NE(e1, oe1);
         EXPECT_EQ(e1->getKeyAsString(), oe1->getKeyAsString());
         EXPECT_TRUE(e1->compareKeyTo(*oe1) == 0);

         int index;
         Entity* e2;
         if ((i % 2) == 0) {
            // locate by the same Entity instance
            a->locateEntity(*e1, index, e2);
         } else {
            // locate by a different Entity instance with matching key
            a->locateEntity(*oe1, index, e2);
         }
         if (j < i) {
            EXPECT_NE(List::NO_MATCHING_ENTITY_INDEX_FLAG, index);
            EXPECT_EQ(e1, e2);
            EXPECT_NE(e1, oe1);
            EXPECT_TRUE(e1->compareKeyTo(*e2) == 0);
            EXPECT_TRUE(oe1->compareKeyTo(*e2) == 0);
            EXPECT_EQ(e1, a->entityAt(index));

            // verify that duplicates are rejected
            cout << "    Attempting to add duplicate e1 " << e1->getKeyAsString() << endl;
            cout << "      a->insertSorted(e1) returns: " << (a->insertSorted(e1) ? "true" : "false") << endl;
            cout << "      a->getCount() returns: " << a->getCount() << endl;
            EXPECT_FALSE(a->insertSorted(e1));
            verifyNonEmptyStateCoherence_tail(a, i);
            EXPECT_FALSE(a->insertSorted(oe1));
            verifyNonEmptyStateCoherence_tail(a, i);
         } else {
            EXPECT_EQ(List::NO_MATCHING_ENTITY_INDEX_FLAG, index);
            EXPECT_TRUE(e2 == NULL);
         }
      }
   }

   cout << "Checking for expected sorted order." << endl;
   i = 0;
   for (a->toFirst(); !a->isTail(); a->toNext()) {
      Entity* e1 = sortedGroup.entityAt(i);
      Entity* oe1 = otherSortedGroup.entityAt(i);
      Entity* e2 = a->currentEntity();
      cout << "   [" << i << "]expected: " << e1 << endl;
      cout << "        actual: " << e2 << endl;
      EXPECT_EQ(e1, e2);
      EXPECT_NE(e1, oe1);
      EXPECT_TRUE(e1->compareKeyTo(*e2) == 0);
      EXPECT_TRUE(oe1->compareKeyTo(*e2) == 0);
      i++;
   }

   while (a->toFirst()) {
      a->extractCurrentEntity();
   }

   delete a;
}

void SortedList_test::insertingAndRemoving(const Object::Info* type) {
   SortedList* a = sortedListFactory(type);
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
      a->insertSorted(data[i]);
      cout << "  After insertSorted() " << *data[i] << endl;
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
