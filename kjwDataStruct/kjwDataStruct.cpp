#include <iostream>

using namespace std;

#define SIZE 5


int main()
{
#pragma region ���� ����

	// ���ĵ��� ���� �����͵鿡 ���� ���� ���� �����͸� ã�Ƽ� 
	// ���� �տ� �ִ� �����Ϳ� ��ȯ�ϴ� �˰���.

	// �ð����⵵ O(n^2)

	int arr[SIZE] = { 5,8,3,9,1 };

	for (int i = 0; i < SIZE - 1; i++)
	{
		int min = arr[i];

		int select = i;

		for (int j = i + 1; j < SIZE; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				select = j;
			}
		}
		swap(arr[i], arr[select]);
	}

	for (const int & element : arr)
	{
		cout << element << " ";
	}
	

	


#pragma endregion






	return 0;
}
