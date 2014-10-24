#pragma once
#include "LinkedList.h"

using namespace std;

class Queue
{
    private:
    
        LinkedList<int> list();

    public:
    
		//Part 3--------------------------------------------------------------
		/**
		 * Adds the current car to the queue.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the queue is already full.
		 *
		 * @return true if the car is successfully added to the queue; false otherwise
		 */
        bool queue.addToQueue(int x);
        
		/**
		 * Removes the first car in the queue and makes it the current car.
		 * Does nothing if there is already a current car or if the queue already empty.
		 *
		 * @return true if the car is successfully removed from the queue; false otherwise
		 */
		bool queue.removeFromQueue();

		/**
		 * Returns the ID of the first car in the queue.
		 *
		 * @return the ID of the first car in the queue; -1 if the queue is empty
		 */
        int queue.showTopOfQueue();

		/**
		 * Returns the number of cars in the queue.
		 *
		 * @return the number of cars in the queue
		 */
        int queue.showSizeOfQueue();
}
