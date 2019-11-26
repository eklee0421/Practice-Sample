#include<iostream>
#include<string>
using namespace std;

#define MappingSize 501

class vertex {
public:
	vertex* prev;
	vertex* next;
	int degree;		//vertex에 연결된 엣지들
	int data;
	vertex(int data) {
		this->degree = 0;
		this->data = data;
	}
	void increase_degree() {
		this->degree++;
	}
	void decrease_degree() {
		this->degree--;
	}
};

class edge {
public:
	edge* prev;
	edge* next;
	vertex* source;
	vertex* destination;
	string data;
	edge(vertex* a, vertex* b, string data) {
		this->source = a;
		this->destination = b;
		this->data = data;
	}
};

class DoublyVertexLinkedList {	//vertex로 이루어진 이중연결리스트
public:
	vertex* head;
	vertex* tail;
	DoublyVertexLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(vertex* insertVertex) {
		if (this->head == NULL) {
			head = insertVertex;
			tail = insertVertex;
		}
		else {
			tail->next = insertVertex;
			insertVertex->prev = tail;
			tail = insertVertex;
		}
	}
	void remove(vertex* delVertex) {
		if (delVertex == head || delVertex == tail) {
			if (delVertex == head && delVertex != tail) {
				vertex* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delVertex == tail && delVertex != head) {
				vertex* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
			else { head = tail = NULL; }
		}
		else {
			delVertex->prev->next = delVertex->next;
			delVertex->next->prev = delVertex->prev;
			delete delVertex;
		}
	}
};

class DoublyEdgeLinkedList {		//edge로 이루어진 이중연결 리스트
public:
	edge* head;
	edge* tail;
	DoublyEdgeLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(edge* insertEdge) {
		if (this->head == NULL) {
			head = insertEdge;
			tail = insertEdge;
		}
		else {
			tail->next = insertEdge;
			insertEdge->prev = tail;
			tail = insertEdge;
		}
	}
	void remove(edge* delEdge) {
		if (delEdge == head || delEdge == tail) {
			if (delEdge == head && delEdge != tail) {
				edge* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delEdge == tail && delEdge != head) {
				edge* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
			else { head = tail = NULL; }
		}
		else {
			delEdge->prev->next = delEdge->next;
			delEdge->next->prev = delEdge->prev;
			delete delEdge;
		}
	}
};

class graph {
public:
	edge*** edgeMatrix;				//edge정보를 관리하는 matrix
	DoublyVertexLinkedList* VertexList;		//전체 vertex 정보를 관리하는 이중연결리스트
	DoublyEdgeLinkedList* EdgeList;			//전체 edge 정보를 관리하는 이중연결 리스트
	int vertexSize;					//그래프에 존재하는 vertex의 개수
	int edgeSize;
	int mappingTable[MappingSize];			// vertex의 고유한 번호와
							// 해당 veretx의 matrix에서 index로 매칭
	graph() {
		this->VertexList = new DoublyVertexLinkedList();
		this->EdgeList = new DoublyEdgeLinkedList();
		this->vertexSize = 0;
		this->edgeSize = 0;
		for (int i = 0; i < MappingSize; i++)mappingTable[i] = -1;
		this->edgeMatrix = new edge * *[1];
		this->edgeMatrix[0] = new edge *[1];
		this->edgeMatrix[0][0] = NULL;
	}
	bool isfindVertex(int n) {		// VertexList에서 고유한 번호가 n인 vertex의 존재 유무 검사
		bool flag = false;
		vertex* temp = VertexList->head;
		while (temp != NULL) {
			if (temp->data == n) {
				flag = true;
				break;
			}
			temp = temp->next;
		}
		return flag;
	}
	vertex* findVertex(int n) {		// VertexList에서 고유한 번호가 n인
		vertex* temp = VertexList->head;    //vertex의 주소 반환
		while (temp != NULL) {
			if (temp->data == n) {
				break;
			}
			temp = temp->next;
		}
		return temp;
	}

	void insert_vertex(int n) {			// 그래프에 고유번호가 n인 vertex  삽입
		if (isfindVertex(n) == true) {
			cout << -1 << endl;
			return;
		}

		else {
			edge*** tempMatrix = new edge * *[vertexSize + 1];  //정점이 1개 추가 될 때마다 
			for (int i = 0; i < vertexSize + 1; i++) {        	//기존 matrix보다 가로, 세로 길이가 1만큼 
				tempMatrix[i] = new edge *[vertexSize + 1];	  //더 큰 tempmatrix 생성
				for (int j = 0; j < vertexSize + 1; j++) {
					tempMatrix[i][j] = NULL;
				}
			}

			for (int i = 0; i < vertexSize; i++) {
				for (int j = 0; j < vertexSize; j++) {
					tempMatrix[i][j] = this->edgeMatrix[i][j];	 //element들  copy
				}
			}

			this->edgeMatrix = tempMatrix;

			vertex* newVertex = new vertex(n);
			VertexList->insert(newVertex);			//VertexList에 고유번호가 n인 vertex 추가
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n;		// mappingtable에 vertex 자신이
		}							//matrix의 어느 index인지 저장
	}


