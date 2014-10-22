/*! \file queueimpl_test.cpp
 *  \brief Definitions for class container_test::QueueImpl_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/queueimpl_test.cpp $
 *  $Date: 2009-06-16 22:02:56 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 420 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: queueimpl_test.cpp
 * File creator:       slinford
 * Created on:         June 13, 2009, 3:20 PM
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

#include "queueimpl.h"
#include "person.h"
#include "orderedarraylist.h"
#include <gtest.h>

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief Unit tests for QueueImpl
 */
class QueueImpl_test: public testing::Test {
protected:

   OrderedList* testData;

   // You can remove any or all of the following functions if its body
   // is empty.

   QueueImpl_test() {
      // You can do set-up work for each test here.

      testData = new OrderedArrayList(10, 5);
      testData->append(new Person("George", "Washington"));
      testData->append(new Person("John", "Adams"));
      testData->append(new Person("Thomas", "Jefferson"));
      testData->append(new Person("James", "Madison"));
      testData->append(new Person("James", "Monroe"));
      testData->append(new Person("John Quincy", "Adams"));
      testData->append(new Person("Andrew", "Jackson"));
      testData->append(new Person("Marin", "Van Buren"));
      testData->append(new Person("William Henry", "Harrison"));
      testData->append(new Person("John", "Tyler"));
   }

   virtual ~QueueImpl_test() {
      // You can do clean-up work that doesn't throw exceptions here.

      delete testData;
   }

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

   void verifyQueueCoherence(Queue* q, const int count = 0) {
      EXPECT_TRUE(count >= 0);
      EXPECT_TRUE(q->getCount() >= 0);
      EXPECT_EQ(count, q->getCount());
      if (count == 0) {
         EXPECT_TRUE(q->isEmpty());
         EXPECT_TRUE(q->dequeue() == NULL);
      } else {
         EXPECT_FALSE(q->isEmpty());
      }

      OrderedList* list = new OrderedArrayList();
      int n = count;
      while (!q->isEmpty()) {
         Entity* e = q->dequeue();
         EXPECT_TRUE(e != NULL);
         list->append(e);
         n--;
         EXPECT_EQ(q->getCount(), n);
      }

      EXPECT_TRUE(q->getCount() == 0);
      EXPECT_TRUE(q->isEmpty());
      EXPECT_TRUE(q->dequeue() == NULL);

      for (int i = 0; i < list->getCount(); i++) {
         q->enqueue(list->entityAt(i));
      }

      EXPECT_EQ(q->getCount(), count);

      while (list->toFirst()) {
         list->extractCurrentEntity();
      }
      delete list;
   }

   void startingEmpty(Queue* q) {
      cout << "Starting with an empty queue:" << endl;
      cout << "    " << q << endl;
      EXPECT_EQ(0, q->getCount());
      verifyQueueCoherence(q, 0);
   }

   void enqueueDequeueTest(Queue* q) {
      startingEmpty(q);

      for (int i = 0; i < testData->getCount(); i++) {
         cout << "  adding " << testData->entityAt(i) << endl;
         q->enqueue(testData->entityAt(i));
         cout << "    " << q << endl;
         verifyQueueCoherence(q, i + 1);
      }

      cout << "Dequeueing items one by one:" << endl;
      for (int i = 0; i < testData->getCount(); i++) {
         Entity* e = q->dequeue();
         EXPECT_EQ(testData->entityAt(i), e);
         cout << "   [" << i << "]expected " << testData->entityAt(i) << endl;
         cout << "        actual " << e << endl;
         verifyQueueCoherence(q, testData->getCount() - i - 1);
      }

      cout << "Ending with an empty queue:" << endl;
      cout << "    " << q << endl;

      delete q;
   }

   /*!
    * \brief Copy #testData and add copy to \a q
    *
    * Helper method.
    */
   void firstTenPresidents(Queue* q) {
      for (int i = 0; i < testData->getCount(); i++) {

         Entity* e = testData->entityAt(i);
         Person* p = dynamic_cast<Person*>(e);

         // use copy constructor
         Person* pCopy = new Person(*p);
         q->enqueue(pCopy);
      }
   }

   void purgeContentsTest(Queue* q) {
      startingEmpty(q);

      cout << "Purging an empty queue:" << endl;
      int n = q->purgeContents();
      cout << "   deleted " << n << " items" << endl;
      EXPECT_EQ(0, n);
      verifyQueueCoherence(q, 0);

      cout << "Populating queue with first " << testData->getCount() <<
            " presidents:" << endl;
      firstTenPresidents(q);
      cout << "  " << q << endl;
      verifyQueueCoherence(q, testData->getCount());

      cout << "Purging:" << endl;
      n = q->purgeContents();
      cout << "    deleted " << n << " items" << endl;
      cout << "  " << q << endl;
      EXPECT_EQ(testData->getCount(), n);
      verifyQueueCoherence(q, 0);

      delete q;
   }

