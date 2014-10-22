/*! \file list.h
 * \brief Header file for class container::List
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/list.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: list.h
 *   File creator:       slinford
 *   Created on:         March 30, 2009, 11:39 PM
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

#ifndef _LIST_H
#define _LIST_H

#include "container.h"

using std::string;

namespace container {

/*!
 * \brief Abstract base class for all list containers
 *
 * May allow duplicates. Derived classes may choose to disallow duplicates.
 */
class List: public Container {
public:

   const static Info * const TYPE_INFO;

   /*!
    * \brief Returned as an index value by method locateEntity() when a matching
    * entity was not found in the list.
    */
   const static int NO_MATCHING_ENTITY_INDEX_FLAG;

protected:

   List();
   List(const List& orig);

public:

   virtual ~List();

   /*********************  List Methods (public) *********************/

   /*!
    * \brief Add an Entity to the list
    *
    * This is the default method for adding an Entity object to a List. Derived
    * classes determine the exact behavior: where in the list it will be
    * added, whether duplicates are allowed, etc. As with all methods that
    * add items to a Container, no copy of the Entity is made. The Container
    * takes responsibility to delete the Entity.
    *
    * \return true if the Entity was added; otherwise false
    *
    * \post If true is returned then the Entity is in the List and the Container's
    * #count is greater by one.
    * \post If false is returned then the List's state is unchanged
    * \post In either case (a return value of true or false) the list cursor
    * will remain unchanged. It will not be pointing to the new Entity.
    */
   bool add(Entity* entity);

   /*!
    * \brief Remove the current Entity from the list and delete it from memory
    *
    * \return true if an Entity was removed. false if the cursor was
    * not pointing to an Entity.
    *
    * \pre The list is not empty
    * \pre The list cursor points an Entity
    * \post The Entity indicated by the cursor is no longer in the list
    * \post The Entity indicated by the cursor is deleted from memory
    * \post The cursor points to the next Entity in the list or to the tail
    * of the list if the deleted Entity was last
    */
   bool deleteCurrent();

   /*!
    * \brief Remove the current Entity from the list and return a pointer
    * to it.
    *
    * The caller becomes responsible for disposing of the Entity. If successful,
    * the list cursor ends up pointing the next Entity in the list.
    *
    * \return A pointer to the extracted Entity. NULL if the list was empty or
    * if the cursor was not pointing to an Entity.
    *
    * \pre The list cursor points to the Entity to be extracted
    * \post The Entity (formerly the current Entity) is not in the list
    * \post The caller is responsible for deleting the extracted Entity
    * \post The list cursor points to the next Entity in the list or to the
    * tail of the list if the extracted Entity was last
    */
   Entity * extractCurrentEntity();

   /*!
    * \brief Return true if the cursor is pointing to first real node, false
    * otherwise.
    *
    * TRUE is only possible if the list is not empty.
    */
   virtual bool isFirst() const = 0;

   /*!
    * \brief Determine whether the list cursor is pointing to the last Entity
    *
    * true is only possible if the list is not empty.
    *
    * \return true if the list cursor is pointing to the last Entity of the list,
    * false otherwise
    */
   virtual bool isLast() const = 0;

   /*!
    * \brief Return true if the cursor is pointing to the list tail, false
    * otherwise
    *
    * false is only possible if the list is not empty.
    */
   virtual bool isTail() const = 0;

   /*!
    * \brief Point the cursor to the first Entity in the list
    *
    * \return false if the list is empty; otherwise, true. A value of true
    * doesn't imply that the cursor was moved, i.e., it may have already been
    * pointing to the first Entity.
    *
    * \pre The list is not empty
    * \post The list cursor points to the first Entity in the list
    */
   virtual bool toFirst() = 0;

   /*!
    * \brief Point the cursor to the last Entity in the list
    *
    * \return false if the list is empty; otherwise, true. A value of true
    * doesn't imply that the cursor was moved, i.e., it may have already been
    * pointing to the last Entity.
    *
    * \pre The list is not empty
    * \post The list cursor points to the last Entity in the list
    */
   virtual bool toLast() = 0;

   /*!
    * \brief Point the cursor to the tail of the list
    *
    * This method should always succeed. A List should always have the concept
    * a tail, i.e., the node or element just beyond the end of the list. No
    * Entity is available at the tail cursor position.
    *
    * \pre A List has been constructed
    * \post The list cursor points to the tail
    */
   virtual void toTail() = 0;

   /*!
    * \brief Point the cursor to the next Entity in the list
    *
    * \return true if the list cursor was moved and points to an Entity
    * \return false if the cursor was moved to the tail of list
    * \return false if the cursor was already pointing to the tail
    *
    * \pre The List is not empty
    * \pre The list cursor is not pointing to the tail
    * \post The list cursor has moved to the next Entity or to the tail if it
    * was pointing to the last Entity
    */
   virtual bool toNext() = 0;

   /*!
    * \brief Point the cursor to the previous Entity in the list
    *
    * Calling toPrev() never leaves the cursor pointing to the head of the list.
    *
    * \return true if the list cursor was moved
    * \return false if the cursor is already pointing the first Entity in the
    * list
    * \return false if the list is empty
    *
    * \pre The list is not empty
    * \pre The list cursor is not pointing to the first Entity in the list
    * \post The list cursor has moved to the previous Entity
    */
   virtual bool toPrev() = 0;

   /*!
    * \brief Return a pointer to the current Entity
    *
    * \return A pointer to the current Entity object. Returns NULL if the list
    * was empty or if the cursor was not pointing to an Entity.
    *
    * \pre The list cursor points to an Entity
    * \post The current Entity remains in the list
    * \post The state of the List is unchanged
    */
   virtual Entity * currentEntity() = 0;

   /*!
    * \brief Locate the first Entity that matches the specified key.
    *
    * The position is returned as a zero based index. The first Entity that
    * matches is returned. No further checking of the list is performed.
    *
    * \return The zero based \a index of the matching Entity. If a matching Entity
    * is not found List::NO_MATCHING_ENTITY_INDEX_FLAG is returned in \a index
    * instead.
    * \return \a entity will point to the matching Entity. If a matching Entity
    * is not found, NULL is returned in \a entity instead.
    *
    * \pre A matching Entity is in the list
    * \post The state of the list is unchanged including the cursor position
    */
   virtual void locateEntity(const Entity &key, int &index, Entity* &entity) = 0;

   /*!
    * \brief Return a pointer to the Entity found at the specified, zero-based
    * index.
    *
    * \return A pointer to the Entity at the specified index
    *
    * \pre The List must contain at least one Entity object.
    * \pre A valid \a index must be specified. For example, if #count
    * is 1 then the only valid \a index is 0.
    * \post The state of the list is unchanged including the cursor position
    */
   virtual Entity* entityAt(int index) = 0;

protected:

   /*********************  List Methods (protected) *********************/

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in List::deleteCurrent
    */
   virtual bool deleteCurrent_impl() = 0;

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in List::extractCurrentEntity
    */
   virtual Entity * extractCurrentEntity_impl() = 0;

   /*!
    * \brief Called by a template method
    *
    * \see Details documented in List::add
    */
   virtual bool add_impl(Entity* entity) = 0;

public:

   /*********************  Container Methods (public) *********************/

   int purgeContents();

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const = 0;

};

} // namespace container
#endif /* _LIST_H */