	void erase_vertex(int n) {                          // 그래프에 고유한 번호가 n인 vertex 제거
		if (isfindVertex(n) == false || vertexSize == 0) {
			cout << -1 << endl;
			return;
		}
		else {
			edge*** tempMatrix = new edge * *[vertexSize - 1]; //정점이 1개 삭제될 때마다
			for (int i = 0; i < vertexSize - 1; i++) {       //기존 matrix보다 가로, 세로 길이가 1만큼
				tempMatrix[i] = new edge *[vertexSize - 1];   //더 작은 tempmatrix 생성
				for (int j = 0; j < vertexSize - 1; j++) {
					tempMatrix[i][j] = NULL;
				}
			}

			int middleIdx = 0;
			for (int i = 0; i < vertexSize; i++) {
				if (mappingTable[i] == n)middleIdx = i;		//middleidx: 삭제할 vertex의 matrix에서의 인덱스
			}
			for (int i = middleIdx; i < vertexSize; i++) {	// mappingtable update
				mappingTable[i] = mappingTable[i + 1];
			}


			for (int i = 0; i < vertexSize; i++) {	//EdgeList에서 고유번호가 n인 vertex와 연결된 모든 edge들 제거
				if (this->edgeMatrix[middleIdx][i] != NULL) {
					EdgeList->remove(this->edgeMatrix[middleIdx][i]);
					edgeSize--;
				}

			}

			for (int i = 0; i < vertexSize; i++) {			//middleidx를 기점으로 element들을 적절히 copy
				for (int j = 0; j < vertexSize; j++) {
					if (i < middleIdx && j < middleIdx) {
						tempMatrix[i][j] = this->edgeMatrix[i][j];
					}
					else if (i > middleIdx&& j > middleIdx) {
						tempMatrix[i - 1][j - 1] = this->edgeMatrix[i][j];
					}
					else if (j > middleIdx) {
						tempMatrix[i][j - 1] = this->edgeMatrix[i][j];
					}
					else if (i > middleIdx) {
						tempMatrix[i - 1][j] = this->edgeMatrix[i][j];
					}
				}
			}
			this->edgeMatrix = tempMatrix;
			VertexList->remove(findVertex(n));			//VertexList에 고유번호가 n인 vertex 제거
			this->vertexSize--;

			printDelV();	// 간선과 저장된 data 출력
		}
	}

	void insert_edge(int indirectSource, int IndirectDestination, string data) {		//그래프에 해당 edge 삽입
		if (isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false) {
			cout << -1 << endl;
			return;
		}

		int destination = -1;
		int source = -1;
		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == IndirectDestination)destination = i;	//indirectSourse는 vertex의 고유 번호
			if (mappingTable[i] == indirectSource)source = i;
			if (source != -1 && destination != -1)break;
		}

		if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL) {
			cout << -1 << endl;				// 삽입하려고 하는 edge가 이미 존재하는 경우
			return;
		}

		edge* newEdge = new edge(findVertex(indirectSource), findVertex(IndirectDestination), data);
		edgeMatrix[source][destination] = newEdge;		//martix에 해당 edge를 삽입
		edgeMatrix[destination][source] = newEdge;

		findVertex(indirectSource)->increase_degree();
		findVertex(IndirectDestination)->increase_degree();

		EdgeList->insert(newEdge);		//EdgeList에 해당 edge를 삽입
		edgeSize++;
	}

	void erase_edge(int indirectSource, int IndirectDestination) {		//그래프에 해당 edge 제거
		int destination = -1;
		int source = -1;
		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == IndirectDestination)destination = i;
			if (mappingTable[i] == indirectSource)source = i;
			if (source != -1 && destination != -1)break;
		}

		if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL)
			return;				//제거하려고 하는 edge가 이미 존재하지 않는 경우

		findVertex(indirectSource)->decrease_degree();
		findVertex(IndirectDestination)->decrease_degree();

		edge* delEdge = edgeMatrix[source][destination];
		EdgeList->remove(delEdge);		//EdgeList에서 해당 edge를 제거

		edgeMatrix[source][destination] = NULL;		//matrix에서 해당 edge를 제거
		edgeMatrix[destination][source] = NULL;
		edgeSize--;
	}

	void printG() {
		cout << vertexSize << " " << edgeSize << endl;
	}

	void isfindEdge(int indirectSource, int IndirectDestination) {
		int destination = -1;
		int source = -1;
		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == IndirectDestination)destination = i;	//indirectSourse는 vertex의 고유 번호
			if (mappingTable[i] == indirectSource)source = i;
			if (source != -1 && destination != -1)break;
		}

		if (edgeMatrix[source][destination] != NULL) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}

	void printDelV() {
		cout << edgeSize << " ";
		edge* p = EdgeList->head;
		for (int i = 0; i < edgeSize; i++) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

};

int main() {
	int n = 0, m = 0; //정점의 개수와 간선의 개수
	cin >> n >> m;

	int k = 0;	//삭제할 정점의 개수
	cin >> k;

	graph G;

	

	for (int N = 0; N < n; N++) {
		int i = 0;
		cin >> i;
		G.insert_vertex(i);
	}

	for (int M = 0; M < m; M++) {
		int s = 0, d = 0;	//두 개의 간선 정보
		cin >> s >> d;
		string u = "";	//저장될 문자열 U
		cin >> u;
		G.insert_edge(s, d, u);

	}

	G.printG();

	for (int K = 0; K < k; K++) {
		int l = 0;
		cin >> l;

		G.erase_vertex(l);	

	}

}
