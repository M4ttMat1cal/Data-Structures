#include <iostream>
struct node
{
	int data;
	node* prev;
	node* next;
};
class List
{
private:
	node* tail;
public:
	List(): tail(nullptr) {}
	void addNodeStart(int value)
	{
		node* temp = new node;
		temp->data = value;
		if (isEmpty())
		{
			temp->prev = temp;
			temp->next = temp;
			tail = temp;
		}
		else
		{
			temp->next = tail->next;
			temp->prev = tail;
			tail->next->prev = temp;
			tail->next = temp;
		}
	}
	void addNodePos(int position, int value) 
	{
		if (position < 0) std::cout << "Tokia pozicija neleidziama\n";
		else if (isEmpty())
		{
			node* temp = new node;
			temp->data = value;
			temp->next = temp;
			temp->prev = temp;
			tail = temp;
		}
		else
		{
			int listsize = size();
			node* temp = new node;
			temp->data = value;
			position = position % listsize;
			if (position == 0) position = listsize;
			if (position <= (listsize / 2 + 1))
			{
				node* prv = tail;
				for (int i = 0; i < position - 1; i++) prv = prv->next;
				temp->next = prv->next;
				temp->prev = prv;
				prv->next->prev = temp;
				prv->next = temp;
			}
			else
			{
				node* nxt = tail;
				for (int i = listsize; i > position; i--) nxt = nxt->prev;
				nxt->prev->next = temp;
				temp->prev = nxt->prev;
				nxt->prev = temp;
				temp->next = nxt;
			}
		}
	}
	void addNodeEnd(int value)
	{
		node* temp = new node;
		temp->data = value;
		if (isEmpty())
		{
			temp->prev = temp;
			temp->next = temp;
			tail = temp;
		}
		else
		{
			temp->next = tail->next;
			temp->prev = tail;
			tail->next->prev = temp;
			tail->next = temp;
			tail = temp;
		}
	}
	void deleteNodeStart()
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else if (tail == tail->next)
		{
			delete tail;
			tail = nullptr;
		}
		else
		{
			node* temp = tail->next;
			tail->next = temp->next;
			temp->next->prev = tail;
			delete temp;
		}
	}
	void deleteNodePos(int position)
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else
		{
			int listsize = size();
			if (position > listsize) std::cout << "Tiek elementu nera\n";
			else
			{
				if (position <= (listsize / 2))
				{
					node* prv = tail;
					for (int i = 0; i < position - 1; i++) prv = prv->next;
					node* cur = prv->next;
					cur->next->prev = prv;
					prv->next = cur->next;
					delete cur;
				}
				else
				{
					node* nxt = tail->next;
					for (int i = listsize; i > position; i--) nxt = nxt->prev;
					node* cur = nxt->prev;
					if (cur == tail) tail = cur->prev;
					nxt->prev = cur->prev;
					cur->prev->next = nxt;
					delete cur;
				}
			}
		}
	}
	void deleteNodeEnd()
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else if (tail == tail->next)
		{
			delete tail;
			tail = nullptr;
		}
		else
		{
			node* temp = tail->prev;
			temp->next = tail->next;
			tail->next->prev = temp;
			delete tail;
			tail = temp;
		}
	}
	void search(int value) //jei nera elemento nieko neisveda
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
		}
		std::cout << '\n';
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
	int size()
	{
		int size = 0;
		node* temp = tail->next;
		do
		{
			size++;
			temp = temp->next;
		} while (temp != tail->next);
		return size;
	}
	void reverse()
	{
		node* cur = tail;
		node* temp;
		do
		{
			temp = cur->next;
			cur->next = cur->prev;
			cur->prev = temp;
			cur = cur->prev;
		} while (cur != tail);
		tail = tail->prev;

	}
	bool isEmpty()
	{
		if (tail == nullptr) return true;
		else return false;
	}
	void clear() 
	{
		if (!isEmpty())
		{
			node* temp = tail->prev;
			node* deletion = temp;
			while (temp != tail)
			{
				deletion = temp;
				temp = temp->prev;
				delete deletion;
			}
			delete tail;
		}
		tail = nullptr;
	}
	~List()
	{
		if (!isEmpty())
		{
			node* temp = tail->prev;
			node* deletion = temp;
			while (temp != tail)
			{
				deletion = temp;
				temp = temp->prev;
				delete deletion;
			}
			delete tail;
		}
	}
};
int main()
{
	List L;
	L.addNodeEnd(22);
	L.addNodeEnd(44);
	L.addNodeEnd(66);
	L.addNodeEnd(7);
	L.display();
	L.deleteNodeEnd();
	L.display();
	L.addNodeEnd(44);
	L.addNodeStart(25);
	L.display();
}