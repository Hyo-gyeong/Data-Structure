//인접행렬로 구현된 그래프
//너비 우선탐색 : 선택된 노드와 가까운 노드부터 방문
//큐를 이용해 구현 -> 큐가 비어있을 때까지
//반복문 사용
//program10.5
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
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);//원형으로 구현
}
//큐 삽입 함수 - rear
void enqueue(QueueType *q, element item)
{
	if (is_full(q)){
		printf("포화상태\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
//큐 삭제 함수 - front
//하나씩 꺼내어 정점 방문할 때 쓰임
element dequeue(QueueType *q)
{
	if (is_empty(q)){
		printf("공백상태\n");
		return;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

#define MAX_VERTICES 50
typedef struct GrapghType{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
int visited[MAX_VERTICES];

//그래프 초기화
void graph_init(GraphType *g)
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
void bfs_mat(GraphType *g, int v)
{
	int w;
	QueueType q;

	queue_init(&q);
	visited[v] = TRUE;
	enqueue(&q, v);
	while(!is_empty(&q)){
		v = dequeue(&q);
		printf("%d 방문-> ", v);
		for (w = 0; w < g->n; w++)
			if (g->adj_mat[v][w] && !visited[w]){
				visited[w] = TRUE;
				enqueue(&q, w);
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

	printf("너비 우선 탐색\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return;
}