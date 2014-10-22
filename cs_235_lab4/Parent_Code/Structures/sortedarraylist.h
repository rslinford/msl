/*! \file sortedarraylist.h
 *  \brief Header file for class container::SortedArrayList
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/sortedarraylist.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: sortedarraylist.h
 * File creator:       slinford
 * Created on:         May 9, 2009, 6:50 PM
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

#ifndef _SORTEDARRAYLIST_H
#define _SORTEDARRAYLIST_H

#include "sortedlist.h"
#include "arraylist.h"

using std::ostream;

namespace container {

/*!
 *  \brief An array implementation of SortedList
 */
class SortedArrayList: public SortedList, public ArrayList {
public:

   const static Info * const TYPE_INFO;

   SortedArrayList();
   SortedArrayList(const SortedArrayList& pattern);
   virtual ~SortedArrayList();

private:

   /*********************  SortedArrayList Methods (private) *********************/

   /*!
    * \brief Locate the Entity with the matching \a key using a binary search
    * algorithm
    *
    * \return true if found, false other wise
    * \return \a index will point to the Entity if found, otherwise \a index
    * will point to where the \a key belongs if the corresponding Entity object
    * were to be inserted
    */
   bool binarySearch(const Entity &key, int& index) const;

protected:

   /*********************  SortedList Methods (protected) *********************/

   virtual bool insertSorted_impl(Entity* entity);

   /*********************  List Methods (public) *********************/

   /*!
    * \brief Uses a binary search to locate the Entity object with the given \a key
    *
    * Overrides the implementation in ArrayList. Uses a binary search for
    * optimization.
    *
    * \see List::locateEntity for method contract
    */
   virtual void locateEntity(const Entity &key, int &index, Entity* &entity);

   /*********************  List Methods (protected) *********************/

   virtual bool add_impl(Entity* entity);

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const;

};

} // namespace container

#endif /* _SORTEDARRAYLIST_H */
