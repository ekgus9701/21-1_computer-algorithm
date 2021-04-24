#include<stdio.h>
#include<stdlib.h>

int product(int a, int b) {
	if (b == 1) {
		return a;
	}
	else {
		return a + product(a, b - 1);
	}
}

int modulo(int a, int b) {
	if (a < b)
		return a;
	else
		return modulo(a - b, b);
}

int quotient(int a, int b) {
	if (a < b)
		return 0;
	else
		return 1 + quotient(a - b, b);
}

int main() {
	int a = 7;
	int b = 3;

	printf("product: %d\n", product(a, b)); //°ö
	printf("modulo: %d\n", modulo(a, b)); //³ª¸ÓÁö
	printf("quotient: %d\n", quotient(a, b)); //¸ò
}