/*! \file container.h
 *  \brief Header file for class container::Container
 *
 * \section svn Source Control
 *
 *  $URL: http://tablet-001/svn/DWC/CS217/trunk/Structures/container.h $
 *  $Date: 2009-06-16 23:12:25 -0400 (Tue, 16 Jun 2009) $
 *  $Author: slinford $
 *  $Revision: 422 $
 *
 * \section original File Creation
 * <pre>
 *   Original file name: container.h
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

#ifndef _CONTAINER_H
#define	_CONTAINER_H

#include "entity.h"

using std::ostream;

/*!
 * \brief Object oriented data structure framework
 */
namespace container {
   
/*!
 * \mainpage CS-217 Data Structures and Algorithms I
 *
 * \section student Student
 * R. Scott Linford
 *
 * \section intro Introduction
 * This package contains an object oriented framework of data structures. In
 * its last delivery it looked like:
 * 
 * \image html original_class_hierarchy.png "Beginning Class Hierarchy"
 *
 * LinkedList was the only working structure. It had a base class called
 * OrderedList. Several other classes were stubbed in and formed the beginning
 * of a class hierarchy with Container as the one common super-class.
 *
 * The hierarchy has grown. Most of the classes in the package extend Object.
 *
 * \image html final_class_hierarchy.png "Final Class Hierarchy"
 *
 * The Object super-class was originally created to generate output in a
 * polymorphic manner. I'm used to Java in which all classes ultimately
 * derive from a common super-class.
 *
 * All of the data structures are unbounded, including the array implementations
 * which expand as needed. All structures use dynamic allocation.
 *
 * Two doubly-linked lists are implemented, one that maintains a sorted order and
 * one that doesn't. The SortedLinkedList does not except duplicates and
 * the OrderedLinekList does. The common functionality to both linked lists
 * resides in the abstract class LinkedList. As the diagram shows, multiple
 * inheritance is in use.
 *
 * Two array based lists are implemented, following the same pattern as the
 * linked lists. Most of the common functionality between the two concrete
 * classes resides in ArrayList. The SortedArrayList makes use of binary
 * searching for retrieval and for insertion.
 *
 * The Queue and Stack implementation can be composed with either a
 * OrderedArrayList or and OrderedLinkedList, using the factory methods
 * provided. QueueImpl contains functionality that demonstrates the difference
 * between deep and shallow copying.
 *
 * Unit tests have been refactored to take advantage of the polymorphic
 * nature of the framework. As shown in the above diagram, for example, all list
 * classes have a common parent called List (oddly enough). There is a unit
 * test called container_test::List_test that enforces the List contract for all
 * known sub-classes.
 *
 * \image html list_unit_test_hierarchy.png "Final Class Hierarchy"
 *
 * The unit tests became invaluable during the extensive refactoring. They
 * caught a lot of bugs, and allowed me to make implementation chages
 * with confidence. All I needed to see were the green lines at the
 * bottom of the output I knew that the method contracts were still
 * satisfied.
 *
 * \section design Project Considerations
 * \subsection opportunity Dusting Off the Old Skills
 * First of all, I haven't done any serious C++ work for 15 years. So this is
 * a good excuse for me to relearn the language and research the new features
 * and coding standards which have evolved during my absence. C++ templates give
 * me a headache but I'll find some way to use them.
 *
 * \subsection oo A Rough OO Outline
 * Second, I want to end up with an OO hierarchy of classes. From experience,
 * I know how hard OO design is to do right. First guesses are always wrong.
 * It usually requires an iterative process to discover abstractions and pull
 * them up into a super class. I haven't started from scratch, however, having
 * taken inspiration from the Java collections framework and other sources.
 *
 * \subsection flexibility More Rope
 * Third, Java is an insidious language in its simplicity. All primitive types
 * are passed by value and all user-created types are passed by reference. In
 * Java there's no such thing as a struct residing on the call stack. Instead,
 * the stack only has references to dynamically allocated objects on the heap.
 * Now I'm back to C++ which has too many choices, all this flexibility, i.e.,
 * (rope to hang myself with).
 *
 * So, coming from a Java frame of mind, Container classes will not make copies
 * of the Entity objects stored within them. Only copies of pointer values will
 * be made when an Entity is added. The Container classes will take responsibility
 * of deleting any Entity objects they have a reference to at the
 * time of Container destruction.
 *
 * \section output Functionality Demonstration
 * Output for demonstration is weaved into the unit tests.
 *
 * \image html unit_test_output.png "Sample Output"
 *
 * The unit test output starts with green text (or red for a failure). All the
 * other lines were added to demonstrate that something is actually happening.
 * The test cases are too verbose to easily capture in a screen shot. Here is
 * the full text of the current output:
 *
 * <a href="../Engineering/artifacts/unit_test_output_4-6-2009.txt">LinkedList
 * and Entity - Unit Test Output</a>
 *
 * The unit tests verify and assert more than is being reported in the print
 * statements. For example, two methods from LinkedList_test generated the
 * above output:
 *
 * \image html linkedlist_example_test_code.png
 *
 * Normally, unit tests aren't designed for human eyes. They either
 * pass or fail, much like code compilation which either succeeds or fails.
 *
 * Well written unit tests do not require print statements. When they fail, the
 * output is designed to be sufficient to trace the problem to its source. The
 * googletest framework is good in this respect. Upon failure, it prints line
 * numbers, expected values, actual values, etc, that make print statements
 * superfluous in a real development environment.
 *
 * \section env Development Environment
 * \subsection automation I Want My IDE Back
 * Coming from a Java background, I've attempted to replicate the features
 * found in IDE's like Eclipse and NetBeans. Long ago I had done C and C++
 * from the command line using tools like vi, make, etc. But now I'm spoiled.
 * I've grown accustomed to code completion, incremental compilation, dependable
 * refactoring tools, and other productivity aids.
 *
 * For example, with NetBeans you can create a Hello World program with a few
 * clicks and then run it by pressing the big green arrow. This is true for
 * a simple console application, a GUI desktop application, a web application,
 * etc. For a web application, it fires up the web server for you a and pops open
 * a browser running the new code, all with the friendly green arrow. Just
 * press play.
 * 
 * Unit tests are just as easy, right out of the box. Select the class to be
 * tested and NetBeans generates a JUnit class with a stub for each method. All
 * you have to do is fill in the stubs. Unit tests can be run with a click of
 * the mouse and become a natural part of the build process.
 *
 * \subsection svn Code Repository
 * Another requirement I set for my environment was to continue using
 * Subversion as my code repository. NetBeans integrates with Subversion. The
 * files shown in blue (container.h and Doxyfile) have been locally modified:
 *
 * \image html project_trees.png
 * 
 * I started using Subversion for CS-114. Access to source code is served up via
 * HTTP from my laptop computer. I have a development environment at home and at
 * work, which serves as protection against loss and forces me to check in code
 * frequently. In doing so, I have a full history of my project since its inception,
 * with useful check-in comments about what was changed any why.
 *
 * \image html sample_history_for_linkedlist_h.png
 *
 * The NetBeans integration allows for each line to be traced back to the
 * responsible developer and the revision where the line was last changed. This
 * is not a special read-only view. The following shot is of "live" editable
 * code:
 *
 * \image html annotated_code_userid_and_version.png "Annotated Code With UserID and Version Number"
 *
 * I experimented with Microsoft's Visual Studio. It has decent code refactoring
 * but there is no built in support for Subversion. Agent SVN looks like a nice
 * plug-in, but $95.95 was not in the budget.
 *
 * \subsection netbeans NetBeans and C++?
 * So after additional research I decided to stick with NetBeans which has a
 * C++ plug-in (crazy). NetBeans becomes a shell for the standard GNU set of
 * tools (gcc, g++, gdb, make, etc.) which have been ported to Cygwin (a
 * Unix-like environment for Windows).
 *
 * It took me a long time to get NetBeans to compile and run a simple program,
 * partly because it has been so long since I have had to worry about include
 * files, linking, and other concerns that either don't exist in Java or are
 * taken care of by the toolset. Yes, I know, I've grown soft. The first linking
 * error really took me back to the old days, "Oh yeah, these. My favorite."
 *
 * \subsection googletest Unit Test Framework
 * Then I went in search of a C++ unit-test framework and found that there isn't
 * a de facto standard like JUnit is for the Java world. I settled on googletest
 * because it has the ability to auto-discover unit tests. I downloaded the
 * googletest source code and built it under Cygwin. With scanty documentation
 * it took some time to figure out how to set it up.
 *
 * I ended up with two NetBeans projects. "Structures" for the actual code and
 * "Structures_test" for the unit tests. The source code in "Structures" has no
 * dependency on the unit tests. It compiles down to a library called
 * "libstructures.a" (no executable).
 *
 * Project "Structures_test" has a build dependency on "Structures". So with a
 * click of a button all files are compiled, linked, and unit tests are
 * executed. The magic is performed by Google's "gtest_main.a" which has a main
 * function that does the work of finding and executing all unit tests.
 *
 * \subsection doxygen Automatic API Documentation
 * Then I had to have automatic documentation. I'm spoiled, remember? In
 * NetBeans (yes, you guessed it) you click a menu and the Javadoc shows up
 * in a browser. For this project I'm learning Doxygen. To automate the process
 * I added a new target to the Makefile that NetBeans generated. My make utility
 * skills were very rusty.
 *
 * \section works Sources and Other Inspiration
 * I started the class without the textbook. It took longer than expected to
 * arrive. I turned to other sources, including Java's collection framework
 * which I have used for years.
 *
 * I also came across an online text book, "Data Structures and Algorithms
 * with Object-Oriented Design Patterns in C++", by Bruno R. Preiss. It has
 * snippets of code but the source is not available.
 *
 * - Opus5 (the Java version of the textbook)
 *   - Java version of the text.
 *   - Includes Javadoc of Preiss' data structure framework
 *   - Javadoc:
 *     - http://www.brpreiss.com/books/opus5/javadoc/index.html
 *   - Java source snippets:
 *     - http://www.brpreiss.com/books/opus5/programs/index.html
 * - Opus4 (the C++ version of the textbook)
 *   - C++ textbook:
 *     - http://www.brpreiss.com/books/opus4/
 *   - Class hierarchy diagram
 *     - http://www.brpreiss.com/books/opus4/html/page617.html#SECTION0019000000000000000000
 */

/*!
 * \brief Abstract base class for all containers.
 *
 * \todo Pull up all common functionality from derived classes.
 */
class Container: public Object {
public:

