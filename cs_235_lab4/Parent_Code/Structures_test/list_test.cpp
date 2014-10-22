/*! \file list_test.cpp
 *  \brief Definitions for class container_test::List_test
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/list_test.cpp $
 *  $Date: 2009-06-06 22:09:11 -0400 (Sat, 06 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 374 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: list_test.cpp
 * File creator:       slinford
 * Created on:         April 27, 2009, 5:29 PM
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

#include "list_test.h"

using namespace container;

namespace container_test {

const int List_test::SOME_OTHER_KEY(9998887);
const int List_test::ZERO_INDEX(0);
const int List_test::NEGATIVE_INDEX(-1);
const int List_test::BIG_INDEX(4000);
const int List_test::SOME_OTHER_INDEX(456);
const int List_test::INDEX_NOT_FOUND(-1);
const int List_test::KEY_4(4);
const string List_test::KEY_4_AS_STRING("4");

/********************  Helper Methods ********************/

void List_test::verifyEmptyStateCoherence(List* a) {
   verifyEmptyStateCoherence(*a);
}

void List_test::verifyEmptyStateCoherence(List& a) {
   EXPECT_TRUE(a.isEmpty());
   EXPECT_EQ(0, a.getCount());
   EXPECT_FALSE(a.isFirst());
   EXPECT_FALSE(a.isLast());
   EXPECT_TRUE(a.isTail());
}

void List_test::verifyNonEmptyStateCoherence_tail(List* a, int count) {
   verifyNonEmptyStateCoherence_tail(*a, count);
}

void List_test::verifyNonEmptyStateCoherence_tail(List& a, int count) {
   EXPECT_FALSE(a.isEmpty());
   EXPECT_EQ(count, a.getCount());
   EXPECT_FALSE(a.isFirst());
   EXPECT_FALSE(a.isLast());
   EXPECT_TRUE(a.isTail());
}

void List_test::verifyNonEmptyStateCoherence_notTail(List* a, int count) {
   verifyNonEmptyStateCoherence_notTail(*a, count);
}

void List_test::verifyNonEmptyStateCoherence_notTail(List& a, int count) {
   EXPECT_FALSE(a.isEmpty());
   EXPECT_EQ(count, a.getCount());
   if (count == 1) {
      EXPECT_TRUE(a.isFirst());
      EXPECT_TRUE(a.isLast());
   } else if (count > 1) {
      if (a.isFirst()) EXPECT_FALSE(a.isLast());
      if (a.isLast()) EXPECT_FALSE(a.isFirst());
   }
   EXPECT_FALSE(a.isTail());
}

void List_test::generateDataAndPopulateList(Entity** &data,
                                            List* list,
                                            const int listSize,
                                            bool print) {
   data = new Entity*[listSize];
   if (print) cout << "Populating " << list->typeInfo()->typeName <<
         " with " << listSize << " entities:" << endl;
   if (print) cout << "  " << list << endl;
   for (int i = 0; i < listSize; i++) {
      data[i] = new Entity();
      list->add(data[i]);
      if (print) cout << "After add() " << *data[i] << endl;
      if (print) cout << "  " << list << endl;
      verifyNonEmptyStateCoherence_tail(list, i + 1);
   }
}

/********************  Unit-test methods for class List ********************/

void List_test::defaultConstructor(const Object::Info* type) {

   // Null check, probably not necessary, but I'm just trying to figure
   // out this new framework.
   List* a = listFactory(type);
   List* n = NULL;
   EXPECT_NE(n, a);

   // I'm relearning the language. Just making sure I understand what's
   // going on. a and b should be pointing to two different places.
   List* b = listFactory(type);
   EXPECT_NE(a, b);

   cout << a->typeInfo()->typeName <<
         " default constructor should create empty lists." << endl;
   cout << " a " << *a << endl;
   EXPECT_TRUE(a->isEmpty());
   EXPECT_EQ(0, a->getCount());
   cout << " b " << *b << endl;
   EXPECT_TRUE(b->isEmpty());
   EXPECT_EQ(0, b->getCount());

   cout << "Adding node to " << a->typeInfo()->typeName << " b" << endl;
   b->add(new Entity());
   cout << " b " << *b << endl;
   EXPECT_FALSE(b->isEmpty());
   EXPECT_EQ(1, b->getCount());
   // isFirst is always false when empty
   EXPECT_FALSE(a->isFirst());
   // adding a node should not have changed the cursor possition
   EXPECT_FALSE(b->isFirst());

   // isLast is always false when empty
   EXPECT_FALSE(a->isLast());
   // adding a node should not have changed the cursor possition
   EXPECT_FALSE(b->isFirst());

   // isLast is always false when empty
   EXPECT_TRUE(a->isTail());
   // adding a node should not have changed the cursor possition
   EXPECT_TRUE(b->isTail());

   delete a;
   delete b;
}

