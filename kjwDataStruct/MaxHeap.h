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
			// �ڽ� ���� �θ� ����� ������ ��.
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
		// Heap�� ����ִٸ� ���α׷� ����.
		if (size <= 0)
		{
			cout << "Data is Empty" << endl;
			exit(1);
		}

		// 2. �ӽ� ���� -> ���� ū ���� �����ϴ� ����
		T result = buffer[1];

		// 3. size�� ����Ű�� �迭�� ���� ù ��° ���ҿ� ����.
		buffer[1] = buffer[size];

		// 4. size�� ����Ű�� �迭�� ���� �ʱ�ȭ.
		buffer[size] = NULL;

		// 5. size�� �� ����.
		size--;

		int parent = 1;

		while (parent * 2 <= size)
		{
			int child = parent * 2;

			// ������ �ڽ��� ��尡 Ŭ ��
			if (buffer[child] < buffer[child + 1])
			{
				child++;
			}

			// �θ� ����� Key ���� �ڽ� ����� Key ������ ũ�ٸ� �ݺ� ����.
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