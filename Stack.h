typedef char StackItemType;

class Stack
{
public:
	Stack();
	Stack(const Stack& aStack);
	~Stack();
	bool IsEmpty() const;
	void Push(const StackItemType& newItem);
	void Pop();
	void pop(StackItemType& stackTop);
	void GetTop(StackItemType& stackTop) const;
private:
	struct StackNode
	{
		StackItemType item;
		StackNode *next;
	};
	StackNode *topPtr;
};