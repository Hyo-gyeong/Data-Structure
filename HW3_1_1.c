#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3
#define MAX_STR_SIZE 30

typedef char element;

typedef struct {
	element name[MAX_QUEUE_SIZE][MAX_STR_SIZE];
	int front, rear;
}MQueueType;
typedef struct {
	element name[MAX_QUEUE_SIZE][MAX_STR_SIZE];
	int front, rear;
}FQueueType;

void error(char *message)
{
	printf("%s", message);
}

void init(FQueueType *fq, MQueueType *mq)
{
	mq->front = mq->rear = 0;
	fq->front = fq->rear = 0;
}

int f_is_empty(FQueueType *fq)
{
	return fq->front == fq->rear;
}

int m_is_empty(MQueueType *mq)
{
	return mq->front == mq->rear;
}

int f_is_full(FQueueType *fq)
{
	return fq->front == (fq->rear + 1) % MAX_QUEUE_SIZE;
}
int m_is_full(MQueueType *mq)
{
	return mq->front == (mq->rear + 1) % MAX_QUEUE_SIZE;
}

void f_enqueue(FQueueType *fq, element name[])
{
	int i;

	if (f_is_full(fq))
		error("����ڰ� ��á���� ���ȸ�� �̿롦\n");
	else{
		fq->rear = (fq->rear + 1) % MAX_QUEUE_SIZE;
		strcpy(fq->name[fq->rear], name);
	}
}

void m_enqueue(MQueueType *mq, element name[])
{
	int i;

	if (m_is_full(mq))
		error("����ڰ� ��á���� ���ȸ�� �̿롦\n");
	else{
		mq->rear = (mq->rear + 1) % MAX_QUEUE_SIZE;
		strcpy(mq->name[mq->rear], name);
	}
}

element f_dequeue(FQueueType *fq)
{
	if (f_is_empty(fq))
		error("ť�� ��������Դϴ�.\n");
	else {
		fq->front = (fq->front + 1) % MAX_QUEUE_SIZE;
	}
}

element m_dequeue(MQueueType *mq)
{
	if (m_is_empty(mq))
		error("ť�� ��������Դϴ�.\n");
	else {
		mq->front = (mq->front + 1) % MAX_QUEUE_SIZE;
	}
}

int get_f_count(FQueueType *fq)
{
	int count = 0;
	int front_index = fq->front;

	while(front_index != fq->rear){
		count++;
		front_index = (front_index + 1) % MAX_QUEUE_SIZE;
	}
	return count;
}
int get_m_count(MQueueType *mq)
{
	int count = 0;
	int front_index = mq->front;

	while(front_index != mq->rear){
		count++;
		front_index = (front_index + 1) % MAX_QUEUE_SIZE;
	}
	return count;
}

void print_f_queue(FQueueType *fq)
{
	int temp_index = fq->front;
	
	if (!f_is_empty(fq)){
		do{
			temp_index = (temp_index + 1) % MAX_QUEUE_SIZE;
			printf("%s", fq->name[temp_index]);
		}while(temp_index != fq->rear);
	}
}
void print_m_queue(MQueueType *mq)
{
	int temp_index = mq->front;

	if (!m_is_empty(mq)){
		do {
			temp_index = (temp_index + 1) % MAX_QUEUE_SIZE;
			printf("%s", mq->name[temp_index]);
		}while(temp_index != mq->rear);
	}
}

element peek(FQueueType *fq, MQueueType *mq)
{
	int i, j;

	printf("���� ����� %d��: ", get_m_count(mq));
	print_m_queue(mq);
	printf("\n");
	printf("���� ����� %d��: ", get_f_count(fq));
	print_f_queue(fq);
	printf("\n");
}

int main(void)
{
	FQueueType fq;
	MQueueType mq;

	char input, sex;
	char name[10];
	int couple = 0;

	init(&fq, &mq);
	printf("���� �ּ� ���α׷��Դϴ�.\n");
	do{
		printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>: ");
		scanf(" %c", &input);
		if (input == 'i'){
			printf("�̸��� �Է�:");
			scanf("%s", &name);
			printf("������ �Է�<m or f>:");
			scanf(" %c", &sex);
			if (sex == 'm'){
				m_enqueue(&mq, name);
				if (f_is_empty(&fq))
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�\n");
				else 
					couple = 1;
			}
			else if (sex == 'f'){
				f_enqueue(&fq, name);
				if (m_is_empty(&mq))
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�\n");
				else
					couple = 1;
			}
			if (couple == 1) {
				printf("Ŀ���� ź���߽��ϴ�!  %s�� %s\n", fq.name[(fq.front+1) % MAX_QUEUE_SIZE], mq.name[(mq.front+1) % MAX_QUEUE_SIZE]);
				f_dequeue(&fq);
				m_dequeue(&mq);
				couple = 0;
			}
		}
		else if (input == 'c')
			peek(&fq, &mq);
	}while(input != 'q');

}