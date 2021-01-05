//���� �迭�� ǥ���� �׷��� 
//���̿켱Ž�� : ���� ���� �������� �Ϻ��ϰ� Ž���ϰ� ���� ���
//��ȯ�� ����ϱ⶧���� ����� �������� �� ���ٰ� 
//�鸣�� �������� �ٽ� ���ƿͼ� �鸣�Ե�.
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

int visited[MAX_VERTICES];//��湮 ���� �ʱ����� �ʿ�, 0���� �ʱ�ȭ��

void init(GraphType *g)
{
	int i, j;

	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++){
		for (j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
	}
}
//�������� ���� �߰�
 void insert_vertex(GraphType *g, int v)
 {
	 if (g->n + 1 > MAX_VERTICES){
		 printf("���� ���� �ʰ�\n");
		 return;
	 }
	 g->n++;
 }
 //���� ���Կ���
 void insert_edge(GraphType * g, int start, int end)
 {
	 if (start >= g->n || end >= g->n){
		 printf("���� ��ȣ ����");
		 return;
	 }
	 g->adj_mat[start][end] = 1;
	 g->adj_mat[end][start] = 1;//����׷����̸� ���̿켱Ž���� �ǹ̰� ũ�� ������~
 }
 //���̿켱Ž�� (DepthFirstSearch)
 void dfs_mat(GraphType *g, int v)
 {
	 int w;

	 visited[v] = TRUE;
	 printf("���� %d-> ", v);
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

	 printf("���� �켱 Ž��\n");
	 dfs_mat(g, 0);
	 printf("\n");
	 free(g);
	 return;
 }