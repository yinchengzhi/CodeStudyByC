#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define N 100
#define mytype int

struct MyQueue{
	mytype data[N];						//����洢����
	int front;							//��ʺ
	int rear;							//�Զ���
};

typedef struct MyQueue myQ;				//��д


void init(myQ *p);
int isfull(myQ *p);
int isEmpty(myQ *p);

void enQ(myQ *p,mytype insertdata);		//��
void deQ(myQ *p);						//��

mytype getlast(myQ *p);					//��ȡ��ǰҪ����
void print(myQ *p);						//��ӡ