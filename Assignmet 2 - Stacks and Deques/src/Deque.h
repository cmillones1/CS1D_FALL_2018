/*
 * Deque.h
 *
 *  Created on: Aug 4, 2018
 *      Author: Chris
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include "header.h"

template <class E>
	struct Dnode
	{
		E data;
		Dnode<E>* next;
		Dnode<E>* prev;
	};
template <class E>
class Deque {
public:
	Deque();
	 ~Deque();

	bool empty();
	int size();
	void push_back(E data);
	void push_front(E data);

	void pop_back();
	void pop_front();

	void print();

private:

	Dnode<E> *head;
	Dnode<E> *tail;
	int count;

};

template <class E>
Deque<E>::Deque() {
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class E>
Deque<E>::~Deque() {
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class E>
bool Deque<E>::empty()
{
	return count == 0? true:false;
}

template <class E>
int Deque<E>::size()
{
	return count;
}

template <class E>
void Deque<E>::push_back(E data)
{
	Dnode<E>* temp = new Dnode<E>;


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
	delete(temp);

	count ++;

}

template <class E>
void Deque<E>::push_front(E data)
{
	Dnode<E>* temp = new Dnode<E>;
	if(size() == 0)
	{

		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = head;
		temp = NULL;
	}
	else
	{
		temp->data = data;

		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
		temp = NULL;
	}

    delete(temp);
	count ++;

}

template <class E>
void Deque<E>::pop_back()
{
	Dnode<E>* temp = new Dnode<E>;
	temp = head;
	if (count == 0)
	{
		cout << "STACK IS EMPTY!\n";
	}else
	{
	while(temp->next != tail)
	{
		temp = temp->next;
	}
	tail = temp;
	tail->next = NULL;
	temp = NULL;
	}
	delete(temp);
}

template <class E>
void Deque<E>::pop_front()
{
	Dnode<E>* temp = new Dnode<E>;
	if (count == 0)
	{
		cout << "STACK IS EMPTY!\n";
	}else
	{
		temp = head->next;
		head->next = NULL;
		head = temp;
		temp = NULL;
	}
	delete(temp);

}

template <class E>
void Deque<E>::print()
{
	Dnode<E>* temp = new Dnode<E>;
	temp = head;
	int counter = 1;

	while(temp != NULL)
	{

		cout << "Element [" << counter << "] " << temp->data << endl;
		temp = temp->next;
		counter ++;
	}

}

#endif /* DEQUE_H_ */
