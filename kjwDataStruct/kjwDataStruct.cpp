#include <iostream>
#include "LinearQueue.h"

using namespace std;


int main()
{
#pragma region ��� ����

	// �������� ���� ���� ������ �ʰ�, �ܼ��ϰ� �� ���ڰ� � �ִ��� 
	// ������ ���� ������ ���� �����ϴ� �˰���.

	// �ð� ���⵵ : O(n+k)

	int arr[10] = { 1,3,5,4,2,4,1,3,5,1 };
	int brr[5];
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 10/(i+1)) count++;

	}


#pragma endregion








	

	return 0;
}