#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++) {
		before = before->link;
	}
	node->data = item;
	node->link = before->link;
	before->link = node;
}

void addLast(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	while (1) {
		if (before->link == NULL)
			break;
		before = before->link;
	}
	node->data = item;
	before->link = node;
	node->link = NULL; 
}

void removeFirst(LinkedListType* L) {
	ListNode* p = L->head;
	L->head = p->link;
}

void remove1(LinkedListType* L, int pos) {
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++) {
		before = before->link;
	}
	ListNode* p = before->link;
	before->link = p->link;

}

void removeLast(LinkedListType* L) {
	ListNode* before = L->head;
	while (1) {
		before = before->link;
		if (before->link->link == NULL)
			break;
	}
	before->link = NULL;

}
void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link) {
		printf("[%d] -> ", p->data);
	}
	printf("NULL\n");
}
int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 0; i < pos; i++)
		p = p->link;
	return p->data;
}
void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 0; i < pos; i++)
		p = p->link;
	p->data = item;
}

void main() {
	LinkedListType list;
	init(&list);
	printf("addFirst\n");
	addFirst(&list, 10);printList(&list);
	addFirst(&list, 20);printList(&list);
	addFirst(&list, 30);printList(&list);
	printf("\nadd\n");
	add(&list, 1, 40); printList(&list);
	add(&list, 2, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	printf("\naddLast\n");
	addLast(&list, 20); printList(&list);
	printf("\nremoveFirst\n");
	removeFirst(&list); printList(&list);
	printf("\nremove\n");
	remove1(&list, 1); printList(&list);
	printf("\nremoveLast\n");
	removeLast(&list); printList(&list);
	int pos;
	printf("\n�� �� ����� ���� ��ȯ�ұ��?");
	scanf_s("%d", &pos);
	printf("%d�� ����� ���� %d\n", pos, get(&list, pos));
	printf("\n�� �� ����� ���� �ٲܱ��?");
	int num;
	scanf_s("%d", &num);
	printf("\n������ �ٲܱ��?");
	int cng;
	scanf_s("%d", &cng);
	set(&list, num, cng);
	printList(&list);


}