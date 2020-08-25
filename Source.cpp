#include <iostream>
using namespace std;
class Node {
	int data;
	Node *lptr;
	Node *rptr;
	Node *head;
	Node *tail;
	Node *current;
	Node *previous;
public:
	Node() :data(0), lptr(NULL), rptr(NULL), head(NULL), current(NULL), previous(NULL),tail(NULL) {}
	void add(int value);
	void getAll();
	void insert(int value);
	void remove(int value);
	void sort();
};
void Node::add(int value) {
	current = new Node;
	current->lptr = NULL;
	current->rptr = NULL;
	current->data = value;
	if (head == NULL)
		head = previous = tail=current;
	else {
		current->lptr = previous;
		previous->rptr = current;
		tail = current;
		previous = current;
	}
}
void Node::getAll() {
	if (head == NULL)
		cout << "List Empty !\n";
	else {
		current = head;
		while (current) {
			cout << current->data << " ";
			current = current->rptr;
		}
		cout << endl;
	}
}
void Node::insert(int value) {
	bool isInserted = false;
	Node *newNode = new Node;
	newNode->lptr = NULL;
	newNode->rptr = NULL;
	newNode->data = value;
	if (head == NULL)
		head = newNode;
	else {
		if (newNode->data <= head->data) {
			newNode->rptr = head;
			head->lptr = newNode;
			head = newNode;
		}
		else {
			current = previous = head;
			while (current) {
				if (newNode->data >= current->data) {
					previous = current;
					current = current->rptr;
				}
				else {
					newNode->rptr = current;
					current->lptr = newNode;
					previous->rptr = newNode;
					newNode->lptr = previous;
					isInserted = true;
					break;
				}
			}
			if (!isInserted) {
				previous->rptr = newNode;
				newNode->lptr = previous;
			}
		}
	}
}
void Node::sort() {
	if (head == NULL)
		cout << "List is empty!\n";
	else {
		previous = current = head;
		while (current) {
			while (current) {
				if (previous->data > current->data) {
					swap(previous->data, current->data);
					current = head;
					break;
				}
				else {
					previous = current;
					current = current->rptr;
				}
			}
		}
	}
}
void Node::remove(int value) {
	if (head == NULL)
		cout << "List is Empty!\n";
	else {
		if (value == head->data) {
			current = head;
			head = head->rptr;
			delete current;
		}
		else {
			previous = current = head;
			while (current) {
				if (value == current->data) {
					previous->rptr = current->rptr;
					delete current;
					break;
				}
				else {
					previous = current;
					current = current->rptr;
				}
			}
		}
	}
}
int main() {
	Node node;
	int choice;
	int integer;
	while (true) {
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t                MENU                \n";
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t             1. Add     [node]      \n";
		cout << "\t\t\t             2. Display [List]      \n";
		cout << "\t\t\t             3. Insert              \n";
		cout << "\t\t\t             4. Sort                \n";
		cout << "\t\t\t             5. Remove              \n";
		cout << "\t\t\t             6. EXIT                \n";
		cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter a data(integer) you want to add:";
			cin >> integer;
			node.add(integer);
			break;
		case 2:
			node.getAll();
			break;
		case 3:
			cout << "Enter an integer you want to insert:";
			cin >> integer;
			node.insert(integer);
			break;
		case 4:
			node.sort();
			break;
		case 5:
			cout << "Enter an integer you want to remove:";
			cin >> integer;
			node.remove(integer);
			break;
		case 6:
			exit(-1);
		default:
			cout << "Invalid Option\n";

		}
	}
	system("pause");
	return 0;
}