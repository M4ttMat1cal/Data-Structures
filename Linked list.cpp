#include <iostream>
struct node
{
	int data;
	node* next;
};
class linkedList
{
private:
	node* head;
	node* tail;
public:
	linkedList(): head(nullptr), tail(nullptr) {}
	void addNodeStart(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
		if (tail == nullptr) tail = temp;
	}
	void addNodePos(int pos, int value)
	{
		if (pos == 1) addNodeStart(value);
		else if (isEmpty()) std::cout << "Tiek elementu sarase nera\n";
		else
		{
			node* prev = head;
			for (int i = 1; i < pos - 1; i++)
			{
				prev = prev->next;
				if (prev == nullptr)
				{
					std::cout << "Tiek elementu sarase nera\n";
					return;
				}
			}
			node* temp = new node;
			temp->data = value;
			temp->next = prev->next;
			prev->next = temp;
			if (temp->next == nullptr) tail = temp;
		}
	}
	void addNodeEnd(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = nullptr;
		if (isEmpty())
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void deleteNodeStart()
	{
		if (isEmpty()) std::cout << "Sarasas tuscias\n";
		else
		{
			node* temp = head;
			head = head->next;
			delete temp;
			if (head == nullptr) tail = nullptr;
		}
	}
	void deleteNodePos(int pos)
	{
		if (pos == 1) deleteNodeStart();
		else
		{
			node* temp = head;
			for (int i = 1; i < pos - 1; i++)
			{
				temp = temp->next;
				if (temp->next == nullptr)
				{
					std::cout << "Tiek elementu sarase nera\n";
					return;
				}
			}
			node* cur = temp->next;
			temp->next = cur->next;
			delete cur;
			if (temp->next == nullptr) tail = temp;
		}
	}
	void deleteNodeEnd()
	{
		if (isEmpty()) std::cout << "Sarasas tuscias\n";
		else
		{
			node* temp = head;
			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
				delete temp;
			}
			else
			{
				while (temp->next != tail) temp = temp->next;
				delete tail;
				tail = temp;
				tail->next = nullptr;
			}
		}
	}
	void search(int value) //jeigu nera elemento, nieko neatspausdina
	{
		int valuepos = 0;
		node* temp = head;
		while (temp != nullptr)
		{
			valuepos++;
			if (temp->data == value) std::cout << valuepos << " ";
			temp = temp->next;
		}
		std::cout << '\n';
	}
	void display()
	{
		if (isEmpty()) std::cout << "Sarasas tuscias\n";
		else
		{
			node* temp = head;
			while (temp != nullptr)
			{
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << '\n';
		}
	}
	void clear() 
	{
		node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
	}
	void reverse()
	{
		node* pre = nullptr, * cur = head, * nxt = nullptr;
		tail = head;
		while (cur != nullptr)
		{
			nxt = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nxt;
		}
		head = pre;
	}
	bool isEmpty()
	{
		if (head == nullptr && tail == nullptr) return true;
		else return false;
	}
	~linkedList()
	{
		node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};
int main()
{
	linkedList listas;
	listas.search(2);
	return 0;
}