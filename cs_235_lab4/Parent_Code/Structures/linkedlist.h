/*! \file linkedlist.h
 * \brief Header file for for classes container::LinkedList and
 * container::LinkedList::Node
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/linkedlist.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: linkedlist.h
 *   File creator:       slinford
 *   Created on:         March 19, 2009, 11:25 PM
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

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "list.h"

using std::ostream;

namespace container {

/*!
 * \brief A mostly complete linked-list implementation of List.
 *
 * Derived directly from List, LinkedList is an abstract class that implements
 * most of List using doubly-linked nodes.
 */
class LinkedList: public virtual List {
public:

   const static Info* const TYPE_INFO;

protected:

   class Node;

   /*!
    * \brief List cursor
    *
    * Points to the current node
    */
   Node* current;

   /*!
    * \brief Dummy node that marks the beginning of the list.
    * 
    * #current never points to head.
    *
    * \todo Considering allowing #current to point to head.
    */
   Node* head;

   /*!
    * \brief Dummy node that marks the end of the list
    * 
    * #current is allowed to point to tail. It does so when the list is
    * empty, when the list has been completely iterated, after toTail() is
    * called, or possibly after toNext() is called.
    */
   Node* tail;

   /*!
    * \brief Creates an empty list.
    *
    * #head and #tail are allocated and pointed to each other. #current is
    * pointed to the tail node.
    */
   LinkedList();

   /*!
    * \brief NOT IMPLEMENTED. Creates a deep copy of the #pattern list.
    *
    * Copies of all nodes and their Entities will are created for the new list.
    *
    * \todo Implement copy constructor
    */
   LinkedList(const LinkedList& pattern);

public:

   /*!
    * \brief Free all memory associated with this list
    *
    * Calls purgeContents(), so all Entity objects in the list will be deleted.
    */
   virtual ~LinkedList();

protected:

   /*********************  LinkedList Methods (protected) *********************/

   /*!
    * /brief Performs the toNext opperation on an arbitrary Node, as opposed
    * to the public toNext() which opperates on the list cursor
    */
   virtual bool toNext(Node*& cursor);

public:

   /*********************  List Methods (public) *********************/

   virtual bool isFirst() const;

   virtual bool isLast() const;

   virtual bool isTail() const;

   virtual bool toFirst();

   virtual bool toLast();

   virtual void toTail();

   virtual bool toNext();

   virtual bool toPrev();

   virtual Entity * currentEntity();

   virtual void locateEntity(const Entity &key, int &index, Entity* &entity);

   virtual Entity* entityAt(int index);

protected:

   /*********************  List Methods (protected) *********************/

   virtual bool deleteCurrent_impl();

   virtual Entity * extractCurrentEntity_impl();

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

//   virtual Object* clone(bool deepCopy = false) const = 0;

};

/********************* Nested class LinkedList::Node *********************/

/*!
 * \brief LinkedList uses Node objects to form a list of Entity objects.
 *
 * Node is doubly linked. It keeps a pointer to its Entity object and expects
 * it to be dynamically allocated. Node takes responsibility for deleting its
 * Entity object during Node destruction.
 *
 * \todo Break node out from LinkedList, or at least provide a .h file. A Node
 * could be used like an iterator. There is some functionality like toNext()
 * and toPrev() that should be encapsulated in Node instead of LinkedList. Node
 * could be re-used as the building block for other linked list type structures.
 */
class LinkedList::Node {
public:

   Node* next;
   Node* prev;
   Entity* entity;

   Node();

   /**
    * \brief Construct a Node for Entity \a e and insert it into the list
    * before Node \a n
    *
    * \pre \a n points to a Node that is part of a correctly formed linked
    * list structure
    * \pre \a e points to an Entity
    * \post The newly constructed Node is in the linked list structure before
    * Node \a n
    */
   Node(Entity *e, Node *n);

   ~Node();

   Entity * extractEntity();

};

} // namespace container
#endif /* _LINKEDLIST_H */
