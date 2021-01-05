//HeapƮ��
//�ּ�heap
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

//�����Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
//�ʱ�ȭ �Լ�
void init(HeapType *h)
{
	h->head_size = 0;
}
//���� ����� ������ head_size�� ���� h�� item����.
//���� �Լ�
void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->head_size);

	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i/2].key)){//������ ���� ��!
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}
//���� �Լ�
element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item  = h->heap[1];
	temp = h->heap[(h->head_size)--];//temp �ڸ� ã�°���
	parent = 1;//�� ����⿡������ �����ڸ� ã�� ->���߿� ������ index���� ����
	child = 2;
	while(child <= h->head_size){
		if (child < h->head_size && h->heap[child].key < h->heap[child+1].key)//������, ���� child��
			child++;//���������� ������
		if (temp.key <= h->heap[child].key) break;//������ ��ġ
		//�� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;//*= 2�ȵǴ� ������ ������ child�� ++�Ǿ��� ���� �����ϱ�
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