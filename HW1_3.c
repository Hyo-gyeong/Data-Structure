#include <stdio.h>
#include <stdlib.h>
#define MAX_SUM_WEIGHT 100

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

ListNode* add_item(ListNode *phead, int new_item)
{
	ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
	ListNode *temp = phead;
	int sum = 0;
	
	newnode->data = new_item;
	
	if (phead == NULL){
		phead = newnode;
		newnode->link = NULL;
	}
	else {
		while(temp != NULL){
			sum += temp->data;
			temp = temp->link;
		}
		sum += new_item;
		if (sum > MAX_SUM_WEIGHT){
			printf("최대 무게<%d> 초과로 아이템 %d를 추가할 수 없음.\n",MAX_SUM_WEIGHT, new_item);
			return phead;
		}
		temp = phead;
		newnode->link = temp;
		phead = newnode;
	}
	return phead;
}

ListNode* delete_item(ListNode* phead, int delete_item)
{
	ListNode *temp = phead, *preTemp;

	if (temp->data == delete_item){
		phead = temp->link;
		free(temp);
	}
	else {
		while(temp != NULL){
			if (temp->data == delete_item)
				break;
			preTemp = temp;
			temp = temp->link;
		}
		if (temp == NULL)
			printf("아이템 %d는 보유하고 있지 않습니다.\n", delete_item);
		else{
			preTemp->link = temp->link;
			free(temp);
		}
	}
	return phead;
}

void display(ListNode *list)
{
	ListNode *temp = list;

	printf("< ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf(">\n");
}

int main(void)
{
	ListNode *list = NULL;
	char choice;
	int weight;

	do {
		printf("enter a<dd>, d<elete> or q<uit>: ");
		scanf("%c", &choice);
		switch (choice){
		case 'a':
			printf("Enter the weight of the item : ");
			scanf("%d", &weight);
			list = add_item(list, weight);
			display(list);
			break;
		case 'd':
			printf("Enter the weight of the item : ");
			scanf("%d", &weight);
			list = delete_item(list, weight);
			display(list);
			break;
		}
		while (getchar() != '\n');
	}while(choice != 'q');
} 