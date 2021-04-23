#include<stdio.h>
#include<stdlib.h>

#define SIZE 8
#define MAX_ELEMENT 100

typedef struct {
	int s[MAX_ELEMENT];
	int top;
}StackType;


void initStack(StackType* stack) {
	stack->top = -1;
}

int isEmpty(StackType* stack) {
	return (stack->top < 0);
}

void push(StackType* stack, int value) {
	stack->s[++(stack->top)] = value;
	
}

int pop(StackType* stack) {
	int k= stack->s[stack->top--];
	return k;
}

void spans(int X[], int S[]) {
	StackType A;
	initStack(&A);
	
	for (int i = 0; i < SIZE; i++) {
		
		while (!isEmpty(&A) && (X[A.s[A.top]] <= X[i])) {
			pop(&A);
		}
		
		if (isEmpty(&A)) {
			S[i] = i + 1;
		}
		

		else {
			S[i] = i - (A.s[A.top]);
		}
		printf("%d : %d  %d\n", i, S[i], A.top);
		push(&A,i);
		
	}
	while (!isEmpty(&A)) {
		pop(&A);
	}
}

void main() {
	int X[SIZE] = { 6,3,4,1,2,3,5,4 };
	int S[SIZE] = { 0 };
	
	spans(X, S);

	for (int i = 0; i < SIZE; i++)
		printf("[%d] ", S[i]);
	printf("\n");
}