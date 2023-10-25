#pragma once
#include <iostream>
#include "LinearQueue.h"

using namespace std;

#define COUNT_SIZE 5
#define BUFFER_SIZE 10


int main()
{
#pragma region ��� ����

	// �������� ���� ���� ������ �ʰ�, �ܼ��ϰ� �� ���ڰ� � �ִ��� 
	// ������ ���� ������ ���� �����ϴ� �˰���.

	// �ð� ���⵵ : O(n+k)

	int buffer[BUFFER_SIZE] = { 5,4,3,2,1,2,3,4,5,1 };
	int countBuffer[COUNT_SIZE] = { 0, };

	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		countBuffer[buffer[i] - 1]++;
	}

	for (int i = 0; i < COUNT_SIZE; i++)
	{
		cout << countBuffer[i] << endl;
	}

#pragma endregion





	return 0;
}