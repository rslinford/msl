/*! \file object.cpp
 *  \brief Definitions for classes container::Object and container::Object::Info
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/object.cpp $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: object.cpp
 * File creator:       slinford
 * Created on:         April 12, 2009, 10:34 PM
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

#include "object.h"

using std::string;

namespace container {

/*********************  class Object *********************/

const Object::Info * const Object::TYPE_INFO = Object::typeInfoFactory("Object");

Object::Object() { }

Object::Object(const Object& orig) { }

Object::~Object() { }

/*********************  Object Methods (public) *********************/

ostream & Object::renderState(ostream& os) const {
   // Casting 'this' to (const void*) prevents an infinite loop.
   return os << typeInfo()->typeName << " this(" << ((const void*)this) << ")";
}

const Object::Info* Object::typeInfo() const {
   return TYPE_INFO;
}

/*********************  Object Methods (protected) *********************/

const Object::Info* Object::typeInfoFactory(const string& typeName) {
   return new Info(typeName);
}

/*********************  Object Friends *********************/

ostream & operator <<(ostream& os, const Object& object) {
   if (&object == NULL)
      // At this point there doesn't seem to be anyway to determine the
      // type of reference that was null.
      return os << "NULL";
   else
      return object.renderState(os);
}

ostream & operator <<(ostream& os, const Object* object) {
   if (object == NULL)
      // At this point there doesn't seem to be anyway to determine the
      // type of reference that was null.
      return os << "NULL";
   else
      return object->renderState(os);
}

/********************* Nested class Object::Info *********************/

const Object::Info * const Object::Info::TYPE_INFO = Object::typeInfoFactory("Object::Info");

Object::Info::Info(const string& type_Name): typeName(type_Name) { }

Object::Info::Info(): typeName(NULL) {
   /* not used */
   std::cerr << "Warning: Object::Info::Info() should not be used." << std::endl;
}

Object::Info::Info(const Object::Info& pattern): typeName(NULL) {
   /* not used */
   std::cerr << "Warning: Object::Info::Info(const Object::Info& pattern) should not be used."
         << std::endl;
}

Object::Info::~Info() {
   /* not used */
   std::cerr << "Warning: Object::Info::~Info() should not be used." << std::endl;
}

/*********************  Object Methods (public) *********************/

const Object::Info* Object::Info::typeInfo() const {
   return Object::Info::TYPE_INFO;
}

ostream& Object::Info::renderState(ostream& os) const {
   return os << Object::Info::TYPE_INFO->typeName << " typeName(" << typeName << ')';
}

Object* Object::Info::clone(bool deepCopy) const {
   std::cerr << "Cloning an " << TYPE_INFO->typeName << " is not allowed." << std::endl;
   return NULL;
}

} // namespace container
