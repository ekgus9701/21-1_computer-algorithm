#include<stdio.h>
#include<stdlib.h>

int runSimulation(int A[],int n, int k) {
	int r = 0;
	int N = n;
	while (n > 1) {
		int i = 0;
		while (i < k) {
			r = (r + 1) % N;
			if (A[r] != 0)
				i = i + 1;
		}
		A[r] = 0;
		n = n - 1;
		while (A[r] == 0) {
			r = (r + 1) % N;
		}

	}
	return A[r];

}

void buildList(int A[], int n) {
	for (int r = 0; r < n; r++) {
		A[r] = r + 1;
		
	}
	return;
}
int main() {
	int n=0;
	printf("양초 개수는?");
	scanf_s("%d", &n);
	int* A = malloc(sizeof(int) * n);
	int k=0;
	printf("몇개를 건너뛰어 불을 끌까?");
	scanf_s("%d", &k);
	buildList(A, n);
	int ans = runSimulation(A, n, k);
	printf("%d",ans);
	
}