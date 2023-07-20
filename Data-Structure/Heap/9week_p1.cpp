/*
MinHeap

명령어가 주어지면 그에 따른 동작을 수행한다

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap {
public:
	Heap() {
		size = 0;
		v.push_back(-1);
		root = 1;
	}

	void swap(int a, int b) {
		int tmp = v[a];
		v[a] = v[b];
		v[b] = tmp;
	}

	void insert(int x) {
		v.push_back(x);
		size++;
		upheap(size);
	}

	void upheap(int child) {
		int parent = child / 2;
		if (parent != 0 && child != root && v[parent] > v[child]) {
			swap(child, parent);
			upheap(parent);
		}
	}

	void sizeHeap() {
		cout << size << endl;
	}

	void inEmpty() {
		if (size == 0) cout << 1 << endl;
		else cout << 0 << endl;
	}

	void pop() {
		if (size == 0) cout << -1 << endl;
		else {
			cout << v[root] << endl;
			swap(root, size);
			v.pop_back();
			size--;
			downHeap(root);
		}
	}

	void downHeap(int parent) {
		int Lchild = parent * 2;
		int Rchild = parent * 2 + 1;
		int child = parent;

		if (Rchild <= size) { //양쪽에 모두 자식이 있다면
			
			if (v[Lchild] <= v[Rchild]) {
				child = Lchild;
			}
			else {
				child = Rchild;
			}
		}
		else if (Lchild <= size) { //왼쪽에만 자식이 있다면
			child = Lchild;
		}

		if (v[child] < v[parent]) {
			swap(child, parent);
			downHeap(child);
		}

	}

	void top() {
		if (size == 0) cout << - 1 << endl;
		else cout << v[root] << endl;
	}

	void print() {
		if (size == 0) cout << -1 << endl;
		else {
			for (int i = root; i <= size; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}

private:
	int size;
	vector<int> v;
	int root;
};


int main() {
	string str;
	int test = 0;
	cin >> test;

	Heap heap;

	for (int t = 0; t < test; t++) {
		cin >> str;

		if(str == "insert"){
			int x = 0;
			cin >> x;
			heap.insert(x);
		}
		else if (str == "size") {
			heap.sizeHeap();
		}
		else if (str == "isEmpty") {
			heap.inEmpty();
		}
		else if (str == "pop") {
			heap.pop();
		}
		else if (str == "top") {
			heap.top();
		}
		else if (str == "print") {
			heap.print();
		}

	}
	
}
