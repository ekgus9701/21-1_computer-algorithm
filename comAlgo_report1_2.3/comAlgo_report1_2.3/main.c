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

LinkedListType* buildList(int n) {
	LinkedListType *L= (LinkedListType*)malloc(sizeof(LinkedListType));
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	L->head = p;
	p->data = 1;
	for (int i = 2; i <= n; i++) {
		
		p->link = (ListNode*)malloc(sizeof(ListNode));
		p = p->link;
		p->data = i;
		
	}
	p->link = L->head;
	return L;

}
void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link) {
		printf("[%d] -> ", p->data);
	}
	printf("NULL\n");
}
int runSimulation3(LinkedListType* L, int n, int k) {
	ListNode* p = L->head;
	
	while (p != p->link) {
		for (int i = 1; i < k; i++) {
			p = p->link;
		}
		ListNode* plink = p->link;
		p->link = p->link->link;
		free(plink);
		p = p->link;
	}
	
	return p->data;
}
int main() {
	
	LinkedListType* L;
	
	int n = 0;
	printf("양초 개수는?");
	scanf_s("%d", &n);
	
	int k = 0;
	printf("몇개를 건너뛰어 불을 끌까?");
	scanf_s("%d", &k);
	L = buildList(n);
	
	
	int ans = runSimulation3(L, n, k);
	printf("%d", ans);
}