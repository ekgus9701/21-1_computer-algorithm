#include<stdio.h>
#include<stdlib.h>
void remove1(int A[], int n, int pos) {

	for (int i = pos; i < n; i++) {
		A[i] = A[i + 1];

	}

}

int runSimulation2(int A[], int n, int k) {
	int r = 0;

	while (n > 1) {
		r = (r + k) % n;
		remove1(A, n, r);

		n = n - 1;
	}
	return A[0];
}

void buildList(int A[], int n) {
	for (int r = 0; r < n; r++) {
		A[r] = r + 1;
	}
}
int main() {
	int n = 0;
	printf("양초 개수는?");
	scanf_s("%d", &n);
	int A = malloc(sizeof(int) * n);
	int k = 0;
	printf("몇개를 건너뛰어 불을 끌까?");
	scanf_s("%d", &k);
	buildList(A, n);

	int ans = runSimulation2(A, n, k);
	printf("%d", ans);

}
