#pragma once
#include <iostream>

using namespace std;


#pragma region ���� Ž�� Ʈ��(BST)

// ������ Ű�� ���� ���Ҹ� ����, ����, �˻��ϴµ� ȿ������ �˰���.

#pragma endregion


template <typename T>
class BinarySearchTree
{
private :
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};
	Node* rootNode;

public :
	BinarySearchTree()
	{
		rootNode = nullptr;
	}

	Node* GetRoot()
	{
		return rootNode;
	}
	                      
	void Insert(T data, Node* root)
	{
		if (root == nullptr)
		{
			root = new Node;
			root->data = data;
			root->left = nullptr;
			root->right = nullptr;
		}
		else
		{
			if (root->data > data)
			{
				Insert(data, root->left);
			}
			else if (root->data < data)
			{
				Insert(data, root->right);
			}
		}
	}



};