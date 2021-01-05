//Ʈ�� - �ݺ��� ��ȸ
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

void postorder_iter(TreeNode *root)//ã�Ƽ� �� 
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
			if (root->right->data == NULL){//���� ��Ʈ�� �������� ������ Ʈ�� ������ ��� ����� ����
				printf("[%d] ", root->data);
				root->data = NULL;
			}
			else{
				push(root);
				root = root->right;
			}
		}
		else{//������ Ʈ���� ����� ������ ������
			printf("[%d] ", root->data); //��Ʈ ���
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
	printf("������ȸ\n");
	inorder_iter(root);
	printf("\n");
	printf("������ȸ\n");
	preorder_iter(root);
	printf("\n");
	printf("������ȸ\n");
	postorder_iter(root);
	printf("\n");
	return;
}