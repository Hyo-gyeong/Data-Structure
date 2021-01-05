//���� Ž�� Ʈ��
//��� ������ Ű�� ������ Ű�� ����
//��Ʈ����...������ �۰� �������� ŭ
//����, ������ ��� ����Ž��Ʈ��
//program8.13
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

//��ȯ���� Ž��
TreeNode* search(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (node->key == key) return node;
	else if (node->key < key)
		return search(node->right, key);
	else
		return search(node->left, key);
}
//�ݺ����� Ž��
//Ʈ���� Ŭ���� ��ȯ���� �ξ� ȿ���� ����
/*
TreeNode* search(TreeNode *node, int key)
{
	while(node != NULL){
	if (key == node->key) return node;
	else if (key < node->key)
		node = node->left;
	else
		node = node->right;
	}
	return NULL;
}
*/
TreeNode * new_node(int item)
{
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * insert_node(TreeNode *node, int key)
{
	if (node == NULL) return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;
}
TreeNode *min_value_node(TreeNode *node)
{
	TreeNode * current = node;
	
	while(current->left = NULL)
		current = current->left;//����Ž��Ʈ���� Ư¡, ������ ������
	return current;
}
TreeNode * delete_node(TreeNode * root, int key)
{
	TreeNode *temp;

	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else{
		//������ ��ͺθ��ֵ��� return�� ����.
		//1.�����Ϸ��� ��尡 �ܸ� ����� ��쳪 �ϳ��� ����Ʈ���� ������ �ִ� ���
		if (root->left == NULL){//�����ʿ� �޷��ִ� ��尡 �� �� �ö��
			TreeNode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL){//���ʿ� �޷��ִ� ��尡 �� �� �ö��
			TreeNode *temp = root->left;
			free(root);
			return temp;
		}
		//2.�����Ϸ��� ��尡 �ΰ��� ����Ʈ���� ������ �ִ� ���
		//����, ������ ������ �� �� �ִ� ��尡 �����Ǹ� �Ʒ� ��� �ҷ�����
		//�ö������ ������ Ʈ������(��Ʈ���� ������ ���� ū Ʈ��) ���� ���� ���� �;���.
		temp = min_value_node(root->right);//���� ���Ƽ� �Լ� �ʹݿ� �������ְ� ���ٽ����..��"��

		root->key = temp->key;//�İ��� ����
		root->right = delete_node(root->right, temp->key);//�����ؼ� �ö�����ϱ� ���� ����
	}
	return root;
}
void inorder(TreeNode * root){
	if(root){
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}
int main(void)
{
	TreeNode *root = NULL;
	TreeNode *tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("���� Ž�� Ʈ�� ���� ��ȸ���\n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("30 ����\n");
	else printf("30 ����\n");
	return;
}