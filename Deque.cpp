#include <iostream>
#include <stack>
#define MAXSIZE 10
class Dequearray
{
private:
	int front, back;
	char array[MAXSIZE] = { 0 };
public:
	Dequearray(): front(-1), back(-1) {}
	void pushFront(char value)
	{
		if (isFull()) std::cout << "Dekas yra pilnas, negalima prideti daugiau elementu\n";
		else if (isEmpty())
		{
			front = 0;
			back = 0;
			array[front] = value;
		}
		else
		{
			front--;
			if (front < 0) front = MAXSIZE - 1;
			array[front] = value;
		}
	}
	void pushBack(char value)
	{
		if (isFull()) std::cout << "Dekas yra pilnas, negalima prideti daugiau elementu\n";
		else
		{
			back++;
			if (back > MAXSIZE - 1) back = 0;
			array[back] = value;
			if (front == -1) front = 0;
		}
	}
	void popFront()
	{
		if (isEmpty()) std::cout << "Nera ko trint\n";
		else
		{
			if (front == back)
			{
				front = -1;
				back = -1;
			}
			else
			{
				front++;
				if (front > MAXSIZE - 1) front = 0;
			}
		}
	}
	void popBack()
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else
		{
			if (front == back)
			{
				front = -1;
				back = -1;
			}
			else
			{
				back--;
				if (back < 0) back = MAXSIZE - 1;
			}
		}
	}
	char peekFront() 
	{
		if (isEmpty()) return 0;
		else return array[front];
	}
	char peekBack()
	{
		if (isEmpty()) return 0;
		else return array[back];
	}
	bool isEmpty()
	{
		if (front == -1 && back == -1) return true;
		else return false;
	}
	bool isFull() 
	{
		if (front == 0 && back == MAXSIZE - 1) return true;
		else if ((front - back) == 1) return true;
		else return false;
	}
	void clear() 
	{
		front = -1;
		back = -1;
	}
	int count()
	{
		if (back >= front) return back - front + 1;
		else return back + MAXSIZE - front + 1;
	}
};
void display(Dequearray &displayarray)
{
	if (displayarray.isEmpty())
	{
		std::cout << "Nera ko rodyt lol\n";
		return;
	}
	char temp;
	for (int i = 0; i < displayarray.count(); i++)
	{
		temp = displayarray.peekFront();
		std::cout << temp << ' ';
		displayarray.popFront();
		displayarray.pushBack(temp);
	}
	std::cout << '\n';
}
void reverse1(Dequearray& inputarray) //rekursija
{
	if (inputarray.isEmpty()) return;
	char temp = inputarray.peekFront();
	inputarray.popFront();
	reverse1(inputarray);
	inputarray.pushBack(temp);
}
void reverse2(Dequearray& inputarray)
{
	std::stack<char> tempstack;
	while (!inputarray.isEmpty())
	{
		tempstack.push(inputarray.peekFront());
		inputarray.popFront();
	}
	while (!tempstack.empty())
	{
		inputarray.pushBack(tempstack.top());
		tempstack.pop();
	}
}
int main()
{
	Dequearray deque;
	reverse1(deque);
	display(deque);
	deque.pushBack('3');
	deque.pushFront('2');
	deque.pushFront(']');
	deque.pushFront('+');
	deque.pushBack('\'');
	display(deque);
	reverse2(deque);
	display(deque);
}