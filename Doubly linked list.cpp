#include <iostream>
struct node
{
	int data;
	node* prev;
	node* next;
};
class LinkedList
{
private:
	node* head;
	node* tail;
public:
	LinkedList(): head(nullptr), tail(nullptr) {}
	void addNodeStart(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->prev = nullptr;
		temp->next = head;
		if (isEmpty())
		{
			head = temp;
			tail = temp;
		}
		else
		{
			head->prev = temp;
			head = temp;
		}
	}
	void addNodePos(int position, int value)  //eh
	{
		int listsize = size();
		if (position > listsize + 1) std::cout << "Tiek elementu sarase nera\n";
		else if (position == 1) addNodeStart(value);
		else if (position == listsize + 1) addNodeEnd(value);
		else
		{
			node* newnode = new node;
			newnode->data = value;
			if (position <= (listsize / 2 + 1))
			{
				node* temp = head;
				for (int i = 1; i < position - 1; i++) temp = temp->next;
				newnode->next = temp->next;
				temp->next->prev = newnode;
				temp->next = newnode;
				newnode->prev = temp;
			}
			else
			{
				node* temp = tail;
				for (int i = listsize; i > position; i--) temp = temp->prev;
				temp->prev->next = newnode;
				newnode->prev = temp->prev;
				temp->prev = newnode;
				newnode->next = temp;
			}
		}
	}
	void addNodeEnd(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = nullptr;
		temp->prev = tail;
		if (isEmpty())
		{
			tail = temp;
			head = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void deleteNodeStart()
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else
		{
			node* temp = head;
			head = head->next;
			delete temp;
			if (head == nullptr) tail = nullptr;
			else head->prev = nullptr;
		}
	}
	void deleteNodePos(int position) //eh
	{
		int listsize = size();
		if (position > listsize) std::cout << "Tiek elementu sarase nera\n";
		else if (position == 1) deleteNodeStart();
		else if (position == listsize) deleteNodeEnd();
		else
		{
			if (position <= (listsize / 2))
			{
				node* prv = head;
				for (int i = 1; i < position - 1; i++) prv = prv->next;
				node* cur = prv->next;
				cur->next->prev = prv;
				prv->next = cur->next;
				delete cur;
			}
			else
			{
				node* nxt = tail;
				for (int i = listsize; i > position + 1; i--) nxt = nxt->prev;
				node* cur = nxt->prev;
				nxt->prev = cur->prev;
				cur->prev->next = nxt;
				delete cur;
			}
		}

	}
	void deleteNodeEnd()
	{
		if (isEmpty()) std::cout << "Nera ko trinti\n";
		else
		{
			node* temp = tail;
			tail = tail->prev;
			delete temp;
			if (tail == nullptr) head = nullptr;
			else tail->next = nullptr;
		}
	}
	void search(int value)
	{
		int position = 0;
		bool hasappeared = false;
		node* temp = head;
		while (temp != nullptr)
		{
			position++;
			if (temp->data == value)
			{
				std::cout << position << ' ';
				hasappeared = true;
			}
			temp = temp->next;
		}
		if (hasappeared) std::cout << '\n';
		else std::cout << "Tokio elemento sarase nera\n";
	}
	void display()
	{
		node* temp = head;
		if (isEmpty()) std::cout << "Sarasas tuscias\n";
		else
		{
			while (temp != nullptr)
			{
				std::cout << temp->data << ' ';
				temp = temp->next;
			}
			std::cout << '\n';
		}
	}
	int size()
	{
		int size = 0;
		node* start = head;
		node* end = tail;
		while (start != end && start->prev != end)
		{
			size += 2;
			start = start->next;
			end = end->prev;
		}
		if (start == end) size++;
		return size;
	}
	void reverse()
	{
		node* cur = head;
		node* temp;
		while (cur != nullptr)
		{
			temp = cur->next;
			cur->next = cur->prev;
			cur->prev = temp;
			cur = cur->prev;
		}
		temp = head;
		head = tail;
		tail = temp;
	}
	bool isEmpty()
	{
		if (head == nullptr && tail == nullptr) return true;
		else return false;
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
	~LinkedList()
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
	LinkedList list;
	list.addNodeEnd(1);
	list.addNodeEnd(2);
	list.addNodeEnd(3);
	list.deleteNodePos(2);
	list.display();
	list.addNodePos(2, 22);
	list.display();
	list.addNodePos(3, 222);
	list.display();
	list.reverse();
	list.display();
}