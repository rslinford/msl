/*! \file container.cpp
 * \brief Definitions for class container::Container
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/container.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: container.cpp
 *   File creator:       slinford
 *   Created on:         March 30, 2009, 11:28 PM
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

#include "container.h"

namespace container {

const Object::Info * const Container::TYPE_INFO = Object::typeInfoFactory("Container");

Container::Container(): count(0) { }

Container::Container(const Container& orig): count(orig.count) { }

Container::~Container() { }

/*********************  Container Methods (public) *********************/

int Container::getCount() const {
   return count;
}

bool Container::isEmpty() const {
   return getCount() == 0;
}

/*********************  Container Methods (protected) *********************/

void Container::setCount(int c) {
   count = c;
}

void Container::incCount() {
   count++;
}

void Container::decCount() {
   count--;
}

/*********************  Object Methods (public) *********************/

ostream & Container::renderState(ostream& os) const {
   return os << typeInfo()->typeName << " count(" << count << ')';
}

const Object::Info* Container::typeInfo() const {
   return TYPE_INFO;
}

} // namespace container
