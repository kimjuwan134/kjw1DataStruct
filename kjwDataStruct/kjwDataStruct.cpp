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
	cout << root->data;
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

// ���� ��ȸ
// 1. Root Node�� �湮.
// 2. ���� ���� Ʈ�� ���� ��ȸ.
// 3. ������ ���� Ʈ�� ���� ��ȸ.

// ���� ��ȸ
// 1. ���� ���� Ʈ�� ���� ��ȸ.
// 2. Root Node �湮.
// 3. ������ ���� Ʈ�� ���� ��ȸ.

// ���� ��ȸ
// 1. ���� ���� Ʈ�� ���� ��ȸ.
// 2. ������ ���� Ʈ�� ���� ��ȸ.
// 3. Root Node �湮.


int main()
{
#pragma region Ʈ��

	// �׷����� �������� ������ ������ �̿��Ͽ� 
	// �������� ��ġ ���¸� �߻�ȭ�� �ڷᱸ��.

	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	






#pragma endregion




	

	return 0;
}