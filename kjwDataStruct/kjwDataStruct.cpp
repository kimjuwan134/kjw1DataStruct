#include <iostream>
#include "LinearQueue.h"

using namespace std;


int main()
{
#pragma region ��� ����

	// �������� ���� ���� ������ �ʰ�, �ܼ��ϰ� �� ���ڰ� � �ִ��� 
	// ������ ���� ������ ���� �����ϴ� �˰���.

	// �ð� ���⵵ : O(n+k)

	int arr[10] = { 5,4,3,2,1,2,3,4,5,1 };
	int brr[5] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 1) brr[0] += 1;
		else if (arr[i] == 2) brr[1] += 1;
		else if (arr[i] == 3) brr[2] += 1;
		else if (arr[i] == 4) brr[3] += 1;
		else if (arr[i] == 5) brr[4] += 1;
	}

	for (int i = 0; i < 5; i++)
	{
		while (brr[i])
		{
			cout << i + 1;
			brr[i]--;
		}
	}

#pragma endregion








	

	return 0;
}