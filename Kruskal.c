//Kruskal의 최소 비용 신장 트리
//주어진 그래프에서 최적만 추려냄
//cycle막기위해 union이용
//program11.8
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000 //그래프 초기화, weight가 0일수도 있어서

int parent[MAX_VERTICES]; //트리 배열 사용

void set_init(int n)
{
	int i;
	for (i = 0; i < n; i++)
		parent[i] = -1;
}
//속하는 집합 반환
int set_find(int curr)
{
	if(parent[curr] == -1)
		return curr;
	while(parent[curr] != -1)
		curr = parent[curr];//curr = 5루트가 3이면 curr 5->3
	return curr;
}
//두개의 원소가 속한 집합을 합친다.
void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2; 
}

struct Edge { //간선을 나타내는 구조체
	int start, end, weight;
};
typedef struct GraphType{//존재하는 간선들을 모두 넣는 배열
	int n;
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g)
{
	int i;

	g->n = 0;
	for (i = 0; i < 2 * MAX_VERTICES; i++){
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
//간선삽입
void insert_edge(GraphType *g, int start, int end, int w)
{
	//간선을 배열에 다 넣고 나중에 정렬해서
	//      ↓g->n되는거
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}
//qsort()에 사용되는 함수..
int compare(const void *a, const void *b)
{
	struct Edge *x = (struct Edge*)a;
	struct Edge *y = (struct Edge*)b;
	return (x->weight - y->weight);
}
//Kruskal
void kruskal(GraphType *g)
{
	int edge_accepted = 0; //선택된 간선의 수
	int uset, vset;
	struct Edge e;
	int i = 0;//차례대로

	set_init(g->n);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);//정렬되어서 차례대로 선택하면됨

	printf("크루스칼 최소비용 신장 트리 알고리즘\n");
	while(edge_accepted < (g->n - 1)){ //최소 n-1개의 간선이 선택되어야 하니까
		e = g->edges[i++];
		uset = set_find(e.start); //find root
		vset = set_find(e.end); //find root
		if (uset != vset){//정렬을 했기때문에 집합이 다를때, 고르기만 하면됨.
			printf("간선 (%d, %d) %d선택\n", e.start, e.end, e.weight);
			set_union(uset, vset);	
			edge_accepted++;
		}
	}
}
int main(void)
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	graph_init(g);

	//방향개념 없음
	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);
	
	kruskal(g);
	free(g);
	return;
}