#include<stdio.h>
#include<stdlib.h>

#define N 4
#define M 5
void spiral(int A[N][M]) {
	int left = 0, right = M - 1;
	int top = 0, bottom = N - 1;

	int value = 1;
	while (left <= right && top <= bottom) {
		if (left <= right) {
			for (int j = left; j <= right; j++) {
				A[top][j] = value;
				value++;
			}
		}
		top = top + 1;
		if (top <= bottom) {
			for (int i = top; i <= bottom; i++) {
				A[i][right] = value;
				value++;
			}

		}
		right = right - 1;
		
		if (left <= right) {
			for (int j = right; j >= left; j--) {
				A[bottom][j] = value;
				value++;
			}
		}
		bottom -= 1;
		
		if (top <= bottom) {
			for (int i = bottom; i >= top; i--) {
				A[i][left] = value;
				value++;
			}

		}
		left += 1;
	}
}

void printArray(int A[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%2d ", A[i][j]);
		}
		printf("\n");
	}
}

void main() {
	int A[N][M] = { 0 };
	spiral(A);
	printArray(A);
}