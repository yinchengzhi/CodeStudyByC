#include<stdio.h>
#include<stdlib.h>

#define datatype int


typedef struct queue{
	datatype data;
	struct queue *pNext;
}Queue,*PQueue;

void init(PQueue *pphead);
PQueue enq(PQueue phead, datatype data);				//入队
PQueue deq(PQueue phead, datatype *pdata);				//出队
void show(PQueue phead);								//显示队列