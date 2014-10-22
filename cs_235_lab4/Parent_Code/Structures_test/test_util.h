/*! \file test_util.h
 * \brief Utility functions for testing containers. Part of namespace
 * container_test.
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures_test/test_util.h $
 *  $Date: 2009-06-15 12:26:32 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 411 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: test_util.h
 * File creator:       slinford
 * Created on:         April 11, 2009, 9:22 PM
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

#ifndef _TEST_UTIL_H
#define _TEST_UTIL_H

#include "orderedlinkedlist.h"
#include "orderedarraylist.h"
#include "sortedlinkedlist.h"
#include "sortedarraylist.h"

using namespace container;

/*!
 * \brief Unit tests for the #container namespace based on the googletest
 * framework
 */
namespace container_test {

/*!
 * \brief Create one of the known concrete classes ultimately derived from
 * container::List
 */
List* listFactory(const Object::Info* type);

/*!
 * \brief Create one of the known concrete classes derived from
 * container::OrderedList
 */
OrderedList* orderedListFactory(const Object::Info* type);

/*!
 * \brief Create one of the known concrete classes derived from
 * container::SortedList
 */
SortedList* sortedListFactory(const Object::Info* type);

} // namespace container_test
#endif /* _TEST_UTIL_H */
