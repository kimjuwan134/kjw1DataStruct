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


	for (int i = 0; i < v.Size(); i++)
	{
		cout << v[i] << endl;
	}


	
	
	
	// 1. Size() �Լ� ����
	// 2. PopBack() �Լ� ����
	// 3. �Ҹ��� ����







	

	return 0;
}