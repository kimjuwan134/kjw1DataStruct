#pragma once
#include <iostream>

using namespace std;

template <typename T>


class STACK
{
private :
	int top;
	T data;
	T buffer[5];

public :
	STACK()
	{
		top = -1;
	}

	void Push(T data)
	{
		if (IsFull())
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			buffer[++top] = data;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "STACK is Empty" << endl;
		}
		else
		{
			top--;
		}
	}
	
	T & Top()
	{
		if (top <= -1)
		{
			cout << "Empty is nothing";
		}
		else return buffer[top];
	}

	bool  Empty()
	{
		if (top <= -1) return true;
		else return false;
	}

	bool  IsFull()
	{
		if (top >= 4) return true;
		else return false;
	}

	int  Size()
	{
		return top + 1;
	}

	~STACK() {}

};