#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
}DListNode;

void init(DListNode *phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode *phead)
{
	DListNode *p;

	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-| |%d| |->", p->data);
	printf("\n");
}

void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;

	if (before->rlink == before && before->llink == before){
		newnode->llink = before;
		before->llink = newnode;
		newnode->rlink = before;
		before->rlink = newnode;
	}
	else {
		newnode->llink = before;
		before->rlink->llink = newnode;
		newnode->rlink = before->rlink;
		before->rlink = newnode;
	}
}

void ddelete(DListNode *head, DListNode *removed)
{
	if(removed == head)
		return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_reverse_dlist(DListNode *head)
{
	DListNode *p;

	for (p = head->llink; p != head; p = p->llink)
		printf("<-| |%d| |->", p->data);
	printf("\n");
}

DListNode* search(DListNode *head, element data)
{
	DListNode *p;
	p = head->rlink;

	while(p != head){
		if (p->data == data){
			printf("%d가 리스트에 존재합니다.\n", data);
			return head;
		}
		p = p->rlink;
	}
	printf("%d가 리스트에 존재하지 않습니다.\n", data);
	return head;
}

int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	printf("추가 단계\n");

	// 맨 앞에 노드를 삽입
	 dinsert(head, 10);
	 print_dlist(head);
	 dinsert(head, 20);
	 print_dlist(head);
	 dinsert(head, 30);
	 print_dlist(head); 

	// 맨 뒤에 노드를 삽입하려면?
	dinsert(head->llink, 99);
	print_dlist(head);

	printf("reverse: ");
	print_reverse_dlist(head);

	search(head, 7);
	search(head, 99);

	printf("\n삭제 단계\n");

	// 맨 앞의 노드를 삭제
	ddelete(head, head->rlink);
	print_dlist(head);

	// 맨 뒤의 노드를 삭제하려면?
	ddelete(head, head->llink);
	print_dlist(head);

	

 
	free(head);
	return 0;
}