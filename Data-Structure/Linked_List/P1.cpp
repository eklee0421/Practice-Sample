#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node(int x){
		data = x;
		next = NULL;
	}
	int data;
	Node* next;
};

class SLinkedList {
public:

	SLinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void addFront(int x) {
		Node* node = new Node(x);
		if (size==0) {
			head = node;
			tail = node;
		}
		else {
			node->next = head;
			head = node;
		}
		size++;
	}

	void removeFront() {
		if (size == 0) cout << -1 << endl;
		else if (size == 1) {
			cout << head->data << endl;
			head = NULL;
			tail = NULL;
		}
		else {
			Node* de = new Node(0);
			de = head;
			cout << head->data << endl;
			head = head->next;
			delete de;
		}
		size--;
	}

	void front() {
		if (size == 0) cout << -1 << endl;
		else {
			cout << head->data << endl;
		}
	}

	void empty() {
		if (size == 0) cout << 1 << endl;
		else cout << 0 << endl;
	}

	void showList() {
		if (size == 0) cout << -1 << endl;
		else {
			Node* count = new Node(0);
			count = head;
			for (int j = 0; j < size; j++) {
				cout << count->data << " ";
				count = count->next;
			}
			cout << endl;
		}
	}

	void addBack(int x) {
		Node* node = new Node(x);
		if (size == 0) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}	
		size++;
	}

private:
	int size;
	Node* head;
	Node* tail;
};

int main() {
	
	string str;

	int t = 0;
	cin >> t;
	
	SLinkedList List;

	for (int T = 0; T < t; T++) {
		cin >> str;

		if (str == "addFront") {
			int x = 0;
			cin >> x;
			List.addFront(x);
		}
		else if (str == "removeFront") {
			List.removeFront();
		}
		else if (str == "front") {
			List.front();
		}
		else if (str == "empty") {
			List.empty();
		}
		else if (str == "showList") {
			List.showList();
		}
		else if (str == "addBack") {
			int x = 0;
			cin >> x;
			List.addBack(x);
		}
	}
} 
