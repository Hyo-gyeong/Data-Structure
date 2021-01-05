//인접 리스트를 이용한 그래프
//program10.2
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode{//리스트 한 줄
	int vertex;
	struct GraphNode *link;
}GraphNode;//하나하의 노드

typedef struct GraphType{//정점의 개수만큼의 리스트 묶음
	int n;
	GraphNode *adj_list[MAX_VERTICES]; //이게 헤더노드!! 태그같이 사용되는거야
}GraphType;//그래프의 전체 

void init(GraphType *g)
{
	int v;

	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
//정점 삽입(개념상)->사실상 정점의 개수를 표현
void insert_vertex(GraphType *g, int v)
{
	if (g->n + 1 > MAX_VERTICES){//정의된 노드 밖으로 추가
		printf("정점 초과\n");
		return;
	}
	g->n++;
}
void insert_edge(GraphType *g, int u, int v)//무방향으로 한번에 담으려면
							//	^^start ^^end
{
	GraphNode *newnode, *newnode2;
	newnode = (GraphNode *)malloc(sizeof(GraphNode));
	newnode2 = (GraphNode *)malloc(sizeof(GraphNode));

	if (u >= g->n || v >= g->n){
		printf("그래프 정점 번호 오류");
		return;
	}
	newnode->vertex = u;
	newnode->link = g->adj_list[v];
	g->adj_list[v] = newnode;
	// 방향 그래프는 아래코드 불필요
	newnode2->vertex = v;
	newnode2->link = g->adj_list[u];
	g->adj_list[u] = newnode2;
}
void print_adj_list(GraphType *g)
{
	int i;
	for (i = 0; i < g->n; i++){
		GraphNode *temp = g->adj_list[i];//GraphNode
		printf("정점 %d의 인접 리스트", i);
		while(temp != NULL){
			printf(" -> %d", temp->vertex);
			temp = temp->link;
		}
		printf("\n");
	}
}
int main(void)
{
	int i;
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	for (i = 0; i < 4; i++)
		insert_vertex(g, i);
	//방향그래프로 넣는다면
	//        from↓to↓ 라는 의미
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);
	free(g);
	return;
}