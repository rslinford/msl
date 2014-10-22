/*! \file person.h
 *  \brief Header file for class container_test::Person
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/person.h $
 *  $Date: 2009-06-16 22:02:56 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 420 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: person.h
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

#ifndef _PERSON_H
#define _PERSON_H

#include "entity.h"

using namespace container;
using namespace std;

namespace container_test {

/*!
 * \brief A type of Entity that represents a person
 *
 * Person is used to test SortedLinkedList and also provides an example
 * of how to create a sub-class of Entity. The Person class' implementation of
 * compareKeyTo results in an alphabetical sort order by last name, using
 * the first name as a tie breaker.
 */
class Person: public Entity {
public:

   const static Info* const TYPE_INFO;

private:

   string firstName;
   string lastName;

   Person();

public:

   Person(string firstName, string lastName);
   Person(const Person& orig);
   virtual ~Person();

   /*********************  Person Methods (public) *********************/

   string getFirstName();
   void setFirstName(string name);

   string getLastName();
   void setLastName(string name);

   /*********************  Entity Methods (public) *********************/

   virtual int compareKeyTo(const Entity& second) const;

protected:

   /*********************  Entity Methods (protected) *********************/

   virtual string* generateKeyAsString() const;

public:

   /*********************  Object Methods (public) *********************/

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const;

};

} // namespace container_test
#endif /* _PERSON_H */
