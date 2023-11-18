#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {
	Node* head;

public:
	LinkedList() {
		head = NULL;
	}
	void add(int data);
	void printList();
	void del(int data);
};

void LinkedList::add(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL)
	{
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void LinkedList::del(int delData) {
	if (head == NULL)
	{
		cout << "List is empty\n";
		return;
	}
	Node* temp = head;
	Node* prev = NULL;

	while (temp != NULL && temp->data != delData)
	{
		prev = temp;
		temp = temp->next;
	}
	
	if (temp == NULL)
	{
		cout << "The value does not exist!\n";
		return;
	}

	if (prev == NULL)// the value is the first element
	{
		head = temp->next;
	}
	else
	{
		prev -> next = temp->next;
	}
	delete temp;
}

void LinkedList::printList()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	delete temp;
}

int main()
{
	LinkedList list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.printList();
	list.del(4);
	list.printList();
	return 0;
}