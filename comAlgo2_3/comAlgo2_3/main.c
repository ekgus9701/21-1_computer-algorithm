#include<stdio.h>
#include<stdlib.h>

int iter_power(int x, int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

int recur_power(int x, int n) {
	if (n == 0)
		return 1;
	else if ((n % 2) == 0)
		return recur_power(x * x, n / 2);
	else
		return x * recur_power(x * x, (n - 1) / 2);

}

void main() {
	printf("2^10 = %d\n", iter_power(2, 10));
	printf("2^10 = %d\n", recur_power(2, 10));
}