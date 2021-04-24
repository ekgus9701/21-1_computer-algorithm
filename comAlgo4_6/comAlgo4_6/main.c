//정수 범위로 매핑가능한 집합
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
	char Lee[13][15] = { "March","July","August","October","December" };
	char Sung[13][15] = { "April","May","August","December" };
	char month[13][15] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

	int A[13] = {0};
	int B[13] = { 0 };
	
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
		
			if (strcmp(Lee[i], month[j])==0) {
				A[j] = 1;
			}
			if (strcmp(Sung[i], month[j])==0) {
				B[j] = 1;
			}
		}

	}
	printf("A ");
	for (int i = 0; i < 12; i++) {
		printf(" [%d월 ] %d", i+1, A[i]);
	}
	printf("\n");
	printf("B ");
	for (int i = 0; i < 12; i++) {
		printf(" [%d월 ] %d", i+1, B[i]);
	}
	printf("\n");
}