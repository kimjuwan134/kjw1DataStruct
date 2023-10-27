#pragma once
#include <iostream>

using namespace std;

template <typename T>
class VECTOR
{
private:
	int size;
	int capacity;
	T* bufferPointer;

public:
	VECTOR()
	{
		size = 0;
		capacity = 0;
		bufferPointer = nullptr;
	}

	T& operator[](const int value)
	{
		return bufferPointer[value - 1];
	}

	void Resize(int newSize)
	{
		capacity = newSize;
		T* newPointer = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			newPointer[i] = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			newPointer[i] = bufferPointer[i];
		}

		if (bufferPointer != nullptr)
		{
			delete[]bufferPointer;
		}

		bufferPointer = newPointer;
	}

	void PushBack(T data)
	{
		if (capacity == 0)
		{
			Resize(1);
		}
		else if (size >= capacity)
		{
			capacity = capacity * 2;
			Resize(capacity);
		}

		bufferPointer[size++] = data;
	}

};