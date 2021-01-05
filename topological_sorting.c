//��������
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

//����--------------------------------------------------- 
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

//�׷����� ���Ḯ��Ʈ ǥ��--------------------------------
typedef struct GraphNode
{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType 
{
	int n; // ������ ����
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;

// �׷��� �ʱ�ȭ
void graph_init(GraphType *g) 
{
	int i;
	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
}

// ���� ���� ����
void insert_vertex(GraphType *g, int v)
 {
	 if (g->n + 1 > MAX_VERTICES){
		 printf("���� ���� �ʰ�\n");
		 return;
	 }
	 g->n++;
 }

// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;

	if( u >= g->n || v >= g->n ){
		fprintf(stderr, "�׷���: ���� ��ȣ ����");		
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void remove_node(GraphNode **phead, element item) // 4�� ����Ʈ���� �н��� �Լ����� ListNode --> GraphNode�� ��������
{
	GraphNode *p, *prevp;
     
     if (*phead == NULL)
          printf("����Ʈ�� ����ֽ��ϴ�.\n");
     else if ((*phead)->vertex == item) {
          p = *phead;
          *phead = (*phead)->link;
          free(p);
     }
     else {
          p = *phead;
          do {
               prevp = p;
               p = p->link;
          }while (p != NULL && p->vertex != item);
          if (p != NULL) {
               prevp->link = p->link;
               free(p);
          }
          else
               printf("%d�� ����Ʈ�� ����\n", item);
     }
}
//���� �ʱ�ȭ
void init(StackType *s)
{
	s->top = -1; 
}
int is_empty(StackType *s)
{
	return (s->top == -1); 
}
int is_full(StackType *s)
{
	if (!is_full(s)){
		return (s->top == (MAX_STACK_SIZE-1));
	}
}
// �����Լ�
void push(StackType *s, element item) 
{
	s->stack[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s) 
{
	if (!is_empty(s)){
		return s->stack[(s->top)--];
	}
}
// ��ũ�Լ�
element peek(StackType *s) 
{
	if( is_empty(s) ) {
		 fprintf(stderr, "���� ���� ����\n");
		 return;
	 }
	 else
		return s->stack[s->top];
}
// ���������� �����Ѵ�.
int topo_sort(GraphType *g)
{
	 int i;
	 StackType s;
	 GraphNode *node;

	 // ��� ������ ���� ������ ���
	 int *in_degree = (int *)malloc(g->n* sizeof(int));
	 for (i = 0; i < g->n; i++) // �ʱ�ȭ
		in_degree[i] = 0;
	 for (i = 0; i < g->n; i++){
		for (node = g->adj_list[i]; node; node = node->link) //���� i���� ������ ������
			in_degree[node->vertex]++;
	 }

	 // ���� ������ 0�� ������ ���ÿ� ����
	 init(&s);
	 for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) 
			push(&s, i);
	 }

	 // ���� ������ ����
	 while (!is_empty(&s)) {
		 int w;
		 w = pop(&s);
		 printf("���� %d ->", w); //���� ���
		 for (node = g->adj_list[w]; node; node = node->link) { //�� ������ ���� ������ ����
			int u = node->vertex;
			in_degree[u]--; //���� ������ ����
			if (in_degree[u] == 0) 
				push(&s, u);
		 }
	 }
	 free(in_degree);
}
int main(void)
{
	 GraphType g;
	 graph_init(&g);
	 insert_vertex(&g, 0);
	 insert_vertex(&g, 1);
	 insert_vertex(&g, 2);
	 insert_vertex(&g, 3);
	 insert_vertex(&g, 4);
	 insert_vertex(&g, 5);
	 //���� 0�� ���� ����Ʈ ����
	 insert_edge(&g, 0, 2);
	 insert_edge(&g, 0, 3);
	 //���� 1�� ���� ����Ʈ ����
	 insert_edge(&g, 1, 3);
	 insert_edge(&g, 1, 4);
	 //���� 2�� ���� ����Ʈ ����
	 insert_edge(&g, 2, 3);
	 insert_edge(&g, 2, 5);
	 //���� 3�� ���� ����Ʈ ����
	 insert_edge(&g, 3, 5);
	 //���� 4�� ���� ����Ʈ ����
	 insert_edge(&g, 4, 5);
	 //���� ����
	 topo_sort(&g);
} 