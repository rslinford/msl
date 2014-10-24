#pragma once
#include "Station.h"
#include "LinkedList.h"
#include "Deque.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

  		//Part 1--------------------------------------------------------------
		/**
		 * Let another car arrive at the station and become the current car.
		 * Do not allow a new car to arrive if any of the following conditions apply:
		 * 1.	There is already a current car
		 * 2.	The new car's ID already exists in any structure
		 * 3.	The new car's ID is negative
		 *
		 * @param car the ID of the car arriving at the station
		 * @return true if the car successfully arrived; false otherwise
		 */
		bool Station::addToStation(int car)
		{
			if(cCar != -1 || car < 0)
			{
				return false;
			}
			if (queue.isDuplicate(car) || stack.isDuplicate(car) || deque.isDuplicate(car)) 
  			{
  				return false;
  			}
		    cCar = car;  
		    return true;
		}

		/**
		 * Returns the ID of the current car.
		 * Return -1 if there is no current car.
		 *
		 * @return the ID of the current car; -1 if there is no current car
		 */
		int Station::showCurrentCar()
		{
		    return cCar;
		}

		/**
		 * Removes the current car from the station.
		 * Does nothing if there is no current car.
		 *
		 * @return true if the current car successfully left; false otherwise
		 */
		bool Station::removeFromStation()
		{
		    if(cCar == -1)
		    {
		    	return false;
		    }
		    cCar = -1;
		    return true;
		}

		
		//Part 2--------------------------------------------------------------
		/**
		 * Adds the current car to the stack.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the stack is already full.
		 *
		 * @return true if the car is successfully added to the stack; false otherwise
		 */
		bool Station::addToStack()
		{
			if (cCar == -1) 
			{
				return false;
			}
			if (stack.size() >= 5) 
			{
				return false;
			}
			int temp = cCar;
			cCar = -1;
		    return stack.addToStack(temp);
		}

		/**
		 * Removes the first car in the stack and makes it the current car.
		 * Does nothing if there is already a current car or if the stack already empty.
		 *
		 * @return true if the car is successfully removed from the stack; false otherwise
		 */
		bool Station::removeFromStack()
		{
			if (cCar != -1) 
			{
				return false;
			}
			if (stack.size() <= 0) 
			{
				return false;
			}
			cCar = stack.showTopOfStack();
			stack.removeFromStack();
		    return true;
		}

		/**
		 * Returns the ID of the first car in the stack.
		 *
		 * @return the ID of the first car in the stack; -1 if the stack is empty
		 */
		int Station::showTopOfStack()
		{
		    return stack.showTopOfStack();
		}

		/**
		 * Returns the number of cars in the stack.
		 *
		 * @return the number of cars in the stack
		 */
		int Station::showSizeOfStack()
		{
		    return stack.showSizeOfStack();
		}

		//Part 3--------------------------------------------------------------
		/**
		 * Adds the current car to the queue.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the queue is already full.
		 *
		 * @return true if the car is successfully added to the queue; false otherwise
		 */
		bool Station::addToQueue()
		{	
			if (cCar == -1) 
			{
				return false;
			}
			if (queue.size() >= 5) 
			{
				return false;
			}
			int temp = cCar;
			cCar = -1;
		    return queue.addToQueue(temp);
		}

		/**
		 * Removes the first car in the queue and makes it the current car.
		 * Does nothing if there is already a current car or if the queue already empty.
		 *
		 * @return true if the car is successfully removed from the queue; false otherwise
		 */
		bool Station::removeFromQueue()
		{
			if (cCar != -1) 
			{
				return false;
			}
			if (queue.size() <= 0) 
			{
				return false;
			}
			cCar = queue.showTopOfQueue();
			queue.removeFromQueue();
		    return true;
		}

		/**
		 * Returns the ID of the first car in the queue.
		 *
		 * @return the ID of the first car in the queue; -1 if the queue is empty
		 */
		int Station::showTopOfQueue()
		{
		    return queue.showTopOfQueue();
		}

		/**
		 * Returns the number of cars in the queue.
		 *
		 * @return the number of cars in the queue
		 */
		int Station::showSizeOfQueue()
		{
		    return queue.showSizeOfQueue();
		}

		//Part 4--------------------------------------------------------------
		/**
		 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the deque is already full.
		 *
		 * @return true if the car is successfully added to the deque; false otherwise
		 */
		bool Station::addToDequeLeft()
		{
			if (cCar == -1) 
			{
				return false;
			}
			if(deque.size() >= 5)
			{
				return false;
			}
			int temp = cCar;
			cCar = -1;
		    return deque.addToDequeLeft(temp);
		}

		/**
		 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the deque is already full.
		 *
		 * @return true if the car is successfully added to the deque; false otherwise
		 */
		bool Station::addToDequeRight()
		{
			if (cCar != -1) 
			{
				return false;
			}
			if (deque.size() >= 5) 
			{
				return false;
			}
			int temp = cCar;
			cCar = -1;
		    return deque.addToDequeRight(temp);
		}

		/**
		 * Removes the leftmost car in the deque and makes it the current car.
		 * Does nothing if there is already a current car or if the deque already empty.
		 *
		 * @return true if the car is successfully removed from the deque; false otherwise
		 */
		bool Station::removeFromDequeLeft()
		{
			if (cCar != -1) 
			{
				return false;
			}
			if (deque.size() <= 0) 
			{
				return false;
			}
			cCar = deque.showTopOfDequeLeft();
			deque.removeFromDequeLeft();
	    	return true;
		}

		/**
		 * Removes the rightmost car in the deque and makes it the current car.
		 * Does nothing if there is already a current car or if the deque already empty.
		 *
		 * @return true if the car is successfully removed from the deque; false otherwise
		 */
		bool Station::removeFromDequeRight()
		{
			if (cCar != -1) {
				return false;
			}
			
			if (deque.size() <= 0) {
				return false;
			}
			cCar = deque.showTopOfDequeRight();
			deque.removeFromDequeRight();
	    	return true;
		}

		/**
		 * Returns the ID of the leftmost car in the deque.
		 *
		 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
		 */
		int Station::showTopOfDequeLeft()
		{
		    return deque.showTopOfDequeLeft();
		}

		/**
		 * Returns the ID of the rightmost car in the deque.
		 *
		 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
		 */
		int Station::showTopOfDequeRight()
		{
			
		    return deque.showTopOfDequeRight();
		}

		/**
		 * Returns the number of cars in the deque.
		 *
		 * @return the number of cars in the deque
		 */
		int Station::showSizeOfDeque()
		{
		    return deque.showSizeOfDeque();
		}
		

				