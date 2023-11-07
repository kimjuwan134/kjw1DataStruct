#pragma once
#include <iostream>
#include <string>

using namespace std;

#define SIZE 5


#pragma region 해시 테이블

// (Key, Value)로 데이터를 저장하는 자료구조 중 하나로 빠르게 데이터를 검색할 수 있는 자료구조.
// 해시 테이블의 평균 시간 복잡도는 O(1)입니다.

// 해시 충돌을 해결하는 방법
// <체이닝 기법>
// 각 해시 버킷을 연결 리스트로 구성하는 방식.
// 해시 충돌 발생시 동일한 해시 값에 해당하는 데이터들을 연결 리스트로 연결하여 저장.

// <개방 주소법>
// 충돌 발생시 빈 버킷에 데이터를 저장하는 방식.
// 빈 버킷을 어떻게 결정할 지에 따라 구현 방식이 달라짐.

// 선형 탐사 : 충돌 발생시 앞에서부터 차례대로 빈 버킷을 찾아 값을 저장하는 방식.

// 2차 탐사 : 충돌 발생시 2의 제곱, 2의 세제곱만큼 떨어진 빈 버킷을 찾아 값을 저장.

// 이중 해싱 : 해시 값을 한번 더 해시 함수에 넣어 다른 함수를 도출하는 방식.

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
		// 1. 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 2. Node를 탐색할 수 있는 순회용 포인터 변수 선언
		// 각 Bucket의 Head를 저장.

		Node* currentNode = bucket[hashIndex].head;

		// 3. 이전 노드를 저장할 수 있는 포인터 변수 선언
		Node* traceNode = nullptr;

		// 4. currentNode가 nullptr이라고 하면 함수 종료.
		if (currentNode == nullptr)
		{
			cout << "HashTable is Empty" << endl;
			return;
		}

		// 5. currentNode를 이용해서 내가 찾고자 하는 key 값 찾기.
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