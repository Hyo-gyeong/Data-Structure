#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_PER_LINE 100

typedef struct {
 char line[MAX_CHAR_PER_LINE];
}element; 
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

void print_list(ListNode *phead)
{
	ListNode *p;
	int num;
	int count = 1;

	printf("----------text edited---------\n");
	for (p = phead; p != NULL; p = p->link){
		printf("(%d)", count);
		num = 0;
		while(p->data.line[num] != '\0')
			printf("%c", p->data.line[num++]);
		count++;
	}
}

void print_lineNB(ListNode *before, int lineNb)
{
	ListNode *temp = before;
	int i, j = 0;

	for (i = 0; i < lineNb-1; i++)
		temp = temp->link;
	while(temp->data.line[j] != '\0')
		printf("%c", temp->data.line[j++]);
}
ListNode* insert(ListNode *before, element data)
{
	ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
	ListNode *temp = before;

	newnode->data = data;
	if (before != NULL){
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = newnode;
	}
	else
		before = newnode;
	newnode->link = NULL;
	return before;
}

ListNode* insert_lineNB(ListNode *before, int lineNb, element data)
{
	int i;
	ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
	ListNode *temp = before, *preTemp;
	newnode->data = data;

	if (lineNb == 1){
		newnode->link = before;
		before = newnode;
		return before;
	}
	else{
		for(i = 0; i < lineNb-1; i++){
			preTemp = temp;
			temp = temp->link;
		}
		newnode->link = temp;
		preTemp->link = newnode;
		return before;
	}
}

ListNode* delete_lineNB(ListNode *before, int lineNb)
{
	ListNode *temp = before, *preTemp;
	int i;

	if (lineNb == 1){
		before = before->link;
		free(temp);
		return before;
	}
	else {
		for (i = 0; i < lineNb-1; i++){
			preTemp = temp;
			temp = temp->link;
		}
		preTemp->link = temp->link;
		free(temp);
		return before;
	}
}

char askChoice(void) 
{
	char choice;

	printf("------------------------------\n"); 
	printf("a: 텍스트 끝에 라인 추가\n"); 
	printf("i: 라인 번호로 라인 추가\n"); 
	printf("d: 라인 번호로 라인 삭제\n");
	printf("v: 라인 번호로 해당 라인 출력\n");
	printf("p: 전체 텍스트 출력\n");
	printf("q: 끝\n");

	printf("메뉴 선택:");
	scanf("%c", &choice);
	return choice;
} 

int main(void) // 3)
{
	ListNode *list = NULL;
	char choice;
	int lineNb;
	element newElement;
 
	while ((choice = askChoice()) != 'q') {
		switch (choice) {
			case 'a':
				printf("텍스트 끝에 삽입할 라인: ");
				while (getchar() != '\n');
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				list = insert(list, newElement);
				print_list(list);
				break;
			case 'i':
				printf("삽입할 라인 번호: ");
				scanf("%d", &lineNb);
				printf("삽입할 라인: ");
				while (getchar() != '\n');
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				list = insert_lineNB(list, lineNb, newElement);
				print_list(list);
				break;
			case 'd':
				printf("삭제할 라인 번호: ");
				scanf("%d", &lineNb);
				list = delete_lineNB(list, lineNb);
				print_list(list);
				break;
			case 'v':
				printf("출력할 라인 번호: ");
				scanf("%d", &lineNb);
				print_lineNB(list, lineNb);
				break;
			case 'p':
				 print_list(list);
		}
		fflush(stdin);
	}
} 