#include <iostream>
#include "CircleQueue.h"

using namespace std;


int main()
{
#pragma region 원형 큐

	// 물리적으로는 선형 구조를 가지고 있으며, 큐의 시작점과 끝점을 연결한 큐.

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