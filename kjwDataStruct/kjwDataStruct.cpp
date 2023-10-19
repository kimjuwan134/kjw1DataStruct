#include <iostream>

using namespace std;

#define SIZE 5


int main()
{
#pragma region 선택 정렬

	// 정렬되지 않은 데이터들에 대해 가장 작은 데이터를 찾아서 
	// 가장 앞에 있는 데이터와 교환하는 알고리즘.

	// 시간복잡도 O(n^2)

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
