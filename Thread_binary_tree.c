//스레드 이진트리
//남아도는 leaf node의 NULL을 활용하자!
//program8.8
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
	int is_thread;
}TreeNode;

TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode *exp = &n7;

TreeNode* find_successor(TreeNode *p)
{
	TreeNode *q = p->right;

	//만약 'q'의 포인터가 NULL이거나(반복문 탈출) 'p'가thread이면
	if (q == NULL || p->is_thread == TRUE)
		return q;

	//만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
	while(q->left  != NULL)
		q = q->left;
	return q;
}

void thread_inorder(TreeNode *t)
{
	TreeNode *q;

	q = t;
	while(q->left) q = q->left;
	do{
		printf("%c-> ", q->data);
		q = find_successor(q);
	}while(q);
}
int main(void)
{
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(exp);
	printf("\n");
	return;
}