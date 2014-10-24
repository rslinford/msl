#pragma once
#include "Deque.h"


// For sanity define tail to head from left to right:
//   list's tail is Deque Left
//   list's head as Deque Right

//Part 4--------------------------------------------------------------
/**
 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Deque::addToDequeLeft(int car)
{
    list->insertTail(car);
    return true;
}

/**
 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Deque::addToDequeRight(int car)
{
    list->insertHead(car);
    return true;
}

/**
 * Removes the leftmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Deque::removeFromDequeLeft()
{
    if (list->size() <= 0) {
        return false;
    }
    
    list->remove(list->at(list->size()-1));
    return true;
}

/**
 * Removes the rightmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Deque::removeFromDequeRight()
{
    if (list->size() <= 0) {
        return false;
    }
    
    list->remove(list->at(0));
    return true;
}

/**
 * Returns the ID of the leftmost car in the deque.
 *
 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
 */
int Deque::showTopOfDequeLeft()
{
    if (list->size() <= 0) {
        return -1;
    }
    
    return list->at(list->size()-1);
}

/**
 * Returns the ID of the rightmost car in the deque.
 *
 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
 */
int Deque::showTopOfDequeRight()
{
    if (list->size() <= 0) {
        return -1;
    }
    
    return list->at(0);
}

/**
 * Returns the number of cars in the deque.
 *
 * @return the number of cars in the deque
 */
int Deque::showSizeOfDeque()
{
    return list->size();
}

bool Deque::isDuplicate(int x) {
    return list->duplicate(x);
}
