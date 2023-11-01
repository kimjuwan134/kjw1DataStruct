#include "BinarySearchTree.h"


int main()
{
	BinarySearchTree<int> bst;

	bst.Insert(10, bst.GetRoot());
	bst.Insert(20, bst.GetRoot());
	bst.Insert(30, bst.GetRoot());
	bst.Insert(40, bst.GetRoot());
	bst.Insert(50, bst.GetRoot());

	bst.Inorder(bst.GetRoot());
	bst.Insert(50, bst.GetRoot());
	bst.Insert(50, bst.GetRoot());
	bst.Inorder(bst.GetRoot());






	

	return 0;
}