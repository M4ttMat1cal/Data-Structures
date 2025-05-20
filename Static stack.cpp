#include <iostream>
#define MAXSIZE 5
class Stack {
private:
	int top;
	int array[MAXSIZE];
public:
	Stack() : top(-1) {};
	void push(int value)
	{
		if (isFull()) std::cout << "Stack is full \n";
		else
		{
			top++;
			array[top] = value;
		}
	}
	void pop()
	{
		if (isEmpty()) std::cout << "Stack is empty \n";
		else top--;
	}
	int peek()
	{
		if (isEmpty()) return 0; //grazina 0 kai sarasas tuscias
		else return array[top];
	}
	bool isEmpty()
	{
		if (top == -1) return true;
		else return false;
	}
	bool isFull()
	{
		if (top == MAXSIZE - 1) return true;
		else return false;
	}
	int size() { return top + 1; }
	void clear() { top = -1; }
};
void display(Stack displaystack)
{
	if (displaystack.isEmpty()) std::cout << "Stack is empty\n";
	else
	{
		Stack tempstack;
		while (!displaystack.isEmpty())
		{
			std::cout << displaystack.peek() << ' ';
			tempstack.push(displaystack.peek());
			displaystack.pop();
		}
		std::cout << '\n';
		while (!tempstack.isEmpty())
		{
			displaystack.push(tempstack.peek());
			tempstack.pop();
		}
	}
}
int main()
{
	Stack s;
	display(s);
}