   const static Info* const TYPE_INFO;

private:

   /*!
    * \brief Number of Entity objects in this Container
    *
    * Access to modify this variable is should be controlled by an abstract base
    * class where possible. Any method that modifies #count should be implemented
    * by the abstract class. For example, append(Entity) is implemented by
    * #OrderedList. No base class of #OrderedList should override append(Entity*)
    * or any other method that modifies #count. Instead, methods like
    * append(Entity*) are written as templates (in the OO sense, not the C++
    * template mechanism) and an "_impl" version is supplied for a derived
    * class to override, e.g., append_impl(Entity*) which does the actual work
    * of adding an item to the Container.
    */
   int count;

protected:

   Container();
   Container(const Container& orig);

public:

   virtual ~Container();

   /*********************  Container Methods (public) *********************/

   /*!
    * \brief Return the number of Entity objects in this container
    */
   int getCount() const;

   /*!
    * \brief Return true if the container is empty, false otherwise
    */
   bool isEmpty() const;

   /*!
    * \brief Empty the contents of the container, deleting all Entities
    *
    * This method is used by the destructor.
    *
    * \return The number of Entity objects deleted
    *
    * \post isEmpty() is true
    * \post The memory for all Entities is freed
    */
   virtual int purgeContents() = 0;

protected:

   /*********************  Container Methods (protected) *********************/

   void setCount(int c);

   void incCount();

   void decCount();

public:

   /*********************  Object Methods (public) *********************/

   virtual ostream& renderState(ostream& os) const;

   virtual const Info* typeInfo() const;

   virtual Object* clone(bool deepCopy = false) const = 0;

};

} // namespace container
#endif /* _CONTAINER_H */
