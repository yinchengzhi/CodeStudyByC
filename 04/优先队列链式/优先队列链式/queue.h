#include<stdio.h>
#include<stdlib.h>

#define datatype int

typedef struct queue {
	int data;
	int high;										//���ȼ�
	struct queue* pNext;
}Queue,*PQueue;

void init(PQueue *pphead);							//��ʼ��
PQueue enq(PQueue phead, datatype data,int high);	//���
PQueue deq(PQueue phead, datatype *pdata);			//����
void show(PQueue phead);							//��ʾ����