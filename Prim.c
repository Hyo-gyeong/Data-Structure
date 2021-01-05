//Prim�� �ּ� ��� ����Ʈ��
//�ٸ� ������ ��忡�� �����Ѵٴ� ���� Kruskal�� ����������
//�̹� ������ ���տ��� ���������� �ʰ� �����Ͽ� Ȯ���Ѵٴ� ������ ���̰�����
//Kruskal�� ����� ������ ���� ������ �ٸ�
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
//Kruskal�� �ٸ��� ������ Ŀ�������� ���հ� �������� �Ÿ��� (���� ������)��� �ٲ�
//���տ� ������ �ʴ� �����߿��� ���հ� �Ÿ��� ���� ���� ���� �����ϱ⶧����
int distance[MAX_VERTICES];//�׷��� distance�迭 �ʿ�

//�ּ� distance[v] ���� ���� ������ ��ȯ
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]){//�Ȱ� �ֵ��߿� �񱳴���� �ϳ� �������� �ּ� ã�°��� ����
			v = i;		//���Ƿ� ���� �����ϸ� �ð� �� �ɸ�
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
	distance[s] = TRUE;//������-������ weight�� 0
	for (i = 0; i < g->n; i++){//��� ������ �����س����� �ݺ���
		u = get_min_vertex(g->n);//ó���� �����Ҷ��� �������� ��������
		selected[u] = TRUE;
		if (distance[u] == INF) return; //���°�
		printf("���� %d�߰�\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)//���� �����鼭
				if (!selected[v] && g->weight[u][v] < distance[v])//��� ������ �ƴ�, �ּڰ� �����ϰڴ�
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