#pragma once
#include <iostream>

using namespace std;


template <typename T>
class DobleLinkedList
{
private :
	struct Node
	{
		T data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;

public :
	DobleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr && tail == nullptr)
		{
			newNode->next = nullptr;
			newNode->previous = nullptr;
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
};

