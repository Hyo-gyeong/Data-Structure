//���� ����Ʈ�� ������ �׷���
//�ʺ� �켱Ž��
//ť�� �̿��� ���� -> ť�� ������� ������
//�ݺ������
//program10.6
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;
void queue_init(QueueType *q)
{
	q->front = q->rear = 0;
}
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);//�������� ����
}
//ť ���� �Լ� - rear
void enqueue(QueueType *q, element item)
{
	if (is_full(q)){
		printf("��ȭ����\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
//ť ���� �Լ� - front
//�ϳ��� ������ ���� �湮�� �� ����
element dequeue(QueueType *q)
{
	if (is_empty(q)){
		printf("�������\n");
		return;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

#define MAX_VERTICES 50
typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;
typedef struct GraphType{
	int n;
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;
int visited[MAX_VERTICES];

//�׷��� �ʱ�ȭ
void graph_init(GraphType *g)
{
	int r;

	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		g->adj_list[r] = NULL;
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
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *newnode, *newnode2;
	newnode = (GraphNode *)malloc(sizeof(GraphNode));
	newnode2 = (GraphNode *)malloc(sizeof(GraphNode));
	if (u >= g->n || v >= g->n){ //���� ������ ������ ����
		printf("�׷��� ���� ��ȣ ����");
		return;
	}
	newnode->vertex = u;
	newnode->link = g->adj_list[v];
	g->adj_list[v] = newnode;

	newnode2->vertex = v;
	newnode2->link = g->adj_list[u];
	g->adj_list[u] = newnode2;
}
void bfs_mat(GraphType *g, int v)
{
	GraphNode *w;
	QueueType q;

	queue_init(&q);
	visited[v] = TRUE;
	enqueue(&q, v);
	while(!is_empty(&q)){
		v = dequeue(&q);
		printf("%d �湮-> ", v);
		for (w = g->adj_list[v]; w; w = w->link )
			if (!visited[w->vertex]){
				visited[w->vertex] = TRUE;
				enqueue(&q, w->vertex);
			}
	}
}
int main(void)
{
	int i;
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	graph_init(g);
	for (i = 0; i < 6; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("�ʺ� �켱 Ž��\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return;
}