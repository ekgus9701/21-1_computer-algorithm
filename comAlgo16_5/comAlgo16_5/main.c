//��������
#include<stdio.h>
#include<stdlib.h>
typedef struct Edge {
	int vNum1;
	int vNum2;
	int weight;
	struct Edge* next;
}Edge;

typedef struct IncidentEdge {
	int adjVertex;
	int weight;
	Edge* e;
	struct IncidentEdge* next;

}IncidentEdge;

typedef struct Vertex {
	int num;
	int isFresh;
	struct Vertex* next;
	IncidentEdge* top;
}Vertex;

#define N 7
#define INF 10000

Vertex* vHead = NULL;
Edge* eHead = NULL;
int vCount;
int eCount;
int dist[N];




void makeVertices() {
	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
	p->num = ++vCount;
	p->top = NULL;
	p->next = NULL;
	p->isFresh = 0;
	Vertex* q = vHead;
	if (q == NULL)
		vHead = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

Vertex* findVertex(int v) {
	Vertex* p = vHead;
	while (p->num != v)
		p = p->next;
	return p;
}

void insertIncidentEdge(Vertex* v, int av, Edge* e) {
	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	p->adjVertex = av;
	p->weight = e->weight;
	p->e = e;
	p->next = NULL;
	IncidentEdge* q = v->top;
	if (q == NULL)
		v->top = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

void insertEdges(int v1, int v2, int w) {
	Edge* p = (Edge*)malloc(sizeof(Edge));
	p->vNum1 = v1;
	p->vNum2 = v2;
	p->weight = w;
	p->next = NULL;
	Edge* q = eHead;
	if (q == NULL)
		eHead = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	Vertex* v = findVertex(v1);
	insertIncidentEdge(v, v2, p);
	v = findVertex(v2);
	insertIncidentEdge(v, v1, p);


}

int getMinVertex() {
	int v = 0;
	Vertex* p = vHead;
	for (; p != NULL; p = p->next) {
		if (p->isFresh == 0) {
			v = p->num - 1;
			break;
		}
	}
	for (p = vHead; p != NULL; p = p->next) {
		if (p->isFresh == 0 && (dist[p->num - 1] < dist[v]))
			v = p->num - 1;

	}

	return v;

}


void print() {
	Vertex* p = vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next) {
		printf("���� %d : ", p->num);
		for (q = p->top; q != NULL; q = q->next)
			printf("[%d (%d)] ", q->adjVertex, q->weight);
		printf("\n");
	}
}

Edge* e[14];
#define SWAP(x,y,t) (t=x,x=y,y=t)

void printEdge() {
	Edge* p = eHead;
	int i = 0;
	for (; p != NULL; p = p->next)
		e[i++] = p;

	int least, temp;
	//������������ ����
	for (i = 0; i < 13; i++) {
		least = i;
		for (int j = i + 1; j < 14; j++)
			if (e[j]->weight < e[least]->weight)
				least = j;
		SWAP(e[i], e[least], temp);
	}
	/*for (i = 0; i < 14; i++)
		printf("[%d - %d (%d)]", e[i]->vNum1, e[i]->vNum2, e[i]->weight);
	printf("\n");*/
}

int v[N];

void initSet() {
	for (int i = 0; i < N; i++) {
		v[i] = -1;
	}
}

int vFind(int vNum) {
	if (v[vNum] == -1)
		return vNum;
	while (v[vNum] != -1)
		vNum = v[vNum];
	return vNum;
}

void vUnion(int vNum1, int vNum2) {
	int r1 = vFind(vNum1);
	int r2 = vFind(vNum2);

	if (r1 != r2)
		v[r2] = r1;
}

void kruskal() {
	int eCount = 0;
	int v1, v2;
	int i = 0;
	initSet();
	Edge* p;

	while (eCount < N) {
		p = e[i];
		v1 = vFind(p->vNum1 - 1);
		v2 = vFind(p->vNum2 - 1);

		if (v1 != v2) {
			printf("���� [%d - %d (%d)] ����\n", p->vNum1, p->vNum2, p->weight);
			eCount++;
			vUnion(v1, v2);
		}
		i++;
	}
}

int main() {
	for (int i = 0; i < N; i++)
		makeVertices();


	insertEdges(1, 2, 10);
	insertEdges(1, 3, 15);
	insertEdges(1, 4, 8);
	insertEdges(1, 5, 27);
	insertEdges(2, 4, 25);
	insertEdges(2, 5, 4);
	insertEdges(3, 4, 13);
	insertEdges(3, 6, 32);
	insertEdges(3, 7, 8);
	insertEdges(4, 5, 10);
	insertEdges(4, 6, 19);
	insertEdges(4, 7, 22);
	insertEdges(5, 7, 25);
	insertEdges(6, 7, 15);


	printEdge();
	kruskal();


}
