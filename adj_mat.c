//인접행렬을 이용한 그래프 
//program10.1
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

//그래프 초기화
void init(GraphType *g)
{
	int r, c;

	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
//정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
	if (g->n + 1 > MAX_VERTICES){//새로 추가하면 max개수가 오넘치네?
		printf("정점 초과\n");
		return;
	}
	g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType *g, int start, int end)
{
	if (start >= g->n || end >= g->n){ //없는 정점에 넣으면 오류
		printf("그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;//weight없음,인접배열은 길의 유무만 표현
	g->adj_mat[end][start] = 1;//무방향그래프의 경우 필요
}

//인접행렬 출력함수
void print_adj_mat(GraphType *g)
{
	int i, j;

	for (i = 0; i < g->n; i++){//있는 정점안에서만 출력
		for (j = 0; j < g->n; j++)
			printf("%d ", g->adj_mat[i][j]);
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
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);
	free(g);
}