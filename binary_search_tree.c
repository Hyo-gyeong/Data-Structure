//이진 탐색 트리
//모든 원소의 키는 유일한 키로 갖음
//루트보다...왼쪽은 작고 오른쪽은 큼
//왼쪽, 오른쪽 모두 이진탐색트리
//program8.13
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

//순환적인 탐색
TreeNode* search(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (node->key == key) return node;
	else if (node->key < key)
		return search(node->right, key);
	else
		return search(node->left, key);
}
//반복적인 탐색
//트리가 클수록 순환보다 훨씬 효율이 좋음
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
		current = current->left;//이진탐색트리의 특징, 왼쪽이 작은값
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
		//위에서 재귀부른애들이 return값 받음.
		//1.삭제하려는 노드가 단말 노드일 경우나 하나의 서브트리만 가지고 있는 경우
		if (root->left == NULL){//오른쪽에 달려있던 노드가 한 층 올라옴
			TreeNode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL){//왼쪽에 달려있던 노드가 한 층 올라옴
			TreeNode *temp = root->left;
			free(root);
			return temp;
		}
		//2.삭제하려는 노드가 두개의 서브트리를 가지고 있는 경우
		//왼쪽, 오른쪽 꼬리가 둘 다 있는 노드가 삭제되면 아래 노드 불러야함
		//올라오려면 오른쪽 트리에서(루트보다 노드들의 값이 큰 트리) 가장 작은 값이 와야함.
		temp = min_value_node(root->right);//버전 낮아서 함수 초반에 정의해주고 갖다써야함..ㅡ"ㅡ

		root->key = temp->key;//후계노드 복사
		root->right = delete_node(root->right, temp->key);//복사해서 올라왔으니까 원본 삭제
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

	printf("이진 탐색 트리 중위 순회결과\n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("30 없음\n");
	else printf("30 있음\n");
	return;
}