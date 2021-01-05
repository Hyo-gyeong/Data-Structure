//��������� �̿��� �׷��� 
//program10.1
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

//�׷��� �ʱ�ȭ
void init(GraphType *g)
{
	int r, c;

	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
//���� ���� ����
void insert_vertex(GraphType *g, int v)
{
	if (g->n + 1 > MAX_VERTICES){//���� �߰��ϸ� max������ ����ġ��?
		printf("���� �ʰ�\n");
		return;
	}
	g->n++;
}

//���� ���� ����
void insert_edge(GraphType *g, int start, int end)
{
	if (start >= g->n || end >= g->n){ //���� ������ ������ ����
		printf("�׷��� ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;//weight����,�����迭�� ���� ������ ǥ��
	g->adj_mat[end][start] = 1;//������׷����� ��� �ʿ�
}

//������� ����Լ�
void print_adj_mat(GraphType *g)
{
	int i, j;

	for (i = 0; i < g->n; i++){//�ִ� �����ȿ����� ���
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