#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h)
{
	h->heap_size =0;
} 
void insert_max_heap(HeapType *h, element item)
{
	int i;

	i = ++(h->heap_size);
	while(i != 1 && item.key > h->heap[i/2].key){
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	parent = 1;
	child = 2;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	while(child <= h->heap_size){
		if ((child < h->heap_size) &&//왼쪽 노드만 있을 수 있으니
			(h->heap[child].key) < (h->heap[child+1].key))
			child++;
		if (temp.key > h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void preorder(HeapType *h, int root)
{
	if (root <= h->heap_size){
		printf("%d ", h->heap[root].key);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}
void print_heap(HeapType *h)
{
	int i = 1, j = 0;

	while(i <= h->heap_size){
		printf("%d ", h->heap[i].key);
		if (i == 1 || i % 2 == j){
			printf("\n");
			j++;
		}
		i++;
	}
}
void print_sorted_value(HeapType h)
{
	HeapType temp = h;
	int i = 1;

	while(i++ <= h.heap_size)
		printf("%d ", delete_max_heap(&temp));

}
int find(HeapType *h, int root, int key)
{
	while (root <= h->heap_size){
		if (h->heap[root].key == key)
			return root;
		root++;
	}
	return 0;
}
void modify_priority(HeapType *h, int oldK, int newK)
{
	int parent;
	int child;
	int key_index = find(h, 1, oldK);

	h->heap[key_index].key = newK;
	
	parent = key_index /2;
	child = key_index * 2;
	if (newK > h->heap[parent].key && parent != 0){
		while(newK > h->heap[parent].key && parent > 0){
			if (h->heap[child].key < h->heap[child+1].key)
				child++;
			h->heap[key_index] = h->heap[parent];
			parent /= 2;
			child /= 2;
			key_index = child / 2;
		}
		key_index = child / 2;
	}
	else if (newK < h->heap[child].key){
		while(newK < h->heap[child].key && child <= h->heap_size){
			if (h->heap[child].key < h->heap[child+1].key)
				child++;
			h->heap[key_index] = h->heap[child];
			parent *= 2;
			child *= 2;
			key_index = child / 2;
		}
	}
	h->heap[key_index].key = newK;
	
}
int main(void)
{
	 element e1={10}, e2={5}, e3={30}, eA = {9}, eB = {19}, eC = {39};
	 element e4, e5, e6;
	 int index;
	 int key, oldKey, newKey;
	 HeapType heap; // 히프 생성

	 init(&heap); // 초기화

	 printf("Step1: 삽입된 10, 5, 30 에 추가적으로 9, 19, 39 를 <삽입> 한다");
	 insert_max_heap(&heap, e1);
	 insert_max_heap(&heap, e2);
	 insert_max_heap(&heap, e3);
	 insert_max_heap(&heap, eA);
	 insert_max_heap(&heap, eB);
	 insert_max_heap(&heap, eC);

	 printf("\nStep2: preorder, print_heap 함수 테스트\n");
	 preorder(&heap, 1);
	 printf("\n\n");
	 print_heap(&heap);

	 e4 = delete_max_heap(&heap);
	 printf("\n 삭제: 루트%d가 삭제됨\n", e4.key);
	 print_heap(&heap);

	 printf("\nStep3: find 함수 테스트\n");
	 printf("찾을 key 입력(-1 for exit):");
	 scanf("%d", &key);
	 while (key != -1) {
		 if ((index = find(&heap, 1, key)) == 0)
			printf("%d 는 없음\n", key);
		 else
			printf("%d 은 [%d]에 있음\n", key, index);
		 printf("찾을 key 입력(-1 for exit):");
		 scanf("%d", &key);
	 }

	 printf("\nStep4: print_sorted_value 함수 테스트\n");
	 print_sorted_value(heap);

	 printf("\nStep5: modify_priority 함수 테스트\n");
	 printf("바꿀 key 입력(-1 for exit):");
	 scanf("%d", &oldKey);
	 while (oldKey != -1) {
		 printf("새 key 입력:");
		 scanf("%d", &newKey);
		 modify_priority(&heap, oldKey, newKey);
		 print_heap(&heap);

		 printf("바꿀 key 입력(-1 for exit):");
		 scanf("%d", &oldKey);
	 }
} 