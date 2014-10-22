/*! \file person.cpp
 *  \brief Definitions for class container_test::Person
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/person.cpp $
 *  $Date: 2009-06-16 22:02:56 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 420 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: person.cpp
 * File creator:       slinford
 * Created on:         April 28, 2009, 5:19 PM
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

#include "person.h"

namespace container_test {

const Object::Info * const Person::TYPE_INFO = Object::typeInfoFactory("Person");

Person::Person() { }

Person::Person(string first_Name, string last_Name): firstName(first_Name),
lastName(last_Name) { }

Person::Person(const Person& orig): Entity(orig), firstName(orig.firstName),
lastName(orig.lastName) { }

Person::~Person() { }

/*********************  Person Methods (public) *********************/

string Person::getFirstName() {
   return firstName;
}

void Person::setFirstName(string name) {
   firstName = name;
   invalidateKeyAsString();
}

string Person::getLastName() {
   return lastName;
}

void Person::setLastName(string name) {
   lastName = name;
   invalidateKeyAsString();
}

/*********************  Entity Methods (public) *********************/

int Person::compareKeyTo(const Entity& second) const {
   if (&second == NULL) {
      return COMPARE_KEY_TO_NULL_RVAL;
   }

   int delta = typeInfo()->typeName.compare(second.typeInfo()->typeName);
   if (delta != 0) {
      return delta;
   }

   const Person& p2 = (Person&)second;
   delta = lastName.compare(p2.lastName);
   if (delta != 0) {
      return delta;
   }

   return firstName.compare(p2.firstName);
}

/*********************  Entity Methods (protected) *********************/

string* Person::generateKeyAsString() const {
   return new string(firstName + " " + lastName);
}

/*********************  Object Methods (public) *********************/

const Object::Info* Person::typeInfo() const {
   return TYPE_INFO;
}

Object* Person::clone(bool deepCopy) const {
   // Alwasy does a deep copy. 
   return new Person(*this);
}

} // namespace container_test
