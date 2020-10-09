#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

void print_list(ListNode *head)//��������Ʈ�� head�� ������ node�� ������.
{
	ListNode *p;

	if (head == NULL){
		printf("����Ʈ�� ��\n");
		return;
	}
	p = head->link; //�� ���� node�� ����Ű�Ե�.
	if (head->link == head){
		printf("%d->����Ʈ�� ��\n", p->data);
		return;
	}
	else {
		do {
			printf("%d->", p->data);
			p = p->link;
		}while(p != head); 
		printf("%d->����Ʈ�� ��\n", p->data);
	}
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL){ //�������� ����� ���� �����������!
		node->link = node;
		head = node;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode *head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL){
		node->link = node;
		head = node;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* delete_first(ListNode *head)
{
	ListNode *temp;

	if (head == NULL){
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	if (head == head->link){ //node�� �� �� ����
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link; //*head->link
		free(temp);
	}
	return head;
}

ListNode* delete_last(ListNode* head)//**
{
	ListNode *pre_head = head, *temp;

	if (head == NULL)
		return NULL;
	if (head == head->link){
		head = NULL;
		free(pre_head);
	}
	else{
		while(pre_head->link != head) 
			pre_head = pre_head->link; 
		temp = head;
		pre_head->link = temp->link;
		free(temp);
		head = pre_head;
	}
	return head;
}

ListNode* search(ListNode *head, element data)
{
	ListNode *temp = head;
	int if_exist = 0;

	if (head == NULL){
		printf("����Ʈ�� ����ֽ��ϴ�.\n", data);
		return NULL;
	}
	else{
		do{
			if (temp->data == data){
				if_exist = 1;
				break;
			}
			temp = temp->link;
		}while(temp != head);
		if (if_exist)
			printf("%d�� �����մϴ�.\n", data);
		else
			printf("%d�� �������� �ʽ��ϴ�.\n", data);
		return head;
	}		
			
}

int get_size(ListNode *head)
{
	ListNode *temp = head;
	int len;

	if (head == NULL)
		return 0;

	len = 0;
	do{
		len++;
		temp = temp->link;
	}while(temp != head);
	return len;
}

int main(void)
{
	ListNode *head = NULL;

	head = insert_last(head, 20);
	print_list(head);
	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	head = delete_first(head);
	print_list(head);
	head = delete_last(head);
	print_list(head);

	printf("����Ʈ�� ���̴� %d\n", get_size(head));
	head = search(head, 50);
	head = search(head, 20);		

	return;
}