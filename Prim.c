//Prim의 최소 비용 신장트리
//다른 집합의 노드에서 선택한다는 점은 Kruskal과 동일하지만
//이미 생성한 집합에서 동떨어지지 않게 연결하여 확장한다는 점에서 차이가있음
//Kruskal과 결과는 같지만 고르는 순서가 다름
//program11.9
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct GraphType{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
//Kruskal과 다르게 집합이 커짐에따라 집합과 정점간에 거리가 (작은 값으로)계속 바뀜
//집합에 속하지 않는 점들중에서 집합과 거리가 가장 작은 점을 골라야하기때문에
int distance[MAX_VERTICES];//그래서 distance배열 필요

//최소 distance[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]){//안고른 애들중에 비교대상은 하나 만들어놔야 최소 찾는것이 용이
			v = i;		//임의로 수로 지정하면 시간 더 걸림
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	return v;
}
void prim(GraphType *g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = TRUE;//시작점-시작점 weight는 0
	for (i = 0; i < g->n; i++){//모든 정점을 포함해나가는 반복문
		u = get_min_vertex(g->n);//처음에 시작할때는 시작점이 나오겠지
		selected[u] = TRUE;
		if (distance[u] == INF) return; //없는거
		printf("정점 %d추가\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)//길이 있으면서
				if (!selected[v] && g->weight[u][v] < distance[v])//골라낸 집합이 아님, 최솟값 저장하겠다
					distance[v] = g->weight[u][v];
	}
}
int main(void)
{
	GraphType g = {7,
	{{0,29,INF,INF,INF,10,INF},
	{29,0,16,INF,INF,INF,15},
	{INF,16,0,12,INF,INF,INF},
	{INF,INF,12,0,22,INF,18},
	{INF,INF,INF,22,0,27,25},
	{10,INF,INF,INF,27,0,INF},
	{INF,15,INF,18,29,INF,0}}
	};
	prim(&g, 0);
	return;
}