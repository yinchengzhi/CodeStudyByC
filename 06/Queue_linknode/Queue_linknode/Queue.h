#include<stdio.h>
#include<stdlib.h>

struct queue{
	int num;										//代表数据
	int high;										//优先级1111
	struct queue *pNext;							//存储下一个节点的地址 
};

typedef struct queue Queue;							//简化队列

Queue *init(Queue *queueA);							//初始化
Queue *EnQueue(Queue *queueA,int num,int high);		//入队
Queue *DeQueue(Queue *queueA, Queue *pout);			//出队
Queue *freeall(Queue *queueA);						//清空
void sort(Queue *queueA);							//优先级排队
void printall(Queue *queueA);						//打印所有数据,递归

Queue *insertEnQueue(Queue *queueA, int num, int high);