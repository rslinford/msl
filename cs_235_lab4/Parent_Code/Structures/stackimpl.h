/*! \file stackimpl.h
 *  \brief Header file for class container::StackImpl
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/stackimpl.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: stackimpl.h
 * File creator:       slinford
 * Created on:         June 15, 2009, 2:28 PM
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

#ifndef _STACKIMPL_H
#define _STACKIMPL_H

#include "stack.h"
#include "orderedlist.h"

using std::string;

namespace container {

/*!
 * \brief An implementation of Stack that based on an OrderedList
 */
class StackImpl: public Stack {
public:

   const static Info * const TYPE_INFO;

private:
   OrderedList * const list;

   StackImpl(OrderedList* list);

public:

   StackImpl(const StackImpl& orig);

   virtual ~StackImpl();

   /*********************  StackImpl Methods (public) *********************/

protected:

   /*********************  StackImpl Methods (protected) *********************/

   virtual void push_impl(Entity* entity);

   virtual Entity * pop_impl();

public:

   /*********************  StackImpl Methods (public) *********************/

   /*!
    * \brief Constructs an StackImpl with an underlying OrderedLinkedList
    */
   static Stack* factoryLinkedComposition();

   /*!
    * \brief Constructs a StackImpl with an underlying OrderedArrayList
    */
   static Stack* factoryArrayComposition();

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const;

};

} // namespace container
#endif /* _STACKIMPL_H */
