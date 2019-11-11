/*

이진 탐색 트리에서 몇번만에 검색에 성공하는지 출력하는 프로그램

깊이의 +1 번 만큼 걸린다

노드를 찾을 수 없는 경우 0을 출력한다

*/

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* parrent;
	Node* rChild;
	Node* lChild;

	// 생성자
	Node() {
		this->data = NULL;
		this->parrent = NULL;
		this->rChild = NULL;
		this->lChild = NULL;
		this->depth = 0;
	}
	Node(int data) {
		this->data = data;
		this->parrent = NULL;
		this->rChild = NULL;
		this->lChild = NULL;
		this->depth = 0;
	}
	// 소멸자
	~Node() {
	}
	// 왼쪽 자식에 추가
	void insertlChild(Node* lChild) {
		this->lChild = lChild;
		lChild->parrent = this;
		lChild->depth = this->depth + 1;
	}
	// 오른쪽 자식에 추가
	void insertrChild(Node* rChild) {
		this->rChild = rChild;
		rChild->parrent = this;
		rChild->depth = this->depth + 1;
	}
};

class BST {
public:
	Node* root;			// root 노드
	int height;			// 트리의 높이
	int size;

	// 생성자
	BST() {
		root = NULL;
		height = 0;
		size = 0;
	}
	// 소멸자
	~BST() {
		this->treeDestructor(this->root);
		size = 0;
	}
	// 노드 삽입 연산 (트리의 높이를 함께 고려)
	void insertNode(Node* tmp, int data) {
		if (size == 0) {
			Node* newnode = new Node(data);
			root = newnode;
			height = 0;
			size++;
		}
		else {
			if (tmp->data > data) {
				if (tmp->lChild != NULL) {
					insertNode(tmp->lChild, data);
				}
				else {
					Node* newnode = new Node(data);
					tmp->insertlChild(newnode);
					size++;
					if (height < newnode->depth) {
						height = newnode->depth;
					}
					size++;
				}
			}
			else if (tmp->data < data) {
				if (tmp->rChild != NULL) {
					insertNode(tmp->rChild, data);
				}
				else {
					Node* newnode = new Node(data);
					tmp->insertrChild(newnode);
					size++;
					if (height < newnode->depth) {
						height = newnode->depth;
					}
					size++;
				}
			}
		}
	}

	// 노드 탐색 연산
	Node* findNode(int data) {
		Node* tmp = root;
		while (tmp != NULL) {
			if (tmp->data == data)
				return tmp;
			else {
				if (tmp->data < data)
					tmp = tmp->rChild;
				else
					tmp = tmp->lChild;
			}
		}
		return NULL;
	}

	void printNum(int data) {
		Node* n = new Node(-1);
		if (findNode(data) != NULL) {
			n = findNode(data);
		}
		if (n->data == -1) {
			cout << 0 << endl;
		}
		else {
			cout << n->depth + 1 << endl;;
		}
	}

	// 후위 순회(post-order traversal)하며 트리의 모든 노드 삭제 (소멸자에서 사용)
	void treeDestructor(Node* root) {
		if (root == NULL)
			return;

		if (root->lChild != NULL)
			this->treeDestructor(root->lChild);
		if (root->rChild != NULL)
			this->treeDestructor(root->rChild);
		delete(root);
	}

	Node* Root() {
		return root;
	}

};

int main() {

	int test = 0;
	cin >> test;

	for (int t = 0; t < test; t++) {

		BST bst;

		int n = 0;
		cin >> n;
		for (int N = 0; N < n; N++) {
			int data = 0;
			cin >> data;
			bst.insertNode(bst.Root(), data);
		}

		int m = 0;
		cin >> m;
		for (int M = 0; M < m; M++) {
			int k = 0;
			cin >> k;
			bst.printNum(k);
		}
	}

	return 0;
}
