//트리 - 반복적 순회
//program8.4
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode *pop()
{
	TreeNode *p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode *root)
{
	while(1){
		for(; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

void preorder_iter(TreeNode *root)
{
	while(1){
		for(; root; root = root->left){
			printf("[%d] ", root->data);
			push(root);
		}
		root = pop();		
		if (!root) break;
		root = root->right;
	}
}

void postorder_iter(TreeNode *root)//찾아서 씀 
{
	while(1){
		do{
			if (root->data != NULL && root != NULL){
				push(root);
				root = root->left;
			}
			else
				break;
		}while(root != NULL);
		root = pop();
		if (!root) break;
		if (root->right != NULL){
			if (root->right->data == NULL){//현재 루트를 기준으로 오른쪽 트리 내용을 모두 출력한 상태
				printf("[%d] ", root->data);
				root->data = NULL;
			}
			else{
				push(root);
				root = root->right;
			}
		}
		else{//오른쪽 트리에 출력할 내용이 없으면
			printf("[%d] ", root->data); //루트 출력
			root->data = NULL;
		}
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
	printf("중위순회\n");
	inorder_iter(root);
	printf("\n");
	printf("전위순회\n");
	preorder_iter(root);
	printf("\n");
	printf("후위순회\n");
	postorder_iter(root);
	printf("\n");
	return;
}