void List_test::cursorControl(const Object::Info* type) {

   List* a = listFactory(type);

   // Cursor manipulation with a empty list
   cout << "List a is empty" << endl;
   cout << "  " << a << endl;
   verifyEmptyStateCoherence(a);
   EXPECT_EQ(false, a->toFirst());
   verifyEmptyStateCoherence(a);
   EXPECT_EQ(false, a->toLast());
   verifyEmptyStateCoherence(a);
   EXPECT_EQ(false, a->toNext());
   verifyEmptyStateCoherence(a);
   EXPECT_EQ(false, a->toPrev());
   verifyEmptyStateCoherence(a);
   a->toTail();
   verifyEmptyStateCoherence(a);

   // Cursor manipulation with a list containing a single node
   Entity* e1 = new Entity();
   a->add(e1);
   cout << "List a has one item" << endl;
   cout << "  " << a << endl;
   EXPECT_EQ(true, a->toPrev());
   cout << "After toPrev()" << endl;
   cout << "  " << a << endl;
   verifyNonEmptyStateCoherence_notTail(a, 1);
   cout << "Current node contains: " << a->currentEntity() << endl;
   EXPECT_EQ(e1, a->currentEntity());
   EXPECT_FALSE(a->toPrev());
   verifyNonEmptyStateCoherence_notTail(a, 1);
   EXPECT_FALSE(a->toNext());
   cout << "After toNext()" << endl;
   cout << "  " << a << endl;
   verifyNonEmptyStateCoherence_tail(a, 1);
   EXPECT_TRUE(a->toFirst());
   cout << "After toFirst()" << endl;
   cout << "  " << a << endl;
   verifyNonEmptyStateCoherence_notTail(a, 1);
   a->toTail();
   cout << "After toTail()" << endl;
   cout << "  " << a << endl;
   verifyNonEmptyStateCoherence_tail(a, 1);
   EXPECT_TRUE(a->toLast());
   cout << "After toLast()" << endl;
   cout << "  " << a << endl;
   verifyNonEmptyStateCoherence_notTail(a, 1);

   //Cursor manipulation with a list containing 2 nodes
   EXPECT_TRUE(a->toFirst());
   cout << "After toFirst(), (cursor shouldn't have moved)" << endl;
   cout << "  " << a << endl;
   EXPECT_TRUE(a->isLast());
   cout << "Adding a 2nd item using default add method" << endl;
   Entity* e2 = new Entity();
   a->add(e2);
   cout << "After add(e2), cursor should still point to e1." << endl;
   cout << "  " << a << endl;
   EXPECT_EQ(e1, a->currentEntity());
   EXPECT_TRUE(e1->compareKeyTo(*a->currentEntity()) == 0);

   int indexResult;
   Entity key = *e1;
   Entity* entityResult;
   a->locateEntity(key, indexResult, entityResult);
   EXPECT_EQ(e1, entityResult);
   EXPECT_NE(INDEX_NOT_FOUND, indexResult);

   // Where method add(Entity*) puts the new items is up to the implementing
   // class. Therefore, this generic test cannot know, at compile time,
   // whether the second entity was added first or last.
   if (indexResult == 0) {
      EXPECT_FALSE(a->isLast());
      EXPECT_TRUE(a->isFirst());
   } else {
      EXPECT_TRUE(a->isLast());
      EXPECT_FALSE(a->isFirst());
   }

   List_test::verifyNonEmptyStateCoherence_notTail(a, 2);
   if (indexResult == 0) {
      EXPECT_TRUE(a->toNext());
      cout << "After toNext()" << endl;
      cout << "  " << a << endl;
      verifyNonEmptyStateCoherence_notTail(a, 2);
      EXPECT_FALSE(a->toNext());
      cout << "After 2nd call toNext()" << endl;
      cout << "  " << a << endl;
      verifyNonEmptyStateCoherence_tail(a, 2);
      EXPECT_TRUE(a->toPrev());
      cout << "Last node contains: " << a->currentEntity() << endl;
      EXPECT_EQ(e2, a->currentEntity());
      EXPECT_TRUE(a->toPrev());
      EXPECT_TRUE(a->isFirst());
      cout << "After toPrev()" << endl;
      cout << "  " << a << endl;
      verifyNonEmptyStateCoherence_notTail(a, 2);
      cout << "First node contains: " << a->currentEntity() << endl;
      EXPECT_EQ(e1, a->currentEntity());
      EXPECT_FALSE(a->toPrev());
      cout << "After toPrev()" << endl;
      cout << "  " << a << endl;
      verifyNonEmptyStateCoherence_notTail(a, 2);
   } else {
      EXPECT_TRUE(a->toPrev());
      cout << "After toPrev()" << endl;
      cout << "  " << a << endl;
      EXPECT_FALSE(a->toPrev());
      cout << "After 2nd call toPrev(), (cursor shouldn't have moved)" << endl;
      cout << "  " << a << endl;
      EXPECT_TRUE(a->isFirst());
      verifyNonEmptyStateCoherence_notTail(a, 2);
      cout << "First node contains: " << a->currentEntity() << endl;
      EXPECT_EQ(e2, a->currentEntity());
      EXPECT_TRUE(a->toNext());
      EXPECT_TRUE(a->isLast());
      cout << "After toNext()" << endl;
      cout << "  " << a << endl;
      verifyNonEmptyStateCoherence_notTail(a, 2);
      cout << "Last node contains: " << a->currentEntity() << endl;
      EXPECT_EQ(e1, a->currentEntity());
      EXPECT_FALSE(a->toNext());
      cout << "After toNext()" << endl;
      cout << "  " << a << endl;
      verifyNonEmptyStateCoherence_tail(a, 2);
   }

   delete a;
}

