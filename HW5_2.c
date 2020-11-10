#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define FILE_NAME "input.txt"

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
void read_heap(HeapType *h, char *filename)
{
	FILE *fp = fopen(filename, "r");
	element temp;
	int n;
	
	if (fp == NULL) {
		fprintf(stderr, "파일 %s을 열 수 없음!\n", filename); 
		return;
	} 

	while (fscanf(fp, "%d\n", &n) != EOF){
		temp.key = n;
		insert_max_heap(h, temp);
	}
	fclose(fp);
}
void write_heap_array(HeapType *h, char *filename)
{
	FILE *fp;
	int i = 1;

	if (filename == NULL) fp = stdout;
	else {
		fp = fopen(filename, "w");
		while (i <= h->heap_size){
			fprintf(fp, "%d\n", h->heap[i].key);
			i++;
		}		
		if (fp == NULL) {
			fprintf(stderr, "파일 %s을 열 수 없음!\n", filename); 
			return;
		}
	 } 
	fclose(fp);
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
void write_descending_order(HeapType *h, char *filename) 
{
	FILE *fp;
	HeapType temp = *h;//?...
	int i = 1;
	
	fp = fopen(filename,  "w");

	while(i <= h->heap_size){
		fprintf(fp, "%d ", delete_max_heap(&temp).key);
		i++;
	}
}
int main(void)
{
	HeapType heap;
	element e1 = {20}, e2 = {40};
	init(&heap);

	read_heap(&heap, FILE_NAME);
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	
	write_heap_array(&heap, "heapArray.txt");
	write_descending_order(&heap, "sorted.txt");
} 