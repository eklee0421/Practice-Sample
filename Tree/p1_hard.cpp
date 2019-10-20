#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:

	Node(int data) {
		this->data = data;
		this->parent = NULL;
		depth = 0;
	}

	void insertChild(Node* chi) {
		this->child.push_back(chi);
		return;
	}

	int data;
	Node* parent;
	vector<Node*> child;
	int depth;
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

	void insertNode(int parent_data, int data) {
		Node* node = new Node(data);
		Node* p = findNode(parent_data);
		p->insertChild(node);
		node->parent = p;
		node_list.push_back(node);
		node->depth = p->depth + 1;
		size++;
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

	void printChild(int data) {
		Node* n = findNode(data);
		for (int i = 0; i < n->child.size(); i++) {
			cout << n->child[i]->data << " ";
		}

	}

	void printDepth(int x) {
		Node* v = findNode(x);
		if (v == NULL) {
			cout << -1 << endl;
		}
		else {
			cout << v->depth << endl;
		}
	}

};

int main()
{
	int t = 0;
	cin >> t;
	string str;

	Tree tree(1);

	for (int T = 0; T < t; T++) {
		cin >> str;

		if (str == "insert") {
			int p = 0, d = 0;
			cin >> p >> d;
			tree.insertNode(p, d);
		}
		else if (str == "printChild") {
			int data = 0;
			cin >> data;
			tree.printChild(data);
			cout << endl;
		}
		else if (str == "printDepth") {
			int x = 0;
			cin >> x;
			tree.printDepth(x);
		}
	}
}