void List_test::purgeConents(const Object::Info* type) {
   const int LIST_SIZE = 100;
   Entity ** data;
   List* a = listFactory(type);
   generateDataAndPopulateList(data, a, LIST_SIZE);
   verifyNonEmptyStateCoherence_tail(a, LIST_SIZE);

   const int SAMPLE_MOD = 10;
   cout << "Created a " << a->typeInfo()->typeName << " with " << LIST_SIZE <<
         " items." << endl;
   cout << "  count(" << a->getCount() << ")" << endl;
   cout << "Vefifying all items. Printing a sample every " <<
         SAMPLE_MOD << " items:" << endl;
   cout << "      Expected Entity                    Container Entity" << endl;
   a->toFirst();
   int index = 0;
   do {
      if ((index % SAMPLE_MOD) == 0) {
         cout << "  [" << index << "] " << data[index] << " == " << a->currentEntity() << endl;
      }
      EXPECT_EQ(data[index], a->currentEntity());
      a->toNext();
      index++;
   } while (!a->isTail());
   EXPECT_EQ(LIST_SIZE, index);
   EXPECT_EQ(LIST_SIZE, a->purgeContents());
   verifyEmptyStateCoherence(a);
   cout << "Called purgeContents()" << endl;
   cout << "  " << a << endl;

   index = 0;
   while (a->toPrev()) index++;
   EXPECT_EQ(0, index);

   Entity e;
   a->add(&e);
   EXPECT_TRUE(a->toPrev());
   verifyNonEmptyStateCoherence_notTail(*a, 1);
   EXPECT_EQ(&e, a->currentEntity());
   EXPECT_TRUE(e.compareKeyTo(*a->extractCurrentEntity()) == 0);
   verifyEmptyStateCoherence(a);

   delete a;
   delete data;
}

