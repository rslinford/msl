/*! \file entity_test.cpp
 * \brief Definitions for class container_test::Entity_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/entity_test.cpp $
 *  $Date: 2009-05-02 15:46:43 -0400 (Sat, 02 May 2009) $
 *  $Author: slinford $
 *  $Revision: 347 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: entity_test.cpp
 *   File creator:       slinford
 *   Created on:         March 22, 2009, 6:06 PM
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

#include "entity.h"
#include <gtest.h>

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief Unit tests for Entity
 */
class Entity_test: public testing::Test {
protected:
   // You can remove any or all of the following functions if its body
   // is empty.

   Entity_test() {
      // You can do set-up work for each test here.
   }

   virtual ~Entity_test() {
      // You can do clean-up work that doesn't throw exceptions here.
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

   void foo(Entity x) {
      cout << "In pass by value foo(x)" << endl;
      cout << "  x " << x << endl;
   }

   void copyConstructorTestCore(Entity& b) {
      Entity* a = NULL;

      // Execute copy constructor explicitly.
      cout << "Before copy constructor a = new Entity(b)" << endl;
      cout << "       a is NULL" << endl;
      cout << "       b " << b << endl;
      a = new Entity(b);
      cout << "After  a " << *a << endl;

      EXPECT_TRUE(a->compareKeyTo(b) == 0);

      // a and b should be independent objects. Again, testing my understanding.
      EXPECT_NE(a, &b);

      // keyAsString members should be independent objects
      EXPECT_NE(&(a->getKeyAsString()), &(b.getKeyAsString()));

      delete a;
   }

   void assignmentOperatorTestCore(Entity& a, Entity& b) {
      // Invoke assignment method.
      cout << "Before assignment a = b" << endl;
      cout << "       a " << a << endl;
      cout << "       b " << b << endl;
      a = b;
      cout << "After  a " << a << endl;
      EXPECT_TRUE(a.compareKeyTo(b) == 0);

      // a and b should be independent objects. Again, testing my understanding.
      EXPECT_NE(&a, &b);

      // keyAsString members should be independent objects
      EXPECT_NE(&(a.getKeyAsString()), &(b.getKeyAsString()));
   }

};

TEST_F(Entity_test, DefaultConstructor) {

   // Null check, probably not necessary, but I'm just trying to figure
   // out this new framework.
   Entity* a = new Entity();
   Entity* n = NULL;
   EXPECT_NE(n, a);

   // I'm relearning the language. Just making sure I understand what's
   // going on. a and b should be pointing to two different places.
   Entity* b = new Entity();
   EXPECT_NE(a, b);

   // A real test. Each Entity should have a unique key.
   cout << "Constructor should assign a unique key automatically" << endl;
   cout << "a " << *a << endl;
   cout << "b " << *b << endl;
   EXPECT_FALSE(a->compareKeyTo(*b) == 0);

   Entity c;
   Entity d;

   // Testing my understanding if C++ again. I think the default constructor
   // is called automatically for c an d.
   cout << "c " << c << endl;
   cout << "d " << d << endl;
   EXPECT_FALSE(c.compareKeyTo(d) == 0);

   delete a;
   delete b;
}

TEST_F(Entity_test, AssignmentOperator) {
   Entity a;
   Entity b;
   assignmentOperatorTestCore(a, b);

   Entity c;
   Entity d;
   c.getKeyAsString(); // force member keyAsString to lazy initialize
   assignmentOperatorTestCore(c, d);

   Entity e;
   Entity f;
   f.getKeyAsString(); // force member keyAsString to lazy initialize
   assignmentOperatorTestCore(e, f);

   Entity g;
   Entity h;
   g.getKeyAsString(); // force member keyAsString to lazy initialize
   h.getKeyAsString(); // force member keyAsString to lazy initialize
   assignmentOperatorTestCore(g, h);
}

TEST_F(Entity_test, CopyConstructor) {
   Entity b;
   copyConstructorTestCore(b);

   Entity c;
   c.getKeyAsString(); // force member keyAsString to lazy initialize
   copyConstructorTestCore(c);
}

} // namespace container_end
