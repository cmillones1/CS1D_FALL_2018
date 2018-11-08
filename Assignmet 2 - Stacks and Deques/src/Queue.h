/*
 * Queue.h
 *
 *  Created on: Aug 3, 2018
 *      Author: Chris
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "header.h"

template <class E>
	struct Qnode
	{
		E data;
		Qnode<E>* next;
	};

template <class E>
class Queue {
public:
	Queue();
	 ~Queue();

	bool empty();
	int size();
	void top();
	void push(E data);
	void  pop();
	void print();

private:

	Qnode<E> *head;
	Qnode<E> *tail;
	int count;

};


template <class E>
Queue<E>::Queue()
{
	head = tail = NULL;
	count = 0;
}

template <class E>
Queue<E>::~Queue()
{
	head = tail = NULL;
	count = 0;
}

template <class E>
bool Queue<E>::empty()
{
	return count == 0? true:false;
}

template <class E>
int Queue<E>::size()
{
	return count;
}

template <class E>
void Queue<E>::top()
{
	cout << "Top: " << head->data;
}


template <class E>
void Queue<E>::push(E data)
{
	Qnode<E>* temp = new Qnode<E>;


	if(size() == 0)
	{
		temp->data = data;
		temp->next = NULL;
		head = tail = temp;
	}
	else
	{
		temp->data = data;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	count ++;
}

template <class E>
void Queue<E>::pop()
{
	Qnode<E>* temp = new Qnode<E>;
	temp = head;
	if (count == 0)
	{
		cout << "STACK IS EMPTY!\n";
	}else
	{
		temp = head->next;
		head->next = NULL;
		head = temp;
	}
	delete(temp);
}


template <class E>
void Queue<E>::print()
{
	Qnode<E>* temp = new Qnode<E>;
	temp = head;
	int counter = 1;

	while(temp != NULL){

		cout << "Element [" << counter << "] " << temp->data << endl;
		temp = temp->next;
		counter ++;
	}

}



#endif /* QUEUE_H_ */
