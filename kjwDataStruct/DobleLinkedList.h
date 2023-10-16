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
			newNode->previous = nullptr;
			head->previous = newNode;
			head = newNode;
		}
		size++;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->data;
		}
		size++;
	}

	void PopFront()
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		else if (size == 1)
		{
			Node* deleteNode = head;
			head = nullptr;
			tail = nullptr;
			delete deleteNode;
		}
		else
		{
			Node* deleteNode = head;
			head = head->next;
			head->previous = nullptr;
			delete deleteNode;
		}
		size--;
	}

	void PopBack()
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		else if (size == 1)
		{
			Node* deleteNode = head;
			head = nullptr;
			tail = nullptr;
			delete deleteNode;
		}
		else
		{
			Node* deleteNode = tail;
			tail = tail->previous;
			tail->next = nullptr;
			delete deleteNode;
		}
		size--;
	}

	void Insert(int position, T data)
	{
		if (position <= 1)
		{
			PushFront(data);
			return;
		}

		Node* currentNode = head;

		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;
		}

		Node* newNode = new Node;
		newNode->next = currentNode;
		currentNode->previous->next = newNode;
		newNode->previous = currentNode->previous;
		currentNode->previous = newNode;
		size++;
	}

	~DobleLinkedList()
	{
		while (head != nullptr)
		{
			Node* deleteNode = head;
			head = head->next;
			delete deleteNode;
		}
	}
};

