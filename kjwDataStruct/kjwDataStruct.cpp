#include "CircleLinkeList.h"

int main()
{
	CircleLinkedList<int> cir;

	cir.PushBack(10);
	cir.PushBack(20);
	cir.PushFront(30);
	cir.PushFront(40);
	cir.PopFront();
	cir.PopBack();
	cir.Display();



	return 0;
}
