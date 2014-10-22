/*! \file entity.cpp
 * \brief Definitions for class container::Entity
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/entity.cpp $
 *  $Date: 2009-06-16 22:02:57 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 421 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: entity.cpp
 *   File creator:       slinford
 *   Created on:         March 22, 2009, 4:29 PM
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

#include "entity.h"
#include "util.h"

using std::string;

namespace container {

const Object::Info * const Entity::TYPE_INFO = Object::typeInfoFactory("Entity");

const int Entity::COMPARE_KEY_TO_NULL_RVAL = -1;

int Entity::nextDefaultKey = 0;

Entity::Entity(): defaultKey(nextDefaultKey++), keyAsString(NULL) { }

Entity::Entity(int key): defaultKey(key), keyAsString(NULL) { }

Entity::Entity(const Entity& pattern): defaultKey(pattern.defaultKey) {
   if (pattern.keyAsString == NULL) {
      this->keyAsString = NULL;
   } else {
      this->keyAsString = new string(*(pattern.keyAsString));
   }
}

Entity::~Entity() {
   if (keyAsString != NULL) {
      delete keyAsString;
   }
}

Entity& Entity::operator=(const Entity& second) {
   if (this != &second) { // make sure not same object
      defaultKey = second.defaultKey;
      // delete allocated item(s)
      if (keyAsString != NULL) {
         delete keyAsString;
      }

      if (second.keyAsString == NULL) {
         keyAsString = NULL;
      } else {
         keyAsString = new string(*(second.keyAsString));
      }
   }

   return *this; // Return ref for multiple assignment
}

/*********************  Entity Methods (public) *********************/

int Entity::compareKeyTo(const Entity& second) const {
   if (&second == NULL) {
      return COMPARE_KEY_TO_NULL_RVAL;
   }
   return defaultKey - second.defaultKey;
}

const string& Entity::getKeyAsString() const {
   if (keyAsString == NULL) {
      keyAsString = generateKeyAsString();
   }
   return *keyAsString;
}

/*********************  Entity Methods (protected) *********************/

inline int Entity::getDefaultKey() {
   return defaultKey;
}

void Entity::invalidateKeyAsString() {
   keyAsString = NULL;
}

string* Entity::generateKeyAsString() const {
   return new string(util::toString(defaultKey));
}

/*********************  Object Methods (public) *********************/

ostream & Entity::renderState(ostream& os) const {
   if (Entity::TYPE_INFO == this->typeInfo()) {
      return os << typeInfo()->typeName << " defaultKey(" << defaultKey << ") keyAsString(" +
            ((keyAsString == NULL) ? "NULL" : *(keyAsString)) << ")";
   } else {
      return os << typeInfo()->typeName << "(" << getKeyAsString() << ")";
   }
}

const Object::Info* Entity::typeInfo() const {
   return TYPE_INFO;
}

Object* Entity::clone(bool deepCopy) const {
   return new Entity(*this);
}

} // namespace container
