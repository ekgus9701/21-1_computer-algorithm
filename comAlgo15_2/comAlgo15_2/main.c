//floyd-warshall algorithm
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define INF 1000000

typedef struct GraphType {
	int n;
	int weight[SIZE][SIZE];
}GraphType;

int A[SIZE][SIZE];

void printA(GraphType* g) {
	int i, j;
	printf("========================\n");
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF)
				printf("  * "); //경로 없음
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("========================\n");
}

void floyd(GraphType* g) {
	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	//경로 찾는 알고리즘 부분
	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				//가중치 없는 버전
				if (A[i][k] == 1 && A[k][j] == 1)
					A[i][j] = 1;
				
				/*가중치 있는 버전
				if(A[i][k]+A[k][j]<A[i][j]) //오른쪽보다 왼쪽이 가는 길이 더 짧다면
					A[i][j]=A[i][k]+A[k][j];
				*/
		printA(g);
	}
}

int main(void) {
	GraphType g = { 5,
	{{0,1,INF,1,INF}, //경로가 있으면 1, 경로가 없으면 INF
	{INF,0,INF,INF,INF},
	{1,INF,0,INF,INF},
	{INF,INF,INF,0,1},
	{1,INF,INF,INF,0}}
	};

	floyd(&g);
	return 0;
}