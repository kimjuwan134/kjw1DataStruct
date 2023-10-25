#include <iostream>
#include "CircleQueue.h"

using namespace std;


int main()
{
#pragma region ���� ť

	// ���������δ� ���� ������ ������ ������, ť�� �������� ������ ������ ť.

	CircleQueue<int> q;

	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Dequeue();
	q.Dequeue();

	cout << q.Front() << endl;
	cout << q.Back() << endl;
	cout << q.Size() << endl;
	cout << q.Empty() << endl;
	cout << q.IsFull() << endl;
	



#pragma endregion







	

	return 0;
}