//�ִܰ�� Dijkstra ���α׷�
//��.��.�� ����a�κ���(�긦 ��������)
//�ٸ� �������� distance�����ؼ� ��
//��) a->c�϶�, a-b-c�� ������? a-d-e-c-�� ������?
//program11.10
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERITECS 100
#define INF 1000000 //���Ѵ� - ������ ���� ���

typedef struct GraphType {
	int n;
	int weight[MAX_VERITECS][MAX_VERITECS];
}GraphType;

int distance[MAX_VERITECS]; //���������κ����� ������ ���
int found[MAX_VERITECS]; //ã���� ǥ��

int choose(int distance[], int n, int found[])//int n�� ��ü ������ ������ ����
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
	for (i = 0; i < g->n; i++){//�ʱ�ȭ
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;//���� ������ �湮���� ǥ��
	distance[start] = 0;
	for (i = 0; i < g->n; i++){//��� ������ �ϳ��� �����س���
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)//������ ������ ������ �Ÿ��� ���� ���
			if (!found[w])
				if (distance[w] > distance[u] + g->weight[u][w])
					//������� ������ �������� �Ÿ� vs ���� ���Ӱ� �߰������� ���� ����� �Ÿ�
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
