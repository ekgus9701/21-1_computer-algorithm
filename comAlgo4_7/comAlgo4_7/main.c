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
	int k = stack->s[stack->top--];
	return k;
}




void main() {
	StackType A;
	StackType B;
	initStack(&A);
	initStack(&B);
	//3,4,5 ³Ö±â
	push(&A, 3);
	push(&A, 4);
	push(&A, 5);
	push(&B, pop(&A));
	push(&B, pop(&A));
	push(&B, pop(&A));
	printf("%d ", pop(&B));
	printf("%d ", pop(&B));
	printf("%d ", pop(&B));


}
