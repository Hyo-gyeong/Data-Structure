//최단경로 Dijkstra 프로그램
//하.나.의 정점a로부터(얘를 기준으로)
//다른 정점까지 distance누적해서 비교
//예) a->c일때, a-b-c가 작을까? a-d-e-c-가 작을까?
//program11.10
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERITECS 100
#define INF 1000000 //무한대 - 연결이 없는 경우

typedef struct GraphType {
	int n;
	int weight[MAX_VERITECS][MAX_VERITECS];
}GraphType;

int distance[MAX_VERITECS]; //시작점으로부터의 누적값 기록
int found[MAX_VERITECS]; //찾은점 표시

int choose(int distance[], int n, int found[])//int n에 전체 정점의 개수가 들어옴
{
	int i, min, minpos;

	min = INF;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]){
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void print_status(GraphType *g)
{
	int i;
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (i = 0; i < g->n; i++){
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for (i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}
void shortest_path(GraphType *g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++){//초기화
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;//시작 정점은 방문으로 표시
	distance[start] = 0;
	for (i = 0; i < g->n; i++){//모든 정점을 하나씩 선택해나감
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)//정점을 선택할 때마다 거리를 새로 계산
			if (!found[w])
				if (distance[w] > distance[u] + g->weight[u][w])
					//현재까지 선택한 점까지의 거리 vs 점을 새롭게 추가했을때 새로 생기는 거리
					distance[w] = distance[u] + g->weight[u][w];
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
	shortest_path(&g, 0);
	return 0;
}
