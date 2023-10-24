#include <iostream>
#include "LinearQueue.h"

using namespace std;


int main()
{
#pragma region 계수 정렬

	// 데이터의 값을 직접 비교하지 않고, 단순하게 각 숫자가 몇개 있는지 
	// 개수를 세어 저장한 다음 정렬하는 알고리즘.

	// 시간 복잡도 : O(n+k)

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