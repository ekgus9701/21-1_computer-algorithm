//위상정렬
#include<stdio.h>
#include<stdlib.h>
typedef struct Edge {
	int vNum1;
	int vNum2;
	int isTree;
	struct Edge* next;
}Edge;

typedef struct IncidentEdge {
	int adjVertex;
	Edge* e;
	struct IncidentEdge* next;

}IncidentEdge;

typedef struct Vertex {
	int num;
	int isFresh;
	struct Vertex* next;
	IncidentEdge* top;
}Vertex;

Vertex* vHead = NULL;
Edge* eHead = NULL;
int vCount;
int eCount;
int in[6];

#define MAX_SIZE 10

typedef struct 
{
	int data[MAX_SIZE];
	int front, rear;
}Queue;


void initQueue(Queue* Q) {
	Q->front = 0;
	Q->rear = 0;
}
int is_empty(Queue* q) {
	return q->front == q->rear;
}

int is_full(Queue* q) {
	return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue* q, char item) {
	if (is_full(q)) exit(1);

	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

int dequeue(Queue* q) {
	if (is_empty(q)) exit(1);

	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

void queue_print(Queue* q) {
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

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

void insertEdges(int v1, int v2) {
	Edge* p = (Edge*)malloc(sizeof(Edge));
	p->vNum1 = v1;
	p->vNum2 = v2;
	p->isTree = 0;
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
	

}

void print() {
	Vertex* p = vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next) {
		printf("정점 %d : ", p->num);
		for (q = p->top; q != NULL; q = q->next)
			printf("[%d] ", q->adjVertex);
		printf("\n");
	}
}

void dfs(Vertex* v) {
	IncidentEdge* q;
	if (v->isFresh == 0) {
		printf("[%d] ", v->num);
		v->isFresh = 1;
	}

	for (q = v->top; q != NULL; q = q->next) {
		v = findVertex(q->adjVertex);
		if (v->isFresh == 0)
			dfs(v);
	}
}

void inDegree() {
	Vertex* p = vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next)
		for (q = p->top; q != NULL; q = q->next)
			in[q->adjVertex - 1]++;
}
void topologicalSort() {
	Queue q;
	initQueue(&q);
	Vertex* p;
	IncidentEdge* r;
	inDegree();

	for (int i = 0; i < 6; i++)
		if (in[i] == 0)
			enqueue(&q, i + 1);
	while (!is_empty(&q)) {
		int w = dequeue(&q);
		printf("[%d] ", w);
		p = findVertex(w);
		r = p->top;
		while (r != NULL) {
			in[r->adjVertex - 1]--;
			if (in[r->adjVertex - 1] == 0)
				enqueue(&q, r->adjVertex);
			r = r->next;
		}
	}

}
int main() {
	for (int i = 0; i < 6; i++)
		makeVertices();
	//ABCDEF를 123456으로 둠

	insertEdges(1, 2);
	insertEdges(1, 5);
	insertEdges(2, 3);
	insertEdges(4, 5);
	insertEdges(5, 2);
	insertEdges(5, 3);
	insertEdges(5, 6);
	insertEdges(6, 3);


	print();

	topologicalSort();
}
	