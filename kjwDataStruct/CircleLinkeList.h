#pragma once
#include <iostream>

using namespace std;


template <typename T>
class CircleLinkedList
{
private :
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	int size;

public :
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
		size++;
	}

	void PopBack()
	{
		Node* deleteNode = head;
		Node* currentNode = head;
		if (size == 1)
		{
			delete deleteNode;
			head = nullptr;
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = head->next;
			head = currentNode;
			delete deleteNode;
		}
		size--;
	}

	void PopFront()
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		if (size == 1)
		{
			Node* deleteNode = head;
			delete deleteNode;
			head = nullptr;
		}
			Node* deleteNode = head->next;
			head->next = deleteNode->next;
			delete deleteNode;
			size--;
	}

	void Display()
	{
		Node* currentNode = head->next;
		for (int i = 0; i < size; i++)
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

	~CircleLinkedList()
	{
		for (int i = 0; i < size; i++)
		{
			Node* deleteNode = head->next;
			head->next = deleteNode->next;
			delete deleteNode;
		}
	}
};