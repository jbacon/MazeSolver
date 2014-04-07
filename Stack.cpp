
#include <cstddef>
#include <new>
#include "Stack.h"
using namespace std;

Stack::Stack() : topPtr(NULL)
{
}

Stack::Stack(const Stack& aStack)
{
	if(aStack.topPtr == NULL)
		topPtr = NULL;
	else {
		topPtr = new StackNode;
		topPtr -> item = aStack.topPtr -> item;
		StackNode *newPtr = topPtr;
		for (StackNode *origPtr = aStack.topPtr -> next; origPtr != NULL; origPtr = origPtr -> next)
		{
			newPtr -> next = new StackNode;
			newPtr = newPtr -> next;
			newPtr -> item = origPtr -> item;
		}
		newPtr -> next = NULL;
	}

}

Stack::~Stack()
{
	while(topPtr != NULL)
		Pop();
}

bool Stack::IsEmpty() const
{
	return topPtr == NULL;
}

void Stack::Push(const StackItemType& newItem)
{
	StackNode *newPtr = new StackNode;
	newPtr->item = newItem;
	newPtr-> next = topPtr;
	topPtr = newPtr;
}

void Stack::Pop()
{
	StackNode *temp = topPtr;
	topPtr = topPtr-> next;
	temp -> next = NULL;
	delete temp;
}

void Stack::pop(StackItemType& stackTop)
{
	stackTop = topPtr -> item;
	StackNode *temp = topPtr;
	topPtr = topPtr-> next;
	temp -> next = NULL;
	delete temp;
}
void Stack::GetTop(StackItemType& stackTop) const
{
	stackTop = topPtr -> item;
}