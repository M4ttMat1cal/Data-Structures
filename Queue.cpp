#include <iostream>
#include <stack>
#define MAXSIZE 5

class QueueArray
{
private:
	int front, back;
	char queue[MAXSIZE] = { 0 };

public:
	QueueArray()
	{
		front = -1;
		back = -1;
	}
	void enqueue(char value)
	{
		if (isFull())
		{
			std::cout << "Eile yra uzpildyta, negalima prideti naujo elemento. \n";
		}
		else
		{
			back++;
			if (back > MAXSIZE - 1) back = 0;
			queue[back] = value;
			if (front == -1) front = 0;
		}
	}
	void dequeue()
	{
		if (isEmpty()) std::cout << "Negalima nieko trinti\n";
		else if (front == back)
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
	char peekFirst()
	{
		if (isEmpty()) return 0;
		else return queue[front];
	}
	char peekLast()
	{
		if (isEmpty()) return 0;
		else return queue[back];
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
	int frontindex() { return front; }
	int backindex() { return back; }
};
void display(QueueArray &displayqueue)
{
	int front = displayqueue.frontindex();
	int back = displayqueue.backindex();
	int count;
	char temp;
	if (back >= front) count = back - front + 1;
	else count = back + MAXSIZE - front + 1;
	for (int i = 0; i < count; i++)
	{
		temp = displayqueue.peekFirst();
		std::cout << temp << ' ';
		displayqueue.dequeue();
		displayqueue.enqueue(temp);
	}
	std::cout << '\n';
}
void reverse(QueueArray &inputqueue) 
{
	std::stack<char> tempstack;
	while (!inputqueue.isEmpty())
	{
		tempstack.push(inputqueue.peekFirst());
		inputqueue.dequeue();
	}
	while (!tempstack.empty())
	{
		inputqueue.enqueue(tempstack.top());
		tempstack.pop();
	}
}
int main()
{
	QueueArray q;
	q.enqueue('a');
	display(q);
	q.enqueue('b');
	display(q);
	q.enqueue('c');
	display(q);
	q.enqueue('d');
	display(q);
	q.enqueue('e');
	display(q);
	q.enqueue('m');
	display(q);
	q.enqueue('k');
	display(q);

	q.dequeue();
	q.dequeue();
	display(q);
	q.enqueue('z');
	q.enqueue('x');
	q.enqueue('y');
	display(q);
	reverse(q);
	display(q);
	reverse(q);
	display(q);
	q.enqueue('w');
	q.dequeue();
	display(q);
	return 0;
}