#include <iostream>
struct node
{
	int value;
	node* prev;
};
class Stack
{
private:
	node* top;
public:
	Stack() : top(nullptr) {};
	void push(int enteredvalue)
	{
		node* tempnode;
		tempnode = new node;
		tempnode->value = enteredvalue;
		tempnode->prev = top;
		top = tempnode;
	}
	void pop()
	{
		if (isEmpty()) std::cout << "Stack is empty\n";
		else
		{
			node* tempnode = top;
			top = top->prev;
			delete tempnode;
		}
	}
	int peek()
	{
		if (isEmpty()) return 0; //jei tuscias grazina 0
		else return top->value;
	}
	bool isEmpty()
	{
		if (top == nullptr) return true;
		else return false;
	}
	int size()
	{
		int stacksize = 0;
		node* tempnode = top;
		while (tempnode != nullptr)
		{
			tempnode = tempnode->prev;
			stacksize++;
		}
		return stacksize;
	}
	void clear()
	{
		node* tempnode = top;
		while (!isEmpty())
		{
			tempnode = top;
			top = top->prev;
			delete tempnode;
		}
		top = nullptr;
	}
	~Stack()
	{
		node* temp = top;
		while (!isEmpty())
		{
			temp = top;
			top = top->prev;
			delete temp;
		}
	}
};
void display(Stack &inputstack)
{
	if (inputstack.isEmpty()) std::cout << "Stack is empty\n";
	else
	{
		Stack tempstack;
		while (!inputstack.isEmpty())
		{
			std::cout << inputstack.peek() << ' ';
			tempstack.push(inputstack.peek());
			inputstack.pop();
		}
		std::cout << '\n';
		while (!tempstack.isEmpty())
		{
			inputstack.push(tempstack.peek());
			tempstack.pop();
		}
	}
}
int main()
{
	Stack s;
	display(s);
	display(s);
	std::cout << s.peek() << '\n';
	s.push(11);
	s.push(6666);
	s.push(4202);
	s.push(133);
	s.pop();
	display(s);
	display(s);
	s.pop();
	std::cout << s.peek();
	std::cout << s.size() << '\n';
	s.clear();
	std::cout << s.size() << '\n';
}