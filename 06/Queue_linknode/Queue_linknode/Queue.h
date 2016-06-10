#include<stdio.h>
#include<stdlib.h>

struct queue{
	int num;										//��������
	int high;										//���ȼ�1111
	struct queue *pNext;							//�洢��һ���ڵ�ĵ�ַ 
};

typedef struct queue Queue;							//�򻯶���

Queue *init(Queue *queueA);							//��ʼ��
Queue *EnQueue(Queue *queueA,int num,int high);		//���
Queue *DeQueue(Queue *queueA, Queue *pout);			//����
Queue *freeall(Queue *queueA);						//���
void sort(Queue *queueA);							//���ȼ��Ŷ�
void printall(Queue *queueA);						//��ӡ��������,�ݹ�

Queue *insertEnQueue(Queue *queueA, int num, int high);