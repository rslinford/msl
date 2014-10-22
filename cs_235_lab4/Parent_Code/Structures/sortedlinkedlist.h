/*! \file sortedlinkedlist.h
 *  \brief Header file for class container::SortedLinkedList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/sortedlinkedlist.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: sortedlinkedlist.h
 * File creator:       slinford
 * Created on:         April 11, 2009, 6:23 PM
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

#ifndef _SORTEDLINKEDLIST_H
#define _SORTEDLINKEDLIST_H

#include "sortedlist.h"
#include "linkedlist.h"

using std::ostream;

namespace container {

/*!
 *  \brief A linked list implementation of SortedList
 */
class SortedLinkedList: public SortedList, public LinkedList {
public:

   const static Info* const TYPE_INFO;

   SortedLinkedList();
   SortedLinkedList(const SortedLinkedList& pattern);
   virtual ~SortedLinkedList();

protected:

   /*********************  SortedList Methods (protected) *********************/

   virtual bool insertSorted_impl(Entity* entity);

   /*********************  List Methods (protected) *********************/

   virtual bool add_impl(Entity* entity);

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const;

};

} // namespace container
#endif /* _SORTEDLINKEDLIST_H */
