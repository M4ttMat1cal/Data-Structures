#include <iostream>
struct node
{
	int data;
	node* next;
};
class LinkedList
{
private:
	node* tail;
public:
	LinkedList(): tail(nullptr) {}
	void addNodeStart(int value)
	{
		node* temp = new node;
		temp->data = value;
		if (isEmpty())
		{
			temp->next = temp;
			tail = temp;
		}
		else
		{
			temp->next = tail->next;
			tail->next = temp;
		}
	}
	void addNodePos(int position, int value)
	{
		node* temp = new node;
		temp->data = value;
		if (isEmpty())
		{
			temp->next = temp;
			tail = temp;
		}
		else
		{
			node* prev = tail;
			for (int i = 0; i < position - 1; i++) prev = prev->next;
			temp->next = prev->next;
			prev->next = temp;
		}
	}
	void addNodeEnd(int value)
	{
		node* temp = new node;
		temp->data = value;
		if (isEmpty())
		{
			temp->next = temp;
			tail = temp;
		}
		else
		{
			temp->next = tail->next;
			tail->next = temp;
			tail = temp;
		}
	}
	void deleteNodeStart() 
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else
		{
			node* temp = tail->next;
			if (temp == tail)
			{
				delete tail;
				tail = nullptr;
			}
			else
			{
				tail->next = temp->next;
				delete temp;
			}
		}
	}
	void deleteNodePos(int position)
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else
		{
			node* prev = tail;
			for (int i = 0; i < position - 1; i++)
			{
				prev = prev->next;
				if (prev == tail)
				{
					std::cout << "Tiek elementu sarase nera\n";
					return;
				}
			}
			if (prev->next == tail) tail = prev;
			node* cur = prev->next;
			prev->next = cur->next;
			delete cur;
		}
	}
	void deleteNodeEnd() 
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else
		{
			node* temp = tail->next;
			if (temp == tail)
			{
				delete tail;
				tail = nullptr;
			}
			else
			{
				while (temp->next != tail) temp = temp->next;
				temp->next = tail->next;
				delete tail;
				tail = temp;
			}
		}
	}
	void search(int value) //jei elemento nera nieko neisveda
	{
		if (!isEmpty())
		{
			int position = 0;
			node* temp = tail->next;
			do
			{
				position++;
				if (temp->data == value) std::cout << position << ' ';
				temp = temp->next;
			} while (temp != tail->next);
			std::cout << '\n';
		}
	}
	void display()
	{
		if (isEmpty()) std::cout << "Sarasas tuscias\n";
		else
		{
			node* temp = tail->next;
			do
			{
				std::cout << temp->data << ' ';
				temp = temp->next;
			} while (temp != tail->next);
			std::cout << '\n';
		}
	}
	void clear() 
	{
		if (!isEmpty())
		{
			node* temp = tail->next;
			node* deletion = temp;
			while (temp != tail)
			{
				deletion = temp;
				temp = temp->next;
				delete deletion;
			}
			delete tail;
			tail = nullptr;
		}
	}
	void reverse() 
	{
		node* prev = tail, * cur = tail->next, * nxt = nullptr;
		tail = cur;
		while (nxt != tail)
		{
			nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
	}
	bool isEmpty()
	{
		if (tail == nullptr) return true;
		else return false;
	}
	~LinkedList()
	{
		if (!isEmpty())
		{
			node* temp = tail->next;
			node* deletion = temp;
			while (temp != tail)
			{
				deletion = temp;
				temp = temp->next;
				delete deletion;
			}
			delete tail;
		}
	}
};
int main()
{
	LinkedList L;
	L.addNodeStart(22);
	L.addNodeEnd(44);
	L.addNodeEnd(222);
	L.addNodeStart(2222);
	L.addNodePos(2, 666);
	L.addNodePos(5, 3333);
	L.display();
	L.deleteNodePos(7);
	L.display();
	L.addNodeStart(22111);
	L.display();
	L.reverse();
	L.display();
	L.addNodeStart(69);
	L.addNodeEnd(909);
	L.display();
}