#pragma once
#include"doubly_linked_list.h"
class queues {
	doubly_linked_list q;
public:
	queues() {
	}
	void Enqueue(char data) {
		q.add_to_tail(data);
	}
	char Dequeue() {
		return q.delete_from_head();
	}
	void display_queue() {
		q.display();
	}
	char peek() {
		return q.return_head_data();
	}
	bool is_empty() {
		if (q.is_empty()){
			return 1;
		}
		else return 0;
	}
};
