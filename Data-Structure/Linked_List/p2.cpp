/*
size가 10인 순환 연결 리스트 구현하고
delete x가 들어오면 head로부터 x번째에 있는 노드 삭제하는 예제
*/



#include <iostream>
#include <string>
using namespace std;

class Node {  //노드 생성
public:
	
	Node() {
		data = 0;
		next = NULL;
	}

	Node(int x) {
		data = x;
		next = NULL;
	}

	int data;
	Node* next;
};


class List {  //순환연결리스트 생성
public:
	List() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	~List() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void insertList(int x) {    //맨 뒤에 원소 추가
		Node* newnode = new Node(x);

		if (size == 0) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
			tail->next = head;
		}
		size++;
	}

	void deleteList(int p) {    //입력으로 들어온 번호의 노드 삭제
		Node* tmp1 = head;
		Node* tmp2 = head;
		
		if (p==0 || p==size) {  //삭제해야 할 노드가 head 일 때
			head = head->next;
			tmp1->next = NULL;
			tail->next = head;
		}
		else if (p == size - 1) {  //삭제해야 할 노드가 tail 일 때
			for (int P = 0; P < p - 1; P++) {
				tmp1 = tmp1->next;
			}
			tmp2 = tmp1->next;

			tail = tmp1;
			tail->next = head;
			tmp2->next = NULL;
		}
		else {  //삭제해야 할 노드가 중간에 있는 노드일 
			for (int P = 0; P < p - 1; P++) {
				tmp1 = tmp1->next;
			}
			tmp2 = tmp1->next;

			tmp1->next = tmp2->next;
			tmp2->next = NULL;
		}
		
		tmp1 = NULL;
		delete tmp1;
		delete tmp2;

		size--;
	}

	void printList() {    //전체 리스트 출력
		Node* tmp = head;

		for (int t = 0; t < size; t++) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

private:
	int size;
	Node* head;
	Node* tail;
};


int main() {

	int K = 0;
	cin >> K;
	
	string str;
	int x = 0;
  
	for (int k = 0; k < K; k++) {
		
		List list;

		for (int s = 0; s < 10; s++) {
			cin >> x;
			list.insertList(x);
		}

		for (int s = 0; s < 3; s++) {
			cin >> str;
			cin >> x;
			list.deleteList(x);
		}
		list.printList();

	}
}
