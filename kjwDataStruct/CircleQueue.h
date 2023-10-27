#pragma once
#include <iostream>

using namespace std;

#define SIZE 4

#pragma region 원형 큐

// 물리적으로는 선형 구조를 가지고 있으며, 큐의 시작점과 끝점을 연결한 큐.

#pragma endregion

template <typename T>
class CircleQueue
{
private :
	int front;
	int rear;
	int size;
	T buffer[SIZE];

public :
	CircleQueue()
	{
		front = SIZE - 1;
		rear = SIZE - 1;
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
		}
	}

	void Enqueue(T data)
	{
		if (IsFull() == true) cout << "CircleQueue is Full";
		else 
		{
			rear = (rear + 1) % SIZE;
			buffer[rear] = data;
			size++;
		}
	}

	void Dequeue()
	{
		if (Empty() == true) cout << "CircleQueue is Empty";
		else 
		{
			front = (front + 1) % SIZE;
			buffer[front] = NULL;
			size--;
		}
	}

	bool IsFull()
	{
		if ((rear + 1) % SIZE == front) return true;
		else return false;
	}

	bool Empty()
	{
		if (front == rear) return true;
		else return false;
	}

	T& Front()
	{
		if (Empty() == true) exit(1);
		else return buffer[(front + 1) % SIZE];
	}

	T& Back()
	{
		return buffer[rear];
	}

	int& Size()
	{
		return size;
	}

	~CircleQueue() {}
};