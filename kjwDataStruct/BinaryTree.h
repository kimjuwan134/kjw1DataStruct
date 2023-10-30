#pragma once
#include <iostream>

using namespace std;


class BinaryTree
{
private:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
	};

public :
	Node * node;

	BinaryTree()
	{
		node = nullptr;
	}

	Node * CreateNode(int data, Node* left, Node* right)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->left = left;
		newNode->right = right;

		return newNode;
	}

	
};

