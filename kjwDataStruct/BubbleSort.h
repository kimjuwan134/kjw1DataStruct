#pragma once
#include <iostream>
#include <Vector>

using namespace std;

#define SIZE 5

#pragma region ������ �����ε�

class Vector2
{
private:
	int x;
	int y;

public:
	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator+(const Vector2& vector2)
	{
		Vector2 clone(x + vector2.x, y + vector2.y);

		return clone;
	}

	Vector2 operator-(const Vector2& vector2)
	{
		Vector2 clone(x - vector2.x, y - vector2.y);

		return clone;
	}

	Vector2 operator*(const Vector2& vector2)
	{
		Vector2 clone(x * vector2.x, y * vector2.y);

		return clone;
	}

	Vector2 operator/(const Vector2& vector2)
	{
		Vector2 clone(x / vector2.x, y / vector2.y);

		return clone;
	}

	Vector2 operator++()
	{
		this->x++;
		this->y++;

		return *this;
	}

	Vector2 operator++(int)
	{
		Vector2 clone = *this;

		this->x++;
		this->y++;

		return clone;
	}

};




#pragma endregion



int main()
{
#pragma region ��ǰ ����

	// ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���.
	// �ð� ���⵵ O(n^2)

	/*int arr[SIZE] = { 7,2,3,0,1 };

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < (SIZE - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}

	for (const int & element : arr)
	{
		cout << element << " ";
	}*/

#pragma endregion

#pragma region ������ �����ε�

	Vector2 Up(0, 1);
	Vector2 Right(1, 0);
	Up + Right;

#pragma endregion







	return 0;
}
