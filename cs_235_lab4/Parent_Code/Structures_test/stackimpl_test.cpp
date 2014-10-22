/*! \file stackimpl_test.cpp
 *  \brief Definitions for class container_test::StackImpl_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/stackimpl_test.cpp $
 *  $Date: 2009-06-15 17:18:47 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 417 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: stackimpl_test.cpp
 * File creator:       slinford
 * Created on:         June 15, 2009, 3:54 PM
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

#include "stackimpl.h"
#include "person.h"
#include "orderedarraylist.h"
#include <gtest.h>

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief Unit tests for StackImpl
 */
class StackImpl_test: public testing::Test {
protected:

   OrderedList* testData;

   // You can remove any or all of the following functions if its body
   // is empty.

   StackImpl_test() {
      // You can do set-up work for each test here.

      testData = new OrderedArrayList(10, 5);
      testData->append(new Person("Marie", "Curie"));
      testData->append(new Person("Max", "Planck"));
      testData->append(new Person("Albert", "Einstein"));
      testData->append(new Person("Niels", "Bohr"));
      testData->append(new Person("Enrico", "Fermi"));
      testData->append(new Person("Ernest", "Lawrence"));
      testData->append(new Person("Richard", "Feynman"));
      testData->append(new Person("Arno Allan", "Penzias"));
      testData->append(new Person("Gerd", "Binnig"));
      testData->append(new Person("Steven", "Chu"));
   }

   virtual ~StackImpl_test() {
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

   void verifyStackCoherence(Stack* s, const int count = 0) {
      EXPECT_TRUE(count >= 0);
      EXPECT_TRUE(s->getCount() >= 0);
      EXPECT_EQ(s->getCount(), count);
      if (count == 0) {
         EXPECT_TRUE(s->isEmpty());
         EXPECT_TRUE(s->pop() == NULL);
      } else {
         EXPECT_FALSE(s->isEmpty());
      }

      OrderedList* list = new OrderedArrayList();
      int n = count;
      while (!s->isEmpty()) {
         Entity* e = s->pop();
         EXPECT_TRUE(e != NULL);
         list->append(e);
         n--;
         EXPECT_EQ(s->getCount(), n);
      }

      EXPECT_TRUE(s->getCount() == 0);
      EXPECT_TRUE(s->isEmpty());
      EXPECT_TRUE(s->pop() == NULL);

      while (list->toLast()) {
         s->push(list->extractCurrentEntity());
      }

      EXPECT_EQ(s->getCount(), count);

      delete list;
   }

   void startingEmpty(Stack* s) {
      cout << "Starting with an empty stack:" << endl;
      cout << "    " << s << endl;
      EXPECT_EQ(0, s->getCount());
      verifyStackCoherence(s, 0);
   }

   void pushPopTest(Stack* s) {
      startingEmpty(s);

      for (int i = 0; i < testData->getCount(); i++) {
         cout << "  adding " << testData->entityAt(i) << endl;
         s->push(testData->entityAt(i));
         cout << "    " << s << endl;
         verifyStackCoherence(s, i + 1);
      }

      cout << "Poping items one by one:" << endl;
      for (int i = 0; i < testData->getCount(); i++) {
         Entity* e = s->pop();
         int expectedIndex = testData->getCount() - i - 1;
         EXPECT_EQ(testData->entityAt(expectedIndex), e);
         cout << "   [" << i << "]expected " <<
            testData->entityAt(expectedIndex) << endl;
         cout << "        actual " << e << endl;
         verifyStackCoherence(s, expectedIndex);
      }

      cout << "Ending with an empty stack:" << endl;
      cout << "    " << s << endl;

      delete s;
   }

   /*!
    * \brief Copy #testData and add copy to \a s
    *
    * Helper method.
    */
   void tenPhysicists(Stack* s) {
      for (int i = 0; i < testData->getCount(); i++) {

         Entity* e = testData->entityAt(i);
         Person* p = dynamic_cast<Person*>(e);

         // use copy constructor
         Person* pCopy = new Person(*p);
         s->push(pCopy);
      }
   }

   void purgeContentsTest(Stack* s) {
      startingEmpty(s);

      cout << "Purging an empty stack:" << endl;
      int n = s->purgeContents();
      cout << "   deleted " << n << " items" << endl;
      EXPECT_EQ(0, n);
      verifyStackCoherence(s, 0);

      cout << "Populating stack with " << testData->getCount() <<
            " physicists:" << endl;
      tenPhysicists(s);
      cout << "  " << s << endl;
      verifyStackCoherence(s, testData->getCount());

      cout << "Purging:" << endl;
      n = s->purgeContents();
      cout << "    deleted " << n << " items" << endl;
      cout << "  " << s << endl;
      EXPECT_EQ(testData->getCount(), n);
      verifyStackCoherence(s, 0);

      delete s;
   }

};

TEST_F(StackImpl_test, factories) {

   cout << "Factory creation of a stack composed with an underlying linked list" << endl;
   Stack* sLinked = StackImpl::factoryLinkedComposition();
   EXPECT_EQ(StackImpl::TYPE_INFO, sLinked->typeInfo());
   cout << "   " << sLinked << endl;

   cout << "Factory creation of a stack composed with an underlying array list" << endl;
   Stack* sArray = StackImpl::factoryArrayComposition();
   EXPECT_EQ(StackImpl::TYPE_INFO, sArray->typeInfo());
   cout << "   " << sArray << endl;

   verifyStackCoherence(sLinked);
   verifyStackCoherence(sArray);

   Person* p = new Person("Leo", "Tolstoy");

   sLinked->push(p);
   sArray->push(p);

   cout << "Both stacks loaded with the same Person object" << endl;
   cout << "   " << sLinked << endl;
   cout << "   " << sArray << endl;

   verifyStackCoherence(sLinked, 1);
   verifyStackCoherence(sArray, 1);

   Entity* p2 = sLinked->pop();
   Entity* p3 = sArray->pop();

   EXPECT_EQ(p, p2);
   EXPECT_EQ(p, p3);

   cout << "Both with the Person popped" << endl;
   cout << "   " << sLinked << endl;
   cout << "   " << sArray << endl;

   verifyStackCoherence(sLinked);
   verifyStackCoherence(sArray);

   delete p;
   delete sLinked;
   delete sArray;
}

TEST_F(StackImpl_test, pushPopLinked) {
   pushPopTest(StackImpl::factoryLinkedComposition());
}

TEST_F(StackImpl_test, pushPopArray) {
   pushPopTest(StackImpl::factoryArrayComposition());
}

TEST_F(StackImpl_test, purgeContentsLinked) {
   purgeContentsTest(StackImpl::factoryLinkedComposition());
}

TEST_F(StackImpl_test, purgeContentsArray) {
   purgeContentsTest(StackImpl::factoryArrayComposition());
}

} // namespace container_end
