#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

void print_list(ListNode *head)
{
	ListNode *p;

	if (head == NULL)
		printf("리스트가 비어있습니다.\n");
	else {
		for (p = head; p != NULL; p = p->link)
			printf("%d->", p->data);
		printf("\n");
	}
	return;
}

ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;//따로 하나 만들고
	p->link = head;
	head = p;

	return head;
}

ListNode* insert_last(ListNode *head, int value)
{
	ListNode *temp = head;

	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (head == NULL)
		head = p;
	else {
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;

	if (head == NULL)
		printf("삭제할 항목 없음\n");
	else{
		removed = head;
		head = removed->link;
		free(removed);
		return head;
	}
}

ListNode* delete_last(ListNode *head)
{
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;

	if(head == NULL)
		printf("삭제할 항목 없음\n");
	else if (head->link == NULL){
		head = NULL;
		free(head);
	}
	else {
		while(temp->link != NULL){
			prevTemp = temp;
			temp = temp->link;
		}
		prevTemp->link = NULL;
		free(temp);
	}
	return head;
}

ListNode* reverse(ListNode *head)
{
	ListNode *p,*q,*r;
	p = head;
	q = NULL;
	while(p != NULL){
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

ListNode* concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		p = head1;
		while(p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

int is_in_list(ListNode *head, element item)
{
	ListNode *p;

	p = head;
	while(p->link != NULL){
		if (p->data == item)
			return 1;
		p = p->link;
	}
	return 0;
}

int get_length(ListNode *head)
{
	ListNode *p;
	int count = 0;

	for (p = head; p != NULL; p = p->link)
		count++;

	return count;

}

int get_total(ListNode *head)
{
	ListNode *p;
	int total = 0;

	for (p = head; p != NULL; p = p->link)
		total += p->data;
	return total;
}

element get_entry(ListNode *head, int pos)
{
	ListNode *p = head;
	int i;

	for (i = 0; i < pos; i++)
		p = p->link;
	return p->data;
}

ListNode* delete_by_key(ListNode *head, int key){	ListNode *p, *prevP, *removed;	int if_first = 0;	if (get_length(head) == 0){		printf("리스트가 비어있습니다.\n");		return head;	}	else if (get_length(head) == 1){		p = head;		head = NULL;		free(p);		return head;	}	else {		p = head;		while(p->data != key){			prevP = p;			p = p->link;			if_first = 1;		}		if (if_first == 0){			head = p->link;			free(p);		}		else {			removed = p;			p = removed->link;			prevP->link = p;					free(removed);		}		return head;	}}

ListNode* insert_pos(ListNode *head, int pos, element item)
{
	ListNode *p = head, *temp, *prevP;
	int i = 0;
	temp = (ListNode *)malloc(sizeof(ListNode));

	temp->data = item;
	temp->link = NULL;//초기화 해줘야함

	if (pos == 0){
		temp->link = p;
		head = temp;
		return head;
	}
	else {
		while(i < pos){
			prevP = p;
			p = p->link;
			i++;
		}
		temp->link = p;
		prevP->link = temp;
		return head;
	}
}

ListNode* delete_pos(ListNode *head, int pos)
{
	ListNode *p = head, *prevP;
	int i = 0;

	if (pos == 0){
		head = p->link;
		free(p);
	}
	else {
		while(i < pos){
			prevP = p;
			p = p->link;
			i++;
		}
		printf("p = %d", p->data);
		printf("prev = %d   ", prevP->data);
		prevP->link = p->link;
		free(p);
	}
	return head;

}

int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3;

	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);

	printf("list1: ");
	print_list(list1);

	list1 = delete_first(list1);
	printf("delete first node: ");
	print_list(list1);

	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	printf("list2 : ");
	print_list(list2);

	printf("delete last node: ");
	list2 = delete_last(list2);
	print_list(list2);

	list3 = reverse(list2);
	printf("reverse list2: ");
	print_list(list3);

	list1 = concat(list1, list3);
	printf("concat list1, list3: ");
	print_list(list1);

	printf("33은 ");
	if (is_in_list(list1, 33))
		printf("list1에 있습니다.\n");
	else
		printf("list1에 없습니다.\n");

	printf("\n");
	printf("list1 : ");
	print_list(list1);
	printf("list1의 길이는 %d\n",get_length(list1));
	printf("list1의 데이터 합은 %d\n",get_total(list1));
	printf("list1의 3번째 데이터는 %d\n", get_entry(list1, 2));
	printf("\n");
	printf("list2 : ");
	print_list(list2);
	printf("list2의 길이는 %d\n",get_length(list2));
	printf("list2의 데이터 합은 %d\n",get_total(list2));
	printf("list2의 1번째 데이터는 %d\n", get_entry(list2, 0));
	printf("\n");
	printf("list3 : ");
	print_list(list3);
	printf("list3의 길이는 %d\n",get_length(list3));
	printf("list3의 데이터 합은 %d\n",get_total(list3));
	printf("list3의 2번째 데이터는 %d\n", get_entry(list3, 1));

	printf("list1의 20제거한 후: ");
	list1 = delete_by_key(list1, 20);
	print_list(list1);

	printf("insert 80: ");
	list1 = insert_pos(list1, 3, 80);
	print_list(list1);

	printf("delete index 2: ");
	list1 = delete_pos(list1, 2);
	print_list(list1);
}