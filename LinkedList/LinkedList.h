//
// Created by Tyler Bowers on 4/9/20.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "LinkedListInterface.h"

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
public:
	void push_front(const T &value) override;

	void pop_front(void) override;

	T &front(void) override;

	bool empty(void) const override;

	void remove(const T &value) override;

	void clear(void) override;

	void reverse(void) override;

	size_t size(void) const override;

	std::string toString(void) const override;

private:
	struct Node
	{
		T data;
		struct Node *next;
	};

	Node *head;
};


#endif //LINKEDLIST_LINKEDLIST_H
