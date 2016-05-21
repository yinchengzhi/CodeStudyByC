#include<stdio.h>
#include<stdlib.h>

#define datatype int

typedef struct queue {
	int data;
	int high;										//优先级
	struct queue* pNext;
}Queue,*PQueue;

void init(PQueue *pphead);							//初始化
PQueue enq(PQueue phead, datatype data,int high);	//入队
PQueue deq(PQueue phead, datatype *pdata);			//出队
void show(PQueue phead);							//显示队列