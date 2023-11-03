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

	T & Delete()
	{
		// Heap이 비어있다면 프로그램 종료.
		if (size <= 0)
		{
			cout << "Data is Empty" << endl;
			exit(1);
		}

		// 2. 임시 변수 -> 가장 큰 값을 보관하는 역할
		T result = buffer[1];

		// 3. size로 가리키는 배열의 값을 첫 번째 원소에 넣음.
		buffer[1] = buffer[size];

		// 4. size로 가리키는 배열의 값을 초기화.
		buffer[size] = NULL;

		// 5. size의 값 감소.
		size--;

		int parent = 1;

		while (parent * 2 <= size)
		{
			int child = parent * 2;

			// 오른쪽 자식의 노드가 클 때
			if (buffer[child] < buffer[child + 1])
			{
				child++;
			}

			// 부모 노드의 Key 값이 자식 노드의 Key 값보다 크다면 반복 종료.
			if (buffer[child] < buffer[parent])
			{
				break;
			}

			swap(buffer[parent], buffer[child]);
			parent = child;
		}
		return result;
	}
	
};