//인접 배열로 표현된 그래프 
//깊이우선탐색 : 다음 노드로 가기전에 완벽하게 탐색하고 가는 방법
//순환을 사용하기때문에 연결된 길을따라 쭉 갔다가 
//들르지 않은점은 다시 돌아와서 들르게됨.
//program10.3
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;
#define MAX_VERTICES 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];//재방문 하지 않기위해 필요, 0으로 초기화됨

void init(GraphType *g)
{
	int i, j;

	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++){
		for (j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
	}
}
//개념적인 정점 추가
 void insert_vertex(GraphType *g, int v)
 {
	 if (g->n + 1 > MAX_VERTICES){
		 printf("정점 개수 초과\n");
		 return;
	 }
	 g->n++;
 }
 //간선 삽입연산
 void insert_edge(GraphType * g, int start, int end)
 {
	 if (start >= g->n || end >= g->n){
		 printf("정점 번호 오류");
		 return;
	 }
	 g->adj_mat[start][end] = 1;
	 g->adj_mat[end][start] = 1;//방향그래프이면 깊이우선탐색이 의미가 크게 없겠지~
 }
 //깊이우선탐색 (DepthFirstSearch)
 void dfs_mat(GraphType *g, int v)
 {
	 int w;

	 visited[v] = TRUE;
	 printf("정점 %d-> ", v);
	 for (w = 0; w < g->n; w++)
		 if (!visited[w] && g->adj_mat[v][w])
			 dfs_mat(g, w);
 }
 int main(void)
 {
	 int i;
	 GraphType *g;
	 g = (GraphType *)malloc(sizeof(GraphType));
	 init(g);
	 for (i = 0; i < 4; i++)
		 insert_vertex(g, i);
	 insert_edge(g, 0, 1);
	 insert_edge(g, 0, 2);
	 insert_edge(g, 0, 3);
	 insert_edge(g, 1, 2);
	 insert_edge(g, 2, 3);

	 printf("깊이 우선 탐색\n");
	 dfs_mat(g, 0);
	 printf("\n");
	 free(g);
	 return;
 }