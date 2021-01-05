//인접 리스트로 표현된 그래프 
//깊이우선탐색 
//program10.4
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;
#define MAX_VERTICES 50

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;
typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];//재방문 하지 않기위해 필요, 0으로 초기화됨

void init(GraphType *g)
{
	int i;

	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
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
 void insert_edge(GraphType * g, int u, int v)
 {
	 GraphNode *newnode, *newnode2;
	 newnode = (GraphNode *)malloc(sizeof(GraphNode));
	 newnode2 = (GraphNode *)malloc(sizeof(GraphNode));

	 if (u >= g->n || v >= g->n){
		 printf("정점 번호 오류");
		 return;
	 }
	 newnode->vertex = u;
	 newnode->link = g->adj_list[v];
	 g->adj_list[v] = newnode;

	 newnode2->vertex = v;
	 newnode2->link = g->adj_list[u];
	 g->adj_list[u] = newnode2;

 }
 //깊이우선탐색 (DepthFirstSearch)
 void dfs_mat(GraphType *g, int v)
 {
	 GraphNode *temp;

	 visited[v] = TRUE;
	 printf("정점 %d-> ", v);
	 for (temp = g->adj_list[v]; temp; temp = temp->link)
		 if (!visited[temp->vertex])
			 dfs_mat(g, temp->vertex);
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