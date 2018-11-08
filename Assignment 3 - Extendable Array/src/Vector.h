/*
 * Vector.h
 *
 *  Created on: Aug 14, 2018
 *      Author: Chris
 */

#ifndef VECTOR_H_
#define VECTOR_H_

template <class E>
class Vector
{
public:
	Vector();
	~Vector();

	bool isEmpty() const;
	int size() const;
	int Capacity() const;
	E front() const;
	E back() const;
	E at(int temp) const;
	void push_back(E data);
	void pop_front();

private:
	E cubby[5];
	int capacity;
	int count;
	int head;
	int tail;
};

template <class E>
Vector<E>::Vector()
{
	count = 0;
	head = 0;
	tail = 0;
	capacity = 5;
}

template <class E>
Vector<E>::~Vector()
{
	count = 0;
	head = 0;
	tail = 0;
}

template <class E>
bool Vector<E>::isEmpty() const
{
	return size() == 0? true:false;
}

template <class E>
int Vector<E>::size() const
{
	return count;
}

template <class E>
int Vector<E>::Capacity() const
{
	return capacity;
}

template <class E>
E Vector<E>::front() const
{
	return at(head);
}

template <class E>
E Vector<E>::back() const
{
	return at(tail);
}

template <class E>
E Vector<E>::at(int temp) const
{
	return cubby[temp];
}

template <class E>
void Vector<E>::push_back(E data)
{
	if(size() == 0)
	{
		cubby[head] = data;
		tail++;
	}
	else
	{
	}

}



#endif /* VECTOR_H_ */
