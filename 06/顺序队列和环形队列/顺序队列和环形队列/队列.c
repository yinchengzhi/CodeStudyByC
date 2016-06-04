#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100
#define datatype int

typedef struct queue{
	datatype data[N];
	int rear;									//吃东西
	int front;									//拉屎
}myQ,*PmyQ;


void init(PmyQ p);
int isfull(PmyQ p);
int isempty(PmyQ p);
void show(PmyQ p);
void enQ(PmyQ p,datatype newdata);
void deQ(PmyQ p);

datatype getlast(PmyQ p);

void init(PmyQ p) {								//初始化
	memset(p->data, 0, sizeof(datatype)*N);
	p->front = p->rear = 0;
}

int isfull(PmyQ p) {
	if (p->rear == N) {
		return 1;
	}
	else {
		return 0;
	}
}


int isempty(PmyQ p) {
	if (p->front==p->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void show(PmyQ p) {
	printf("\n");
	if (isempty(p)==1){
		return;
	}
	else {
		for (int i = p->front; i < p->rear; i++) {
			printf("%4d", p->data[i]);
		}
	}
}


datatype getlast(PmyQ p) {
	if (isempty(p)==1) {
		return;
	}
	else {
		return p->data[p->front];
	}
}


void enQ(PmyQ p, datatype newdata) {					//入队
	if (isfull(p)==1) {
		return;
	}
	else {
		p->data[p->rear] = newdata;						//吃入
		p->rear++;
	}
}


void deQ(PmyQ p) {
	if (isempty(p) == 1) {
		return;
	}
	else {

		//队列的损耗，移动费事费力

		for (int i = 0; i < p->rear - p->front - 1; i++) {
			p->data[i] = p->data[i + 1];
		}
		//数据从后往前移动 
		p->rear -= 1;
	}
}


void main() {

	myQ myq;
	init(&myq);
	for (int i = 0; i < 10; i++) {
		enQ(&myq, i);
		show(&myq);
	}
	while (!isempty(&myq)) {
		printf("\n拉出来的%d", getlast(&myq));
		deQ(&myq);
		show(&myq);
	}

	system("pause");
}