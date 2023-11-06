#pragma once
#include <iostream>

using namespace std;

#define SIZE 5


#pragma region �ؽ� ���̺�

// (Key, Value)�� �����͸� �����ϴ� �ڷᱸ�� �� �ϳ��� ������ �����͸� �˻��� �� �ִ� �ڷᱸ��.
// �ؽ� ���̺��� ��� �ð� ���⵵�� O(1)�Դϴ�.

// �ؽ� �浹�� �ذ��ϴ� ���
// <ü�̴� ���>
// �� �ؽ� ��Ŷ�� ���� ����Ʈ�� �����ϴ� ���.
// �ؽ� �浹 �߻��� ������ �ؽ� ���� �ش��ϴ� �����͵��� ���� ����Ʈ�� �����Ͽ� ����.

// <���� �ּҹ�>
// �浹 �߻��� �� ��Ŷ�� �����͸� �����ϴ� ���.
// �� ��Ŷ�� ��� ������ ���� ���� ���� ����� �޶���.

// ���� Ž�� : �浹 �߻��� �տ������� ���ʴ�� �� ��Ŷ�� ã�� ���� �����ϴ� ���.

// 2�� Ž�� : �浹 �߻��� 2�� ����, 2�� ��������ŭ ������ �� ��Ŷ�� ã�� ���� ����.

// ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؽ� �Լ��� �־� �ٸ� �Լ��� �����ϴ� ���.

#pragma endregion


template<typename K, typename V>
class HashTable
{
private :
	struct Node
	{
		K key;
		V value;
		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];

public :
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	int HashFunction(K key)
	{
		int temp = 0;

		for (const char & element : key)
		{
			temp += (int)element;
		}

		int hashIndex = temp % SIZE;
		return hashIndex;
	}

	Node * CreateNode(K key, V value)
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void Insert(K key, V value)
	{
		int hashIndex = HashFunction(key);

		Node* newNode = CreateNode(key, value);

		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newNode;
			bucket[hashIndex].count++;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
			bucket[hashIndex].count++;
		}
	}
};