/*! \file stackimpl.cpp
 *  \brief Definitions for class container::StackImpl
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/stackimpl.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: stackimpl.cpp
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

#include "stackimpl.h"
#include "orderedlinkedlist.h"
#include "orderedarraylist.h"

namespace container {

const Object::Info * const StackImpl::TYPE_INFO =
      Object::typeInfoFactory("StackImpl");

StackImpl::StackImpl(OrderedList * lst): list(lst) { }

StackImpl::StackImpl(const StackImpl& orig): list(orig.list) { }

StackImpl::~StackImpl() {
   delete list;
}

/*********************  StackImpl Methods (protected) *********************/

void StackImpl::push_impl(Entity* entity) {
   list->append(entity);
}

Entity * StackImpl::pop_impl() {
   if (list->toLast()) {
      return list->extractCurrentEntity();
   } else {
      return NULL;
   }
}

/*********************  StackImpl Methods (public) *********************/

Stack* StackImpl::factoryLinkedComposition() {
   return new StackImpl(new OrderedLinkedList());
}

Stack* StackImpl::factoryArrayComposition() {
   return new StackImpl(new OrderedArrayList());
}

/*********************  Object Methods (public) *********************/

ostream & StackImpl::renderState(ostream& os) const {

   this->Stack::renderState(os);
   os << " composed with an " << list->typeInfo()->typeName << " contents{";

   int i = 0;
   for (list->toTail(); list->toPrev(); i++) {
      os << std::endl << "      [" << i << ']' << list->currentEntity();
      if (list->getCount() > 1) {
         if (list->isFirst()) {
            os << " <--BOTTOM";
         } else if (list->isLast()) {
            os << " <--TOP";
         }
      }
   }
   return os << "}";
}

const Object::Info* StackImpl::typeInfo() const {
   return TYPE_INFO;
}

Object* StackImpl::clone(bool deepCopy) const {
   
}

} // namespace container
