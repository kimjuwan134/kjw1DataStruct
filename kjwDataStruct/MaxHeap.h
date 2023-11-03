#pragma once
#include <iostream>

#define SIZE 10

using namespace std;

template <typename T>
class MaxHeap
{
private :
	T data;
	T buffer[SIZE] = { 0, };
	int size;

public :
	MaxHeap()
	{
		size = 0;
	}
	
	void Insert(T data)
	{
		if (IsFull())
		{
			cout << "MaxHeap is Full" << endl;
			return;
		}

		buffer[++size] = data;

		int child = size;
		int parent = size / 2;

		while (child > 1)
		{
			// 자식 노드와 부모 노드의 데이터 비교.
			if (buffer[parent] < buffer[child])
			{
				swap(buffer[parent], buffer[child]);
			}

			child = parent;
			parent = child / 2;
		}

	}

	bool IsFull()
	{
		if (size == SIZE - 1) return true;
		else return false;
	}

	void Display()
	{
		for (int i = 1; i < SIZE; i++)
		{
			cout << buffer[i] << " ";
		}
	}

	void Delete(T data)
	{
		if (size <= 0)
		{
			cout << "Data is Empty" << endl;
			return;
		}

		else if (size > 1 && size < SIZE)
		{
			swap(buffer[1], buffer[size]);
		}
	}
	
};