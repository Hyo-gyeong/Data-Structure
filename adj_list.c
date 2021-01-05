//���� ����Ʈ�� �̿��� �׷���
//program10.2
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode{//����Ʈ �� ��
	int vertex;
	struct GraphNode *link;
}GraphNode;//�ϳ����� ���

typedef struct GraphType{//������ ������ŭ�� ����Ʈ ����
	int n;
	GraphNode *adj_list[MAX_VERTICES]; //�̰� ������!! �±װ��� ���Ǵ°ž�
}GraphType;//�׷����� ��ü 

void init(GraphType *g)
{
	int v;

	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
//���� ����(�����)->��ǻ� ������ ������ ǥ��
void insert_vertex(GraphType *g, int v)
{
	if (g->n + 1 > MAX_VERTICES){//���ǵ� ��� ������ �߰�
		printf("���� �ʰ�\n");
		return;
	}
	g->n++;
}
void insert_edge(GraphType *g, int u, int v)//���������� �ѹ��� ��������
							//	^^start ^^end
{
	GraphNode *newnode, *newnode2;
	newnode = (GraphNode *)malloc(sizeof(GraphNode));
	newnode2 = (GraphNode *)malloc(sizeof(GraphNode));

	if (u >= g->n || v >= g->n){
		printf("�׷��� ���� ��ȣ ����");
		return;
	}
	newnode->vertex = u;
	newnode->link = g->adj_list[v];
	g->adj_list[v] = newnode;
	// ���� �׷����� �Ʒ��ڵ� ���ʿ�
	newnode2->vertex = v;
	newnode2->link = g->adj_list[u];
	g->adj_list[u] = newnode2;
}
void print_adj_list(GraphType *g)
{
	int i;
	for (i = 0; i < g->n; i++){
		GraphNode *temp = g->adj_list[i];//GraphNode
		printf("���� %d�� ���� ����Ʈ", i);
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
	//����׷����� �ִ´ٸ�
	//        from��to�� ��� �ǹ�
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);
	free(g);
	return;
}