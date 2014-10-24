#pragma once
#include "Deque.h"


//Part 4--------------------------------------------------------------
/**
 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Deque::addToDequeLeft(int car)
{
    return false;
}

/**
 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Deque::addToDequeRight(int car)
{
    return false;
}

/**
 * Removes the leftmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Deque::removeFromDequeLeft()
{
    return false;
}

/**
 * Removes the rightmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Deque::removeFromDequeRight()
{
    return false;
}

/**
 * Returns the ID of the leftmost car in the deque.
 *
 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
 */
int Deque::showTopOfDequeLeft()
{
    return 0;
}

/**
 * Returns the ID of the rightmost car in the deque.
 *
 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
 */
int Deque::showTopOfDequeRight()
{
    return 0;
}

/**
 * Returns the number of cars in the deque.
 *
 * @return the number of cars in the deque
 */
int Deque::showSizeOfDeque()
{
    return 0;
}

bool Deque::isDuplicate(int x) {
    return list->duplicate(x);
}
