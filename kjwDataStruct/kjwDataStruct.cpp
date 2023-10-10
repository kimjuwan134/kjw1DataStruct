#include <iostream>

using namespace std;


#pragma region 단일 연결 리스트

// 1. 단일 연결 리스트 노드 제작



#pragma endregion

struct Node
{
	int data;
	Node * next;
};

void PushFront(Node * target, int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = target->next;
	target->next = newNode;
}



int main()
{
	Node * head = new Node;
	head->next = NULL;

	PushFront(head, 10);
	PushFront(head, 20);
	PushFront(head, 30);


	Node * currentPtr = head->next;

	while (currentPtr != NULL)
	{
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}



	delete head;





	return 0;
}
