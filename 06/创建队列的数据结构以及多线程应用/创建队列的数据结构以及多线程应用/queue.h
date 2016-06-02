#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define N 100
#define mytype int

struct MyQueue{
	mytype data[N];						//数组存储队列
	int front;							//拉屎
	int rear;							//吃东西
};

typedef struct MyQueue myQ;				//简写


void init(myQ *p);
int isfull(myQ *p);
int isEmpty(myQ *p);

void enQ(myQ *p,mytype insertdata);		//吃
void deQ(myQ *p);						//拉

mytype getlast(myQ *p);					//获取当前要拉的
void print(myQ *p);						//打印