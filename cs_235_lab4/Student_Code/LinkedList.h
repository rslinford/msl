#pragma once
#include <iostream>

using namespace std;

template <class T> 
class LinkedList
{
private:
	template <class U> 
	class Node {
	public:
		Node<U>* next = NULL;
		U value;
		Node(){};
		~Node(){};
	};

	Node<T>* head = NULL;
	Node<T>* tail = NULL;

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
	virtual T at(int index);
	virtual int size(); 
};


template <class T>
bool LinkedList<T>::duplicate(T value)
{
	if (head == NULL)
	{
		return false;
	}
	Node<T> *n = head;
	while (n != NULL)
	{
		if (n->value == value)
		{
			return true;
		}
		n = n->next;
	}
	return false;
}

/*
insertHead

A node with the given value should be inserted at the beginning of the list.

Only non-negative values should be added to the list. Do not allow
duplicate values in the list.
*/
template <class T>
void LinkedList<T>::insertHead(T value)
{
	// if (value < 0)
	// {
	// 	return;
	// }
	if (duplicate(value) == true)
	{
		return;
	}
	Node<T> *n = new Node<T>();
	n->value = value;
	n->next = head;
	head = n;
}

/*
insertTail

A node with the given value should be inserted at the end of the list.

Only non-negative values should be added to the list. Do not allow
duplicate values in the list.
*/
template <class T>
void LinkedList<T>::insertTail(T value)
{
	// 	if (value < 0 || duplicate(value) == true)
	// {
	// 	return;
	// }
	if (duplicate(value) == true)
	{
		return;
	}
	if (head == NULL)
	{
		Node<T> *t = new Node<T>();
		t->value = value;
		head = t;
		return;
	}

	Node<T> *n = head;
	while (n->next != NULL)
	{
		n = n->next;
	}

	n->next = new Node<T>();
	n->next->value = value;
	return;
}

/*
insertAfter

A node with the given value should be inserted immediately after the
node whose value is equal to insertionNode.

A node should only be added if the node whose value is equal to
insertionNode is in the list. Only non-negative values should be
added to the list. Do not allow duplicate values in the list.
*/
template <class T>
void LinkedList<T>::insertAfter(T value, T insertionNode)
{
	if (duplicate(value) || !duplicate(insertionNode))
	{
		return;
	}

	Node<T> *n = head;
	while (n->value != insertionNode)
	{
		n = n->next;
	}
	Node<T>* temp = n->next;
	n->next = new Node<T>();
	n->next->value = value;
	n->next->next = temp;
}

/*
remove

The node with the given value should be removed from the list.

The list may or may not include a node with the given value.
*/
template <class T>
void LinkedList<T>::remove(T value)
{
	if (head == NULL)
	{
		return;
	}

	Node<T> *n = head;
	Node<T> *prev = NULL;
	while (n != NULL)
	{
		// cout << "the value of n->value: " << n->value << endl;
		if (n->value == value)
		{
			if (prev == NULL)
			{
				head = n->next;
			}
			else
			{
				prev->next = n->next;
				//cout << "the next value of prev->next->value: " << prev->next->value << endl;
			}
			delete n;
			return;
		}
		prev = n;
		n = n->next;
	}
	return;
}

/*
clear

Remove all nodes from the list.
*/
template <class T>
void LinkedList<T>::clear()
{
	while (head != NULL)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	return;
}

/*
at

Returns the value of the node at the given index. The list begins at
index 0.

If the given index is out of range of the list, return -1;
*/
template <class T>
T LinkedList<T>::at(int index)
{
	// if (index >= size() || index < 0)
	// {
	// 	return -1;
	// }
	if (index >= size() || index < 0)
	{
		return NULL;
	}
	Node<T> *n = head;

	// interate "index" number of times to find the right node
	for (int i = index; i > 0; i--)
	{
		n = n->next;
	}
	return n->value;
}

/*
size

Returns the number of nodes in the list.
*/
template <class T>
int LinkedList<T>::size()
{
	if (head == NULL) {
		return 0;
	}

	int i = 1;
	Node<T> *n = head;
	while (n->next != NULL) {
		n = n->next;
		i++;
	}

	return i;
}
