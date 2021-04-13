#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
	
}HeapType;

typedef struct {
	int s[MAX_ELEMENT];
	int top;
}StackType;


void initStack(StackType *stack) {
	stack->top = -1;
}

int isEmpty(StackType* stack) {
	if (stack->top < 0)
		return 1;
	else
		return 0;
}

void push(StackType* stack,int value) {
	stack->s[++(stack->top)] = value;
}

int pop(StackType* stack) {
	return stack->s[(stack->top)--];
}


void init(HeapType* h) {
	h->heap_size = 0;
}

void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i];

	//루트가 아니고 부모노드보다 삽입하려는 값이 작으면
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}


void insertItem(HeapType* h, int key) {
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("[%d] ", h->heap[i]);
	}
	printf("\n");
}
void binaryExpansion(int i, StackType* S) {
	while (i >= 2) {
		push(S, i % 2);
		i = i / 2;
	}
	push(S, i);
}
int findLastNode(HeapType* h, int n) {
	StackType s;
	initStack(&s);
	int v = 1;
	binaryExpansion(n, &s);
	pop(&s);
	while (!isEmpty(&s)) {
		int bit = pop(&s);
		if (bit == 0) {
			v = v * 2;
		}
		else {
			v = v * 2 + 1;
		}
	}
	return h->heap[v];
}

void main() {
	HeapType heap;
	init(&heap);
	insertItem(&heap, 10);
	insertItem(&heap, 6);
	insertItem(&heap, 4);
	insertItem(&heap, 14);
	insertItem(&heap, 9);
	insertItem(&heap, 12);
	insertItem(&heap, 8);
	insertItem(&heap, 2);
	insertItem(&heap, 11);
	insertItem(&heap, 9);
	
	
	printHeap(&heap);

	int lastnode = findLastNode(&heap, 10);
	printf("last node : %d", lastnode);


}
