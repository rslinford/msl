/*! \file orderedlinkedlist.h
 *  \brief Header file for class container::OrderedLinkedList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/orderedlinkedlist.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: orderedlinkedlist.h
 * File creator:       slinford
 * Created on:         April 11, 2009, 11:18 PM
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

#ifndef _ORDEREDLINKEDLIST_H
#define _ORDEREDLINKEDLIST_H

#include "linkedlist.h"
#include "orderedlist.h"

using std::ostream;

namespace container {

/*!
 *  \brief A linked list implementation of OrderedList
 */
class OrderedLinkedList: public OrderedList, public LinkedList {
public:

   const static Info * const TYPE_INFO;

   OrderedLinkedList();
   OrderedLinkedList(const OrderedLinkedList& orig);
   virtual ~OrderedLinkedList();

protected:

   /*********************  OrderedList Methods (protected) *********************/

   virtual void append_impl(Entity* entity);

   virtual void insertBefore_impl(Entity* entity);

   /*********************  List Methods  (protected) *********************/

   virtual bool add_impl(Entity* entity);

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const;

};

} // namespace container
#endif /* _ORDEREDLINKEDLIST_H */
