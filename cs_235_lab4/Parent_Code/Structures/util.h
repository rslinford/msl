/*! \file util.h
 * \brief General utility functions from namespace util
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/util.h $
 *  $Date: 2009-06-15 12:26:36 -0400 (Mon, 15 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 412 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: util.h
 *   File creator:       slinford
 *   Created on:         March 23, 2009, 7:00 PM
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

#ifndef _UTIL_H
#define	_UTIL_H

#include <sstream>

/*!
 * \brief General utilities
 */
namespace util {

/*! \brief Converts an object into a new its string representation.
 * 
 * Uses the standard class stringstream. The objects type T must provide an
 * implementation of the canonical << method:
 *
 *    std::ostream & operator <<(std::ostream& os, const T& t)
 *
 * where T is a real type.
 */
template <typename T> inline std::string toString(const T& t) {
   std::stringstream ss;
   ss << t;
   return ss.str();
}

} // namespace util
#endif /* _UTIL_H */
