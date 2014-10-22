/*! \file object.h
 *  \brief Header file for classes container::Object and container::Object::Info
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/object.h $
 *  $Date: 2009-06-16 20:52:47 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 418 $
 *
 * \section original File Creation
 * <pre>
 * Original file name: object.h
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

#ifndef _OBJECT_H
#define _OBJECT_H

#include <iostream>

using std::ostream;
using std::string;

namespace container {

/*!
 * \brief The root for most classes in the container namespace
 *
 * Provides polymorphic behavior for rendering the state of an object. Default
 * rendering is provided which prints "Object" followed by its memory address,
 * i.e., the value of the 'this' pointer.
 *
 * For customized output, objects may override Object::renderState(ostream&)const and
 * Object::typeInfo(). One or both may be implemented. If, for example,
 * a derived class does not have any state, it should at least override 
 * Object::typeInfo() so that it doesn't print as "Object".
 * 
 * Overriding these two methods takes the place of the standard pattern of 
 * creating a friend method for operator <<(ostream&, ...) in each class, with
 * the advantage that references and pointers of a base-class type will produce
 * output specific for the derived class. For example:
 * <pre>
 *    OrderedLinkedList* x = new OrderedLinkedList();
 *    Entity * y = new Entity();
 *    x->add(y);
 *    Object* obj1 = x;
 *    Object* obj2 = y;
 *    cout << "[" << obj2 << "] is in [" << obj1 << "]";
 * </pre>
 * Produces the following output
 * <pre>
 *    [Entity key(114) keyAsString(NULL)] is in [OrderedLinkedList count(1)
 *       cursor->TAIL contents{[0]Entity key(114) keyAsString(NULL)}]
 * </pre>
 */
class Object {
public:

   class Info;

   const static Info * const TYPE_INFO;

protected:

   Object();
   Object(const Object& orig);

public:

   virtual ~Object();


   /*********************  Object Methods (public) *********************/

   /**
    * \brief Write the state of an Object for debugging and demonstration
    *
    * This method must not change the state of an Object; adding or removing
    * debug statements should not change the behavior of a class. The
    * implementation must be robust, e.g., NULL safe, etc. and work without
    * an unrecoverable error for any state, excluding an Object's time of
    * construction and destruction. It is not required for the implementation
    * to be thread safe.
    *
    * \pre The Object has been fully constructed and is not in the process
    * of destruction
    * \post The state of the Object is unchanged
    */
   virtual ostream& renderState(ostream& os) const;

   /*!
    * \brief Return the instance of Object::Info that describes the class of
    * \a this object
    *
    * Instantiation of Object::Info is controlled by the protected method
    * Object::typeInfoFactory(const string&). Each sub-class of Object should
    * create one and only one instance of Object::Info.
    */
   virtual const Info* typeInfo() const;

   /*!
    * \brief A polymorphic copy constructor
    */
   virtual Object* clone(bool deepCopy = false) const = 0;

protected:

   /*********************  Object Methods (protected) *********************/

   /*!
    * \brief Create an instance of Object::Info
    *
    * Each sub-class of Object should create one and only one instance of
    * Object::Info.
    */
   static const Info* typeInfoFactory(const string& typeName);

public:

   /*********************  Object Friends *********************/

   /*!
    * \brief Render the state of \a object as text
    *
    * Polymorphic behavior is achieved by calling Object::renderState(ostream&) 
    * on \a object. Parameter \a object is a reference type and
    * Object::renderState(ostream&) is a virtual method; therefore, a
    * polymorphic determination is made as to which Object::renderState(ostream&)
    * method to call. The determination is made at runtime (not compile time),
    * and the winning candidate will be the method furthest down the inheritance
    * chain with a matching signature.
    *
    * This only works when an object is referred to by a pointer or by a reference.
    */
   friend ostream & operator <<(ostream& os, const Object& object);

   /*!
    * \brief Render the state of \a object as text
    *
    * Polymorphic behavior is achieved by calling Object::renderState(ostream&) on
    * \a object. Parameter \a object is a pointer type and Object::renderState(ostream&)
    * is a virtual method; therefore, a polymorphic determination is made as to
    * which Object::renderState(ostream&) method to call. The determination is made at
    * runtime (not compile time), and the winning candidate will be the method
    * furthest down the inheritance chain with a matching signature.
    *
    * This only works when an object is referred to by a pointer or by a reference.
    */
   friend ostream & operator <<(ostream& os, const Object* object);

};

/********************* Nested class Object::Info *********************/

/*!
 * \brief Metadata that describes type Object or a descendant there of
 *
 * Instantiation of Object::Info is controlled by the protected method
 * Object::typeInfoFactory(const string&). Each sub-classes of Object should
 * create one and only one instance of Object::Info.
 */
class Object::Info: public Object {
public:

   const static Info * const TYPE_INFO;

   const string typeName;

private:

   /*!
    * \brief The only constructor that is used to create instances of Info.
    *
    * Only Object::typeInfoFacotry is granted access.
    */
   Info(const string& type_Name);

   /*!
    * \brief Constructor not used
    */
   Info();

   /*!
    * \brief Constructor not used
    */
   Info(const Info& orig);

public:

   /*!
    * \brief Destructor not used
    * 
    * Destructor is private which prevents Object::Info from being inherited.
    */
   virtual ~Info();

   /*********************  Object Methods (public) *********************/

   virtual ostream & renderState(ostream& os) const;

   /*!
    * \brief Return the instance of Object::Info that describes its own class
    */
   virtual const Info* typeInfo() const;

private:
   /*!
    * \brief Hidded so that Object::Info items cannot be cloned
    */
   virtual Object* clone(bool deepCopy = false) const;

public:

   /*********************  Object::Info Friends *********************/

   /*!
    * \brief Grant class Object the ability to create instances of
    * Object::Info
    *
    * Class Object::Info is publically available for reference by clients of the
    * container framework; however, all constructors are private. Method 
    * Object::typeInfoFactory(const string&) is granted the right to create
    * instances, and it is a protected member of class Object. Sub-classes are
    * expected to make one and only one instance of class Object::Info (a static
    * member) to describe themselves.
    */
   friend const Info* Object::typeInfoFactory(const string& typeName);
};

} // namespace container
#endif/* _OBJECT_H */
