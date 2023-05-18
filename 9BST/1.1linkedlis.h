#include<iostream>
using namespace std;
class Node {

public:
	int data;
	Node * next;

	//constructor.
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

void print(Node * head) {

	Node * temp =  head; //now head will remain intact.

	while (temp != NULL) {
		cout << temp -> data << " " ;
		temp = temp -> next;
	}
	//if we don't wanna print the tail node we can put head-> next !=  null in the loop.
}


Node * takeinput_better() {
	int data;

	cin >> data;
	Node * head = NULL;
	Node * tail = NULL;

	while (data != -1) {
		Node * newNode = new Node(data);
		if (head == NULL and tail == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
			//or 
			//tail = newNode;
		}

		cin >> data;
	}


	return head;

}