#include "LinkedListInterface.h"

template <class T>

class LinkedList : public LinkedListInterface
{
private:
	class Node;

	Node* head = NULL;
	Node* tail = NULL;

	virtual bool duplicate(T value);
public:
	LinkedList(){};
	virtual ~LinkedList(){
		clear();
	};

	virtual void insertHead(T value);
	virtual void insertTail(T value);
	virtual void insertAfter(T value, T insertionValue);
	virtual void remove(T value);
	virtual void clear();
	virtual T at(T index);
	virtual int size(); 
};

template<class T>
class LinkedList<T>::Node {
public:

	Node* next = NULL;
	T value;
	Node(){};
	~Node(){};
};