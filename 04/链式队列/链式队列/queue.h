#include<stdio.h>
#include<stdlib.h>

#define datatype int


typedef struct queue{
	datatype data;
	struct queue *pNext;
}Queue,*PQueue;

void init(PQueue *pphead);
PQueue enq(PQueue phead, datatype data);				//���
PQueue deq(PQueue phead, datatype *pdata);				//����
void show(PQueue phead);								//��ʾ����