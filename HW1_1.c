#include <stdio.h>
#define MAX_LIST_SIZE 5 // ����Ʈ�� �ִ�ũ��

typedef int element; // �׸��� ����
typedef struct {
	element array[MAX_LIST_SIZE]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
}ArrayListType; 

void init(ArrayListType *L)
{
	L->size = 0;
}

int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE;
}

void insert(ArrayListType *L, int pos, element item)
{
	int i;

	if (!is_full(L) && (pos >= 0 && pos <= L->size)) {
		for (i = L->size-1; i >= pos; i--)
			L->array[i+1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}else
		printf("����Ʈ �����÷ο�\n");
}
void insert_first(ArrayListType *L, element item)
{
	int i;

	if (!is_full(L)) {
		for (i = L->size; i >= 0; i--)
			L->array[i] = L->array[i-1];
		L->array[0] = item;
		L->size++;
	}else
		printf("����Ʈ �����÷ο�\n");
}
void print_list(ArrayListType *L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("����Ʈ��\n");
}

void clear(ArrayListType *L)
{
	L->size = 0;
}
void insert_last(ArrayListType *L, element item)
{
	if( L->size >= MAX_LIST_SIZE ) {
		printf("����Ʈ �����÷ο�");
	}else
		L->array[L->size] = item;
	L->size++;

}
element delete_item(ArrayListType *L, int pos)
{
	element item;
	int i;

	if (pos < 0 || pos > L->size)
		printf("��ġ ����");
	item = L->array[pos];
	for (i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	
	return item;
} 
int get_length(ArrayListType *L) 
{
	return L->size;
}

int get_entry(ArrayListType *L, int index)
{
	return L->array[index];
}

void replace(ArrayListType *L, int index, element item)
{
	L->array[index] = item;
}
int is_in_list(ArrayListType *L, element item)
{
	int i;

	for (i = 0; i < L->size; i++)
		if (L->array[i] == item)
			return i;
	return 0;
}
void delete_by_key(ArrayListType *L, element key)
{
	int i;
	int if_exist = is_in_list(L, key);

	if (if_exist != 0){
		for (i = if_exist; i < (L->size - 1); i++)
			L->array[i] = L->array[i + 1];
		L->size--;
	}else
		printf("�����Ϸ��� key�� %d�� ����Ʈ�� �����ϴ�.\n", key);

}
int main(void)
{
	ArrayListType list1;
 
	init(&list1);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);
	clear(&list1); print_list(&list1);

	insert_last(&list1, 90); print_list(&list1);
 
	insert(&list1, 0, 30);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);
 
	delete_item(&list1, 2); print_list(&list1);

	printf("\n-�� ���Ĵ� HW1_1���� �߰��� �Լ��� �׽�Ʈ-\n");
	insert_first(&list1, 9); print_list(&list1);
	insert_last(&list1, 99); print_list(&list1);

	// ���� ����Ʈ�� �� ��(ũ�� 5��) �����̹Ƿ� �� �׸��� �� �߰��ϸ� "����Ʈ �����÷ο�"�� ����Ѵ�. 
	insert_first(&list1, 1); print_list(&list1);

	printf("���̴� %d\n", get_length(&list1));
	printf("3��° ����Ÿ�� %d\n", get_entry(&list1, 2));

	replace(&list1, 3, 40); print_list(&list1);
	printf("20�� ����Ʈ�� %s\n", is_in_list(&list1, 20) ? "�ֽ��ϴ�" : "�����ϴ�");//0�� �ƴϸ� ��
	printf("22�� ����Ʈ�� %s\n", is_in_list(&list1, 22) ? "�ֽ��ϴ�" : "�����ϴ�");

	delete_by_key(&list1, 20); print_list(&list1);
	delete_by_key(&list1, 22); print_list(&list1);
}