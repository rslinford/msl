#include "LinkedListInterface.h"


class LinkedList : public LinkedListInterface
{
private:
    class Node;
    
    Node* head = NULL;
    Node* tail = NULL;

    virtual bool duplicate(int value);
public:
	LinkedList(){};
	virtual ~LinkedList(){
	    clear();
	};

	virtual void insertHead(int value);
	virtual void insertTail(int value);
	virtual void insertAfter(int value, int insertionValue);
	virtual void remove(int value);
	virtual void clear();
	virtual int at(int index);
	virtual int size();
};

class LinkedList::Node {
public:

   Node* next = NULL;
   int value;
   Node(){};
   ~Node(){};
};