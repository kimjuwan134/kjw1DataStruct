#include <iostream>

using namespace std;


#pragma region ���� ���� ����Ʈ

// 1. ���� ���� ����Ʈ ��� ����



#pragma endregion

void Remove(Node * target)
{
	Node * deleteNode = target->next;
	target->next = deleteNode->next;
	delete deleteNode;
}

int main()
{
	Node * head = new Node;
	head->next = NULL;

	PushFront(head, 10);
	PushFront(head, 20);
	PushFront(head, 30);

	Remove(head);

	Node * currentPtr = head->next;

	while (currentPtr != NULL)
	{
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}








	return 0;
}
