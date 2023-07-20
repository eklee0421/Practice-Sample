//일반 트리 구현
//전위 순회 & 후위 순회

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:

	Node(int data) {
		this->data = data;
		this->parent = NULL;
		depth = 0;
		child_size = 0;
	}

	void insertChild(Node* chi) {
		this->child.push_back(chi);
		return;
	}

	int data;
	Node* parent;
	vector<Node*> child;
	int depth;
	int child_size;

};

class Tree {
private:
	Node* root;
	vector<Node*> node_list; //트리의 리스트
	int size;

public:
	Tree() {
		root = NULL;
		size = 0;
	}

	Tree(int data) {
		root = new Node(data);
		node_list.push_back(root); //리스트에 root 추가
		size = 1;
	}

	~Tree() {

		for (int i = size-1; i > 0; i--) {
			Node* de = node_list[i];
			delete de;
		}
	
		delete root;
		size = 0;

	}

	Node* getroot() {
		return root;
	}

	void insertNode(int parent_data, int data) {
		Node* node = new Node(data);
		Node* p = findNode(parent_data);
		p->insertChild(node);
		node->parent = p;
		node_list.push_back(node);
		node->depth = p->depth + 1;
		size++;
		p->child_size++;
	}

	Node* findNode(int data) {
		Node* v = NULL;
		for (int i = 0; i < this->node_list.size(); i++) {

			if (this->node_list[i]->data == data) {
				v = node_list[i];
				break;
			}
		}
		
		return v;
	}

	void visit(Node* node) {
		cout << node->data << " ";
	}

	void preorder(Node* node) { //전위 순회
		visit(node);
		if (node->child_size != 0) {
			for (int i = 0; i < node->child.size(); i++) {
				preorder(node->child[i]);
			}
		}
		return;
	}

	void postorder(Node* node) { //후위 순회
		if (node->child_size != 0) {
			for (int i = 0; i < node->child.size(); i++) {
				postorder(node->child[i]);
			}
		}
		visit(node);
		return;
	}

	void treeDepth() { //트리 전체의 깊이
		int Tdepth = 0;
		for (int i = 0; i < size; i++) {
			if (Tdepth < node_list[i]->depth) {
				Tdepth = node_list[i]->depth;
			}
		}
		cout << Tdepth << endl;
	}

};

int main()
{
	int test = 0;
	cin >> test;

	for (int T = 0; T < test; T++) {
		
		Tree tree(1);

		int n = 0;
		cin >> n;

		for (int num = 0; num < n; num++) {
			int p = 0, x = 0;
			cin >> p >> x;
			tree.insertNode(p, x);
		}

		tree.preorder(tree.getroot());
		cout << endl;
		tree.postorder(tree.getroot());
		cout << endl;
		tree.treeDepth();
	
	}
}