void List_test::locateEntity(const Object::Info* type) {
   List* emptyList = listFactory(type);
   cout << "Calling locateEntity on an emtpy " << emptyList->typeInfo()->typeName
         << "." << endl;
   Entity key(KEY_4);
   int index(SOME_OTHER_INDEX);
   EXPECT_EQ(SOME_OTHER_INDEX, index);
   EXPECT_EQ(KEY_4_AS_STRING, key.getKeyAsString());
   Entity *entity = new Entity();
   Entity *entity2 = entity;
   EXPECT_EQ(entity, entity2);
   emptyList->locateEntity(key, index, entity);
   verifyEmptyStateCoherence(emptyList);
   EXPECT_EQ(INDEX_NOT_FOUND, index);
   EXPECT_TRUE(NULL == entity);
   EXPECT_NE(entity2, entity);
   cout << "  returned index(" << index << ") entity(" << entity << ")" << endl;

   List *list = listFactory(type);
   Entity *entity3 = new Entity();
   list->add(entity3);
   const Entity key2 = *entity3;
   cout << "Calling locateEntity on a " << list->typeInfo()->typeName <<
         " with a single item." << endl;
   cout << "  " << *list << ")" << endl;
   cout << "  locating Entity with key(" << key2.getKeyAsString() << ")" << endl;
   index = SOME_OTHER_INDEX;
   entity = NULL;
   verifyNonEmptyStateCoherence_tail(*list, 1);
   list->locateEntity(key2, index, entity);
   verifyNonEmptyStateCoherence_tail(*list, 1);
   EXPECT_EQ(ZERO_INDEX, index);
   EXPECT_EQ(entity3, entity);
   EXPECT_FALSE(entity3 == NULL);
   cout << "  returned index(" << index << ") entity(" << *entity << ")" << endl;

   cout << "Calling locateEntity on the same " << list->typeInfo()->typeName <<
         '.' << endl;
   cout << "  " << *list << ")" << endl;
   cout << "  locating Entity with key(" << SOME_OTHER_KEY << ")" << endl;
   const Entity someOtherKey(SOME_OTHER_KEY);
   index = SOME_OTHER_INDEX;
   entity = entity2;
   verifyNonEmptyStateCoherence_tail(*list, 1);
   list->locateEntity(someOtherKey, index, entity);
   verifyNonEmptyStateCoherence_tail(*list, 1);
   EXPECT_EQ(INDEX_NOT_FOUND, index);
   EXPECT_TRUE(NULL == entity);
   EXPECT_NE(entity2, entity);
   cout << "  returned index(" << index << ") entity(" << entity << ")" << endl;

   delete emptyList;
   delete list;
}

void List_test::entityAt(const Object::Info* type) {
   List* emptyList = listFactory(type);
   cout << "Calling entityAt(" << ZERO_INDEX << ") on an empty " <<
         emptyList->typeInfo()->typeName << '.' << endl;
   Entity *entity = new Entity();
   Entity *entity2 = entity;
   EXPECT_EQ(entity, entity2);
   entity = emptyList->entityAt(ZERO_INDEX);
   verifyEmptyStateCoherence(emptyList);
   EXPECT_TRUE(NULL == entity);
   EXPECT_NE(entity2, entity);
   cout << "  returned entity(" << entity << ")" << endl;

   List *list = listFactory(type);
   Entity *entity3 = new Entity();
   list->add(entity3);
   EXPECT_TRUE(list->toFirst());
   cout << "Calling entityAt(" << ZERO_INDEX << ") on a  " <<
         list->typeInfo()->typeName << " with one item." << endl;
   cout << "  " << *list << endl;
   entity = NULL;
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   entity = list->entityAt(ZERO_INDEX);
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   EXPECT_EQ(entity3, entity);
   EXPECT_FALSE(entity3 == NULL);
   cout << "  returned entity(" << *entity << ")" << endl;

   cout << "Calling entityAt(" << NEGATIVE_INDEX << ") on the same " <<
         list->typeInfo()->typeName << '.' << endl;
   cout << "  " << *list << endl;
   entity = entity2;
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   entity = list->entityAt(NEGATIVE_INDEX);
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   EXPECT_TRUE(NULL == entity);
   EXPECT_NE(entity2, entity);
   cout << "  returned entity(" << entity << ")" << endl;

   cout << "Calling entityAt(" << BIG_INDEX << ") on the same " <<
         list->typeInfo()->typeName << '.' << endl;
   cout << "  " << *list << endl;
   entity = entity2;
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   entity = list->entityAt(BIG_INDEX);
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   EXPECT_TRUE(NULL == entity);
   EXPECT_NE(entity2, entity);
   cout << "  returned entity(" << entity << ")" << endl;

   cout << "Calling entityAt(" << list->getCount() << ") on the same " <<
         list->typeInfo()->typeName << '.' << endl;
   cout << "  " << *list << endl;
   entity = entity2;
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   entity = list->entityAt(list->getCount());
   verifyNonEmptyStateCoherence_notTail(*list, 1);
   EXPECT_TRUE(NULL == entity);
   EXPECT_NE(entity2, entity);
   cout << "  returned entity(" << entity << ")" << endl;

   delete emptyList;
   delete list;
}

} // namespace container_test
