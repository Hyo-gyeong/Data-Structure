#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 10
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(int key)
{
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));

	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(TreeNode *root)
{
	if (root){
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

TreeNode* search(TreeNode *node, int key)
{
	if (node == NULL)
		return NULL;
	else{
		if (key < node->key)
			return search(node->left, key);
		else if (key > node->key)
			return search(node->right, key);
		return node;
	}
}

TreeNode* insert_node(TreeNode *root, int key)
{
	if (root == NULL)
		return new_node(key);
	else if (key < root->key)
		root->left = insert_node(root->left, key);
	else
		root->right = insert_node(root->right, key);
	return root;
}

TreeNode* max_value_node(TreeNode *node)
{
	TreeNode *current = node;

	while(current->right != NULL)
		current = current->right;
	return current;
}

TreeNode* min_value_node(TreeNode *node)
{
	TreeNode *current = node;

	while(current->left != NULL)
		current = current->left;
	return current;
}


TreeNode* delete_node(TreeNode *root, int key)
{
	TreeNode *temp;

	if (root == NULL) return NULL;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL){
			temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			temp = root->left;
			free(root);
			return temp;
		}
		else{
			temp = min_value_node(root->right);
			root->key = temp->key;
			root->right = delete_node(root->right, temp->key);
		}
	}
	return root;
}

int get_height(TreeNode *root)
{
	int right = 0, left = 0;

	if (root == NULL)
		return 0;
	else if (root->left != NULL && root->right != NULL){
		right =  1 + get_height(root->right);
		left = 1 + get_height(root->left);
	}
	else if (root->left == NULL)
		right = 1 + get_height(root->right);
	else if (root->right == NULL)
		left = 1 + get_height(root->left);
	else
		return 1;
	return (right > left ? right : left);
}

int count_node(TreeNode *root)
{
	if (root == NULL)
		return 0;
	else if (root->left != NULL && root->right != NULL)
		return 1 + count_node(root->right) + count_node(root->left);
	else if (root->left == NULL)
		return 1 + count_node(root->right);
	else 
		return 1 + count_node(root->left);
}

int main(void)
{
	TreeNode *root = NULL;
	char choice;
	int key;

	do{
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>,c<ount>, m<ax>, n<min>, q<uit>: ");
		scanf("%c", &choice);
		switch(choice){
		case 'i':
			printf("삽입할 key값 입력 : ");
			scanf("%d", &key);
			root = insert_node(root, key);
			break;
		case 'd':
			printf("삭제할 key값 입력 : ");
			scanf("%d", &key);
			root = delete_node(root, key);
			break;
		case 's':
			scanf("%d", &key);
			if (search(root, key) == NULL)
				printf("없음\n");
			else
				printf("있음\n");
			break;
		case 'p':
			preorder(root);
			printf("\n");
			break;
		case 'h':
			printf("트리의 높이는 %d\n", get_height(root));
			break;
		case 'c':
			printf("노드의 개수는 %d\n", count_node(root));
			break;
		case 'm':
			printf("가장 큰 값은 %d\n", max_value_node(root)->key);
			break;
		case 'n':
			printf("가장 작은 값은 %d\n", min_value_node(root)->key);
			break;
		case 'q':
			break;
		default:
			printf("there is no option\n");
			break;
		}
		getchar();
	}while(choice != 'q');
}