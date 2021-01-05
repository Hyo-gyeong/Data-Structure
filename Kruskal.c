//Kruskal�� �ּ� ��� ���� Ʈ��
//�־��� �׷������� ������ �߷���
//cycle�������� union�̿�
//program11.8
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000 //�׷��� �ʱ�ȭ, weight�� 0�ϼ��� �־

int parent[MAX_VERTICES]; //Ʈ�� �迭 ���

void set_init(int n)
{
	int i;
	for (i = 0; i < n; i++)
		parent[i] = -1;
}
//���ϴ� ���� ��ȯ
int set_find(int curr)
{
	if(parent[curr] == -1)
		return curr;
	while(parent[curr] != -1)
		curr = parent[curr];//curr = 5��Ʈ�� 3�̸� curr 5->3
	return curr;
}
//�ΰ��� ���Ұ� ���� ������ ��ģ��.
void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2; 
}

struct Edge { //������ ��Ÿ���� ����ü
	int start, end, weight;
};
typedef struct GraphType{//�����ϴ� �������� ��� �ִ� �迭
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
//��������
void insert_edge(GraphType *g, int start, int end, int w)
{
	//������ �迭�� �� �ְ� ���߿� �����ؼ�
	//      ��g->n�Ǵ°�
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}
//qsort()�� ���Ǵ� �Լ�..
int compare(const void *a, const void *b)
{
	struct Edge *x = (struct Edge*)a;
	struct Edge *y = (struct Edge*)b;
	return (x->weight - y->weight);
}
//Kruskal
void kruskal(GraphType *g)
{
	int edge_accepted = 0; //���õ� ������ ��
	int uset, vset;
	struct Edge e;
	int i = 0;//���ʴ��

	set_init(g->n);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);//���ĵǾ ���ʴ�� �����ϸ��

	printf("ũ�罺Į �ּҺ�� ���� Ʈ�� �˰���\n");
	while(edge_accepted < (g->n - 1)){ //�ּ� n-1���� ������ ���õǾ�� �ϴϱ�
		e = g->edges[i++];
		uset = set_find(e.start); //find root
		vset = set_find(e.end); //find root
		if (uset != vset){//������ �߱⶧���� ������ �ٸ���, ���⸸ �ϸ��.
			printf("���� (%d, %d) %d����\n", e.start, e.end, e.weight);
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

	//���ⰳ�� ����
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