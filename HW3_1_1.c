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
		error("대기자가 꽉찼으니 담기회를 이용…\n");
	else{
		fq->rear = (fq->rear + 1) % MAX_QUEUE_SIZE;
		strcpy(fq->name[fq->rear], name);
	}
}

void m_enqueue(MQueueType *mq, element name[])
{
	int i;

	if (m_is_full(mq))
		error("대기자가 꽉찼으니 담기회를 이용…\n");
	else{
		mq->rear = (mq->rear + 1) % MAX_QUEUE_SIZE;
		strcpy(mq->name[mq->rear], name);
	}
}

element f_dequeue(FQueueType *fq)
{
	if (f_is_empty(fq))
		error("큐가 공백상태입니다.\n");
	else {
		fq->front = (fq->front + 1) % MAX_QUEUE_SIZE;
	}
}

element m_dequeue(MQueueType *mq)
{
	if (m_is_empty(mq))
		error("큐가 공백상태입니다.\n");
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

	printf("남성 대기자 %d명: ", get_m_count(mq));
	print_m_queue(mq);
	printf("\n");
	printf("여성 대기자 %d명: ", get_f_count(fq));
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
	printf("미팅 주선 프로그램입니다.\n");
	do{
		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>: ");
		scanf(" %c", &input);
		if (input == 'i'){
			printf("이름을 입력:");
			scanf("%s", &name);
			printf("성별을 입력<m or f>:");
			scanf(" %c", &sex);
			if (sex == 'm'){
				m_enqueue(&mq, name);
				if (f_is_empty(&fq))
					printf("아직 대상자가 없습니다. 기다려주십시오\n");
				else 
					couple = 1;
			}
			else if (sex == 'f'){
				f_enqueue(&fq, name);
				if (m_is_empty(&mq))
					printf("아직 대상자가 없습니다. 기다려주십시오\n");
				else
					couple = 1;
			}
			if (couple == 1) {
				printf("커플이 탄생했습니다!  %s과 %s\n", fq.name[(fq.front+1) % MAX_QUEUE_SIZE], mq.name[(mq.front+1) % MAX_QUEUE_SIZE]);
				f_dequeue(&fq);
				m_dequeue(&mq);
				couple = 0;
			}
		}
		else if (input == 'c')
			peek(&fq, &mq);
	}while(input != 'q');

}