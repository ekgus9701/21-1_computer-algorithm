//에어텔 분할통치법, 동적프로그래밍 
#include<stdio.h>
#include<stdlib.h>

#define max(x,y) ((x)>(y)?(x):(y))

int A[] = { 0,1,3,6,11,17 };
int H[] = { 0,2,5,1,5,0 };
int m[10];

//정방향 동적계획법
int airtel(int n) {
	m[0] = 0;
	int cost;
	for (int d = 1; d < n; d++) {
		m[d] = 10000;
		for (int k = 0; k < d; k++) {
			cost = m[k] + H[k] + A[d - k];
			m[d] = min(m[d], cost);
		}
	}
	return m[n - 1];
}


//정방향분할통치법
int rAirtelForward(int d) {
	if (d == 0)
		return 0;
	int minCost = 10000;
	int cost;
	for (int k = 0; k < d; k++) {
		cost = rAirtelForward(k) + H[k] + A[d - k];
		minCost = min(minCost, cost);
	}
	return minCost;
}

//역방향도 해보기?


int main() {
	printf("%d\n", rAirtelForward(5));
	return 0;
}