   void verifyEquivalence(Queue* orig, Queue* copy, bool deepCopy) {
      cout << "  orig->typeInfo():" << endl;
      cout << "     original " << orig->typeInfo() << endl;
      cout << "         copy " << copy->typeInfo() << endl;
      EXPECT_EQ(orig->typeInfo(), copy->typeInfo());
      cout << "  getCount():" << endl;
      cout << "     original " << orig->getCount() << endl;
      cout << "         copy " << copy->getCount() << endl;
      EXPECT_EQ(orig->getCount(), copy->getCount());
      cout << "  isEmpty():" << endl;
      cout << "     original " << orig->isEmpty() << endl;
      cout << "         copy " << copy->isEmpty() << endl;
      EXPECT_EQ(orig->isEmpty(), copy->isEmpty());
      if (deepCopy) {
         cout << "  Deep copy should create new, independent People objects:" << endl;
      } else {
         cout << "  Shallow copy should share the same People objects:" << endl;
      }
      for (int i = 0; i < orig->getCount(); i++) {
         Person* op = dynamic_cast<Person*>(orig->dequeue());
         Person* cp = dynamic_cast<Person*>(copy->dequeue());
         orig->enqueue(op);
         copy->enqueue(cp);
         cout << "    [" << i << "]" << endl;
         cout << "        original pointer value " << ((void*)op) << endl;
         cout << "            copy pointer value " << ((void*)cp) << endl;
         op->setFirstName(op->getFirstName().append(" Albert"));
         if (deepCopy) {
            EXPECT_NE(op, cp);
            cout << "      Change to one won't affect the other:" << endl;
            EXPECT_NE(op->getFirstName(), cp->getFirstName());
         } else {
            EXPECT_EQ(op, cp);
            cout << "      Change to one will affect the other:" << endl;
            EXPECT_EQ(op->getFirstName(), cp->getFirstName());
         }
         cout << "       original " << op << endl;
         cout << "           copy " << cp << endl;
      }

   }

   void shallowVersusDeepTest(Queue* q) {
      firstTenPresidents(q);
      cout << "Starting with " << testData->getCount() << " People:" << endl;
      cout << "    " << q << endl;
      verifyQueueCoherence(q, testData->getCount());
      cout << "Creating shallow copy:" << endl;
      Queue* qCopy = dynamic_cast<Queue*>(q->clone(false));
      cout << "    " << qCopy << endl;
      verifyQueueCoherence(qCopy, testData->getCount());
      verifyEquivalence(q, qCopy, false);

      while (!qCopy->isEmpty()) {
         qCopy->dequeue();
      }
      verifyQueueCoherence(qCopy, 0);
      delete qCopy;
      verifyQueueCoherence(q, testData->getCount());

      cout << "Creating deep copy:" << endl;
      qCopy = dynamic_cast<Queue*>(q->clone(true));
      cout << "    " << qCopy << endl;
      verifyQueueCoherence(qCopy, testData->getCount());
      verifyEquivalence(q, qCopy, true);

      delete q;
      verifyQueueCoherence(qCopy, testData->getCount());
      delete qCopy;
   }

};

TEST_F(QueueImpl_test, factories) {

   cout << "Factory creation of a queue composed with an underlying linked list" << endl;
   Queue* qLinked = QueueImpl::factoryLinkedComposition();
   EXPECT_EQ(QueueImpl::TYPE_INFO, qLinked->typeInfo());
   cout << "   " << qLinked << endl;

   cout << "Factory creation of a queue composed with an underlying array list" << endl;
   Queue* qArray = QueueImpl::factoryArrayComposition();
   EXPECT_EQ(QueueImpl::TYPE_INFO, qArray->typeInfo());
   cout << "   " << qArray << endl;

   verifyQueueCoherence(qLinked);
   verifyQueueCoherence(qArray);

   Person* p = new Person("Herman", "Melville");

   qLinked->enqueue(p);
   qArray->enqueue(p);

   cout << "Both queues loaded with the same Person object" << endl;
   cout << "   " << qLinked << endl;
   cout << "   " << qArray << endl;

   verifyQueueCoherence(qLinked, 1);
   verifyQueueCoherence(qArray, 1);

   Entity* p2 = qLinked->dequeue();
   Entity* p3 = qArray->dequeue();

   EXPECT_EQ(p, p2);
   EXPECT_EQ(p, p3);

   cout << "Both with the Person dequeued" << endl;
   cout << "   " << qLinked << endl;
   cout << "   " << qArray << endl;

   verifyQueueCoherence(qLinked);
   verifyQueueCoherence(qArray);

   delete p;
   delete qLinked;
   delete qArray;
}

TEST_F(QueueImpl_test, enqueueDequeueLinked) {
   enqueueDequeueTest(QueueImpl::factoryLinkedComposition());
}

TEST_F(QueueImpl_test, enqueueDequeueArray) {
   enqueueDequeueTest(QueueImpl::factoryArrayComposition());
}

TEST_F(QueueImpl_test, purgeContentsLinked) {
   purgeContentsTest(QueueImpl::factoryLinkedComposition());
}

TEST_F(QueueImpl_test, purgeContentsArray) {
   purgeContentsTest(QueueImpl::factoryArrayComposition());
}

TEST_F(QueueImpl_test, shallowVersusDeepArray) {
   shallowVersusDeepTest(QueueImpl::factoryArrayComposition());
}

} // namespace container_end
