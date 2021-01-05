//Heap트리
//최소heap
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct{
	int key;
}element;
typedef struct{
	element heap[MAX_ELEMENT];
	int head_size;
}HeapType;

//생성함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
//초기화 함수
void init(HeapType *h)
{
	h->head_size = 0;
}
//현재 요소의 개수가 head_size인 히프 h에 item삽입.
//삽입 함수
void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->head_size);

	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i/2].key)){//삽입할 값과 비교!
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}
//삭제 함수
element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item  = h->heap[1];
	temp = h->heap[(h->head_size)--];//temp 자리 찾는과정
	parent = 1;//맨 꼭대기에서부터 넣을자리 찾음 ->나중에 삽입할 index가될 변수
	child = 2;
	while(child <= h->head_size){
		if (child < h->head_size && h->heap[child].key < h->heap[child+1].key)//오른쪽, 왼쪽 child비교
			child++;//오른쪽으로 내려감
		if (temp.key <= h->heap[child].key) break;//적절한 위치
		//한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;//*= 2안되는 이유는 위에서 child가 ++되었을 수도 있으니까
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main(void)
{
	element e1 = {1}, e2 = {4}, e3 = {2}, e7 = {7};
	element e4, e5, e6, e8;
	HeapType *heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e7);

	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > ", e6.key);
	e8 = delete_max_heap(heap);
	printf("< %d > ", e8.key);

	free(heap);
	return 0;
}