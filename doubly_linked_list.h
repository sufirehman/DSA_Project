#pragma once
#include<iostream>
using namespace std;
class node {
public:
	char data;
	node* next;
	node* previous;
	
	node();
	node(char, node * , node *);
	node(node& rhs);
	~node() {
	}
};
node::node() {
	next = 0;
	previous = 0;
}
node::node(char d = 0, node *n = NULL, node *p = NULL) {
	data = d;
	next = n;
	previous = p;
}
node::node(node& rhs) {
	data = rhs.data;
	next = rhs.next;
	previous = rhs.previous;
}
class doubly_linked_list {
	node *head;
	node *tail;
	int size;
public:
	doubly_linked_list();
	doubly_linked_list(char d);
	void add_to_head(char d);
	void add_to_tail(char d);
	void display();
	char delete_from_head();
	char delete_from_tail();
	int get_size();
	char return_head_data();
	bool is_empty();
};
doubly_linked_list::doubly_linked_list() {
	head = 0;
	tail = 0;
}
doubly_linked_list::doubly_linked_list(char d) {
	head = new node(d);
	tail = head;
}
void doubly_linked_list::add_to_head(char d) {
	if (head == NULL) {
		head = tail = new node(d);
	}
	else {
		head = new node(d, head);
		head->next->previous = head;
	}
}
void doubly_linked_list::add_to_tail(char d) {
	if (tail == NULL) {
		head = tail = new node(d);
	}
	else {
		tail = new node(d, NULL, tail);
		tail->previous->next = tail;
	}
}
void doubly_linked_list::display() {
	node *temp = head;
	cout << endl;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << endl;
}
char doubly_linked_list::delete_from_head() {
	if (head == NULL) {
		cout << "list is empty";
	}
	else if (head == tail) {
		char temp = head->data;
		delete head;
		head = tail = NULL;
		return temp;
	}
	else {
		char temp2 = head->data;
		node *temp = head;
		head = head->next;
		head->previous = NULL;
		delete temp;
		return temp2;
	}
	return 0;
}
char doubly_linked_list::delete_from_tail() {
	if (tail == NULL) {
		cout << "list is empty";
	}
	else if (tail == head) {
		char temp = tail->data;
		delete tail;
		tail = head = NULL;
		return temp;
	}
	else {
		char temp2 = tail->data;
		node* temp = tail;
		tail = tail->previous;
		tail->next = NULL;
		delete temp;
		return temp2;
	}
	return 0;
}
int doubly_linked_list::get_size() {
	return size;
}
char doubly_linked_list::return_head_data() {
	if (head != 0)
		return head->data;
	return 'a';
}
bool doubly_linked_list::is_empty() {
	if (head ==NULL&& tail==NULL) {
		return 1;
	}
	else return 0;
}
