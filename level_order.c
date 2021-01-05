//트리레벨순회
//원형큐 사용
//program8.5
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

//원형큐 코드 시작
#define MAX_QUEUE_SIZE 100
typedef TreeNode *element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//초기화
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
void enqueue(QueueType *q, element item)
{
	if (is_full(q)){
		printf("포화상태\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType *q)
{
	if (is_full(q)){
		printf("공백상태\n");
		return;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
void level_order(TreeNode *ptr)
{
	QueueType q;

	init_queue(&q);
	if (ptr == NULL) return; //아무것도 안넣음
	enqueue(&q, ptr);
	while(!is_empty(&q)){
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(void)
{
	printf("레벨순회 = ");
	level_order(root);
	printf("\n");
	return;
}