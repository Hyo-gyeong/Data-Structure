//Floyd의 최단 경로 프로그램
//Dijkstra모든정점ver.
//& Dijkstra확장ver. 모든 정점 사이의 최단 거리를 알 수 있음
//program11.11
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 100000 //연결이 없는 경우

typedef struct GraphType{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];//distance값이 수정될 배열

void printA(GraphType *g)
{
	int i, j;
	printf("===============================\n");
	for (i = 0; i < g->n; i++){
		for (j = 0; j < g->n; j++){
			if (A[i][j] == INF)
				printf(" * ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("===============================\n");
}
void floyd(GraphType *g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)//초기상태
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	for (k = 0; k < g->n; k++){//추가된정점 
		for (i = 0; i < g->n; i++)//배열
			for (j = 0; j < g->n; j++)//배열
				if (A[i][k] + A[k][j] < A[i][j])//정점을 추가하면서 거리 다시계산
					A[i][j] = A[i][k] + A[k][j];
		printA(g);//정점k = 0, 1, 2, ... g->n 추가될때마다 출력
	}
}
int main(void)
{
	GraphType g = {7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}}
	};
	floyd(&g);
	return;
}