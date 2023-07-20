#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxHeap {
public:
	MaxHeap() {
		size = 0;
		v.push_back(-1);
		v2.push_back(-1);
		root = 1;
	}

	~MaxHeap() {
		v.clear();
		v2.clear();
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
		if (parent != 0 && child != root && v[parent] < v[child]) {
			swap(child, parent);
			upheap(parent);
		}
	}

	void pop() {
		if (size == 0) cout << -1 << endl;
		else {
			v2.push_back(v[root]);
			if (size != 1) {
				swap(root, size);
				v.pop_back();
				size--;
				downHeap(root);
			}
		}
	}

	void downHeap(int parent) {
		int Lchild = parent * 2;
		int Rchild = parent * 2 + 1;
		int child = parent;

		if (Rchild <= size) { //양쪽에 모두 자식이 있다면

			if (v[Lchild] >= v[Rchild]) {
				child = Lchild;
			}
			else {
				child = Rchild;
			}
		}
		else if (Lchild <= size) { //왼쪽에만 자식이 있다면
			child = Lchild;
		}

		if (v[child] > v[parent]) {
			swap(child, parent);
			downHeap(child);
		}

	}

	void printV(int p) {
		//cout << "v: ";
		cout << v[p] << endl;
	}

	void printV2(int p) {
		//cout << "v2: ";
		cout << v2[p] << endl;
	}

private:
	int size;
	vector<int> v;
	vector<int> v2;
	int root;
};


class MinHeap {
public:
	MinHeap() {
		size = 0;
		v.push_back(-1);
		v2.push_back(-1);
		root = 1;
	}

	~MinHeap() {
		v.clear();
		v2.clear();
		
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

	void pop() {
		if (size == 0) cout << -1 << endl;
		else {
			v2.push_back(v[root]);
			if (size != 1) {
				swap(root, size);
				v.pop_back();
				size--;
				downHeap(root);
			}
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

	void printV(int p) {
		cout << v[p] << endl;
	}

	void printV2(int p) {
		cout << v2[p] << endl;
	}

private:
	int size;
	vector<int> v;
	vector<int> v2;
	int root;
};


int main() {
	string str;
	int test = 0;
	cin >> test;

	int n = 0, p = 0;

	for (int t = 0; t < test; t++) {

		MinHeap minheap;
		MaxHeap maxheap;

		cin >> n >> p;

		for (int i = 0; i < n; i++) {
			int x = 0;
			cin >> x;
			minheap.insert(x);
			maxheap.insert(x);
		}
	
		minheap.printV(p);

		for (int i = 1; i <= n; i++) { 
			minheap.pop();
		}

		minheap.printV2(p);

		maxheap.printV(p);

		for (int i = 1; i <= n; i++) {
			maxheap.pop();
		}

		maxheap.printV2(p);
	}

}
