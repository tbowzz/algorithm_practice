//
// Created by Tyler Bowers on 4/9/20.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <sstream>
#include "LinkedListInterface.h"

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
public:
	LinkedList() : head(nullptr) {}

	void push_front(const T &value) override
	{
		Node *node = new Node();
		node->data = value;
		if (head)
		{
			node->next = (Node*)head;
			head = (Node*)node;
		}
		else
		{
			head = node;
		}
	}

	void pop_front(void) override
	{

	}

	T &front(void) override
	{
		return head->data;
	}

	bool empty(void) const override
	{
		return head == nullptr;
	}

	void remove(const T &value) override
	{

	}

	void clear(void) override
	{
		while (head != nullptr)
		{
			Node *next = head->next;
			delete head;
			head = next;
		}
	}

	void reverse(void) override
	{

	}

	size_t size(void) const override
	{
		size_t size = 0;
		Node *current = head;
		while (current != nullptr)
		{
			size++;
			current = current->next;
		}
		return size;
	}

	std::string toString(void) const override
	{
		Node *current = (Node*)head;
		std::stringstream ss;
		while (current != nullptr)
		{
			ss << " " << current->data;
			current = current->next;
		}

		return ss.str();
	}

private:
	struct Node
	{
		Node() : next(nullptr) {}
		T data;
		struct Node *next;
	};

	Node *head;
};


#endif //LINKEDLIST_LINKEDLIST_H
