#include <iostream>
#include "VECTOR.h"
#include <vector>

using namespace std;


int main()
{
	VECTOR<int> v;

	v.PushBack(10);
	v.PushBack(20);
	v.PushBack(30);
	v.PushBack(40);
	v.PushBack(50);

	v.PopBack();
	v.PopBack();


	for (int i = 0; i < v.Size(); i++)
	{
		cout << v[i] << endl;
	}
	
	cout << v.Size();


	
	
	
	// 1. Size() 함수 구현
	// 2. PopBack() 함수 구현
	// 3. 소멸자 구현







	

	return 0;
}