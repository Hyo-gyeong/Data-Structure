#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 100

typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
}element;

typedef struct TreeNode{
	element data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(element *newnode, int key)
{
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));

	temp->data.id = key;
	strcpy(temp->data.name, newnode->name);
	strcpy(temp->data.tel, newnode->tel);
	strcpy(temp->data.dept, newnode->dept);
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode *root, element *temp, int key)
{
	if (root == NULL)
		return new_node(temp,key);
	else if (key < root->data.id)
		root->left = insert_node(root->left, temp, key);
	else
		root->right = insert_node(root->right,temp, key);
	return root;
}
void inorder(TreeNode *root)
{
	if(root){
		inorder(root->left);
		printf("-------------------\n");
		printf("학번 : %d\n", root->data.id);
		printf("이름 : %s\n", root->data.name);
		printf("전화번호 : %s\n", root->data.tel);
		printf("학과 : %s\n", root->data.dept);
		inorder(root->right);
	}
}
int count_node(TreeNode *root)
{
	if (root == NULL)
		return 0;
	else if (root->left != NULL && root->right != NULL)
		return 1 + count_node(root->left) + count_node(root->right);
	else if (root->left == NULL)
		return 1 + count_node(root->right);
	else if (root->right == NULL)
		return 1 + count_node(root->left);
	else
		return 1;
}
TreeNode* search(TreeNode *root, int id)
{
	if (root == NULL)
		return NULL;
	else if (id < root->data.id)
		return search(root->left, id);
	else if (id > root->data.id)
		return search(root->right, id);
	else
		return root;
}
TreeNode* min_value_node(TreeNode *root)
{
	TreeNode *current = root;

	while(current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode *root, int id)
{
	TreeNode *temp;

	if (root == NULL) return NULL;
	else if (id < root->data.id)
		root->left = delete_node(root->left, id);
	else if (id > root->data.id)
		root->right = delete_node(root->right, id);
	else{
		if (root->left == NULL){
			temp = root->right;
			free(temp);
			return temp;
		}
		else if (root->right == NULL){
			temp = root->left;
			free(temp);
			return temp;
		}
		else{
			temp = min_value_node(root->right);
			root->data.id = temp->data.id;
			root->right = delete_node(root->right, temp->data.id);
		}
	}
	return root;
}
int main(void)
{
	TreeNode *root = NULL;
	TreeNode *tmp = NULL;
	element *temp = (element *)malloc(sizeof(element));
	char choice;
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];

	do{
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>,c<ount>, m<ax>, n<min>, q<uit>: ");
		scanf("%c", &choice);
		switch(choice){
		case 'i':
			printf("학번 입력 : ");
			scanf("%d", &temp->id);
			printf("이름 입력 : ");
			scanf("%s", temp->name);
			printf("전화번호 입력 : ");
			scanf("%s", temp->tel);
			printf("학과 입력 : ");
			scanf("%s", temp->dept);
			root = insert_node(root, temp, temp->id);
			break;
		case 'd':
			printf("삭제할 학번 입력 : ");
			scanf("%d", &id);
			tmp = search(root, id);
			if (tmp == NULL)
				printf("id가 %d인 학생은 없습니다\n", id);
			else{
				root = delete_node(root, id);
				printf("id가 %d인 학생을 삭제하였습니다\n", id);
			}
			break;
		case 's':
			printf("탐색할 학번 입력: ");
			scanf("%d", &id);
			tmp = search(root, id);
			if (tmp == NULL)
				printf("id가 %d인 학생은 없습니다\n", id);
			else
				inorder(tmp);
			break;
		case 'p':
			printf("학생 정보 학번 순 출력\n");
			inorder(root);
			break;
		case 'c':
			printf("노드의 개수는 %d\n", count_node(root));
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