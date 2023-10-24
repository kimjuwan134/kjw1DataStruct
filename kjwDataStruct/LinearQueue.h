#pragma once
#include <iostream>
#define SIZE 5

using namespace std;

#pragma region ���� ť

// �迭�� ������ �� �����Ͱ� �����Ǿ� �����͸� �������� �ʱ�ȭ���� ������
// ���� �����Ͱ� �ִ� �迭�� �ڸ��� �� �̻� �ٸ� ���� �� �� ���� Queue�Դϴ�.

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