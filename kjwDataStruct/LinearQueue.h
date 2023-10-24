#pragma once
#include <iostream>
#define SIZE 5

using namespace std;

#pragma region 선형 큐

// 배열의 공간에 들어간 데이터가 고정되어 데이터를 빼내더라도 초기화하지 않으면
// 원래 데이터가 있던 배열의 자리에 더 이상 다른 값이 들어갈 수 없는 Queue입니다.

#pragma endregion

template <typename T>
class LinearQueue
{
private :
	int front;
	int rear;
	int size;
	T buffer[SIZE];

public :
	LinearQueue()
	{
		front = 0;
		rear = 0;
		size = 0;
	}

	void Enqueue(T data)
	{
		if (rear >= SIZE)
		{
			cout << "FULL" << endl;
		}
		else
		{
			buffer[rear++] = data;
			size++;
		}
	}

	void Dequeue()
	{
		if (front == rear)
		{
			cout << "Nothing" << endl;
		}
		else
		{
			buffer[front++] = 0;
		}
	}

	bool IsFull()
	{
		if (rear == SIZE) return true;
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
		else return buffer[front];
	}

	T &Back()
	{
		return buffer[rear - 1];
	}

	int& Size()
	{
		return size;
	}
};