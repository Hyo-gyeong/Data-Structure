#include <stdio.h>
#define MAX_LIST_SIZE 5 // 리스트의 최대크기

typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
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
		printf("리스트 오버플로우\n");
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
		printf("리스트 오버플로우\n");
}
void print_list(ArrayListType *L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("리스트끝\n");
}

void clear(ArrayListType *L)
{
	L->size = 0;
}
void insert_last(ArrayListType *L, element item)
{
	if( L->size >= MAX_LIST_SIZE ) {
		printf("리스트 오버플로우");
	}else
		L->array[L->size] = item;
	L->size++;

}
element delete_item(ArrayListType *L, int pos)
{
	element item;
	int i;

	if (pos < 0 || pos > L->size)
		printf("위치 오류");
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
		printf("삭제하려는 key값 %d은 리스트에 없습니다.\n", key);

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

	printf("\n-이 이후는 HW1_1에서 추가한 함수들 테스트-\n");
	insert_first(&list1, 9); print_list(&list1);
	insert_last(&list1, 99); print_list(&list1);

	// 현재 리스트가 꽉 찬(크기 5개) 상태이므로 한 항목을 더 추가하면 "리스트 오버플로우"을 출력한다. 
	insert_first(&list1, 1); print_list(&list1);

	printf("길이는 %d\n", get_length(&list1));
	printf("3번째 데이타는 %d\n", get_entry(&list1, 2));

	replace(&list1, 3, 40); print_list(&list1);
	printf("20은 리스트에 %s\n", is_in_list(&list1, 20) ? "있습니다" : "없습니다");//0이 아니면 참
	printf("22는 리스트에 %s\n", is_in_list(&list1, 22) ? "있습니다" : "없습니다");

	delete_by_key(&list1, 20); print_list(&list1);
	delete_by_key(&list1, 22); print_list(&list1);
}