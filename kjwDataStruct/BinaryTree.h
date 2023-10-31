#pragma once
#include <iostream>

using namespace std;


struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data, Node* left, Node* right)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;
}

void PreorderTraversal(Node* root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

void PostorderTraversal(Node* root)
{
	if (root != nullptr)
	{
		PostorderTraversal(root->left);
		PostorderTraversal(root->right);
		cout << root->data << " ";
	}
}

void InorderTraversal(Node* root)
{
	if (root != nullptr)
	{
		InorderTraversal(root->left);
		cout << root->data << " ";
		InorderTraversal(root->right);
	}
}

// 전위 순회
// 1. Root Node를 방문.
// 2. 왼쪽 서브 트리 전위 순회.
// 3. 오른쪽 서브 트리 전위 순회.

// 중위 순회
// 1. 왼쪽 서브 트리 전위 순회.
// 2. Root Node 방문.
// 3. 오른쪽 서브 트리 전위 순회.

// 후위 순회
// 1. 왼쪽 서브 트리 전위 순회.
// 2. 오른쪽 서브 트리 전위 순회.
// 3. Root Node 방문.


int main()
{
#pragma region 트리

	// 그래프의 일종으로 정점과 간선을 이용하여 
	// 데이터의 배치 형태를 추상화한 자료구조.

	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	PreorderTraversal(node1);
	cout << endl;
	InorderTraversal(node1);
	cout << endl;
	PostorderTraversal(node1);

#pragma endregion






	return 0;
}