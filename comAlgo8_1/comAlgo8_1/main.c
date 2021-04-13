#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 15

int partition(int list[], int left, int right) {
	int pivot, temp, low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);

		for (int i = 0; i < MAX_SIZE; i++)
			printf("[%d] ", list[i]);
		printf("\nlow= %d, high= %d\n", low, high); getch();

		if (low < high)
			SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right) { //�迭, �����ε���, ������ �ε���

	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

void main() {

	int list[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n"); getch();

	quick_sort(list, 0, MAX_SIZE - 1);
	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n"); getch();

}