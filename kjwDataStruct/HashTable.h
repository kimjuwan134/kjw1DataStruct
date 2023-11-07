#pragma once
#include <iostream>
#include <string>

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

	template <typename T>
	int HashFunction(T key)
	{
		int hashIndex = (int)key % SIZE;

		return hashIndex;
	}

	template<>
	int HashFunction(string key)
	{
		int temp = 0;

		for (const char& element : key)
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

	void Remove(K key)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// 2. Node�� Ž���� �� �ִ� ��ȸ�� ������ ���� ����
		// �� Bucket�� Head�� ����.

		Node* currentNode = bucket[hashIndex].head;

		// 3. ���� ��带 ������ �� �ִ� ������ ���� ����
		Node* traceNode = nullptr;

		// 4. currentNode�� nullptr�̶�� �ϸ� �Լ� ����.
		if (currentNode == nullptr)
		{
			cout << "HashTable is Empty" << endl;
			return;
		}

		// 5. currentNode�� �̿��ؼ� ���� ã���� �ϴ� key �� ã��.
		while (currentNode != nullptr)
		{
			if (currentNode->key == key)
			{
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				bucket[hashIndex].count--;
				delete currentNode;
				return;
			}

			traceNode = currentNode;
			currentNode = currentNode->next;
		}

		cout << "Not key Found" << endl;
	}

	void Display()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* currentNode = bucket[i].head;

			while (currentNode != nullptr)
			{
				cout << "[" << i << "]" << "Key : " << currentNode->key << "Value : " << currentNode->value << " -->";
				currentNode = currentNode->next;
			}
			cout << endl;
		}
	}

	void Find(K key, V value)
	{
		Node* currentNode = bucket[0].head;

		while (currentNode != nullptr)
		{
			if (currentNode->key == key)
			{
				cout << "Key : " << currentNode->key << "Value" << currentNode->value << endl;
			}
		}
		
	}

	~HashTable()
	{
	}
};