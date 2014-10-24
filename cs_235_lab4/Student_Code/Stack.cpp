 #pragma once
 #include "Stack.h"
 
 using namespace std;
 
//Part 2--------------------------------------------------------------
/**
 * Adds the current car to the stack.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the stack is already full.
 *
 * @return true if the car is successfully added to the stack; false otherwise
 */
bool addToStack(int car)
{
    list.insertHead(car);
    return true;
}

/**
 * Removes the first car in the stack and makes it the current car.
 * Does nothing if there is already a current car or if the stack already empty.
 *
 * @return true if the car is successfully removed from the stack; false otherwise
 */
bool removeFromStack(int car)
{
    list.remove(car)
    return false;
}

/**
 * Returns the ID of the first car in the stack.
 *
 * @return the ID of the first car in the stack; -1 if the stack is empty
 */
int showTopOfStack()
{
    if (list.size()<=0)
    {
        return -1;
    }
    return list.at(0);;
}

/**
 * Returns the number of cars in the stack.
 *
 * @return the number of cars in the stack
 */
int showSizeOfStack()
{
    return list.size();
}