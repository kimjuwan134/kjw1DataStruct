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

	T& operator[](const int& value)
	{
		return bufferPointer[value];
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

		//if (bufferPointer != nullptr)
		//{
		//	delete[]bufferPointer;
		//}
		delete[]bufferPointer;

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

	int& Size()
	{
		return size;
	}

	void PopBack()
	{
		if (size <= 0) cout << "Data is Empty" << endl;
		else bufferPointer[--size] = NULL;
	}

	void Reserve(int newSize)
	{
		if (newSize < capacity)
		{
			return;
		}
		Resize(newSize);
	}

	~VECTOR()
	{
		delete [] bufferPointer;
	}
};