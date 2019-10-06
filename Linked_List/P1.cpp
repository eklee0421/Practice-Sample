#include <iostream>
#include <string>
using namespace std;

class Node {
   friend class List;
private:
   int value;
   Node *next;
   Node(int v, Node *n) : value(v), next(n) {}
};

class List {
private:
   Node *head, *tail;
   int size = 0;
public:
   List(int);
   void addBack(int);
   void removeFront();
   void addFront(int);
   void showList();
   void front();
   void empty();
   ~List();
};

List::List(int v) {
   head = tail = new Node(v, NULL);
   size = 0;
}

void List::addBack(int value) {
   Node* newNode = new Node(value, NULL);
   if (head == NULL) head = newNode;
   else tail->next = newNode;
   tail = newNode;
   size++;
}

void List::removeFront() {
   if (head != NULL) {
      Node* removal = head;
      head = head->next;
      cout << removal << "\n";
      delete removal;
      size--;
   }
   else if (head == NULL) {
      cout << -1 << "\n";
   }
}

void List::addFront(int value) {
   Node* newNode = new Node(value, NULL);
   if (head == NULL) head = newNode;
   else {
      head->next = head;
      head = newNode;
   }
   size++;
}

void List::showList() {
   Node* scan = head;
   while (scan != NULL) {
      cout << scan->value << " ";
      scan = scan->next;
   }
   cout << "\n";
}

void List::front() {
   if (head == NULL) cout << -1 << "\n";
   else cout << head << "\n";
}

void List::empty() {
   if (size == 0) cout << 1 << "\n";
   else cout << 0 << "\n";
}

List::~List() {
   while (head != NULL) removeFront();
}

int main() {
   int N, x;
   string op;

   List list = List(NULL);

   cin >> N;

   while (N--) {
      cin >> op;

      if (op == "addFront") {
         cin >> x;
         list.addFront(x);
      }
      else if (op == "removeFront") {
         list.removeFront();
      }
      else if (op == "front") {
         list.front();
      }
      else if (op == "empty") {
         list.empty();
      }
      else if (op == "showList") {
         list.showList();
      }
      else if (op == "addBack") {
         cin >> x;
         list.addBack(x);
      }
   }
}
