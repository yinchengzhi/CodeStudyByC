#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100
#define datatype int

typedef struct queue {
	datatype data[N];
	int rear;									//吃东西
	int front;									//拉屎
}myQ, *PmyQ;


void init(PmyQ p);
int isfull(PmyQ p);
int isempty(PmyQ p);
void show(PmyQ p);
void enQ(PmyQ p, datatype newdata);
void deQ(PmyQ p);

datatype getlast(PmyQ p);

void init(PmyQ p) {
	memset(p->data, '\0', sizeof(datatype)*N);
	p->front = p->rear = 0;
}

int isempty(PmyQ p) {
	if (p->front == p->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int isfull(PmyQ p) {
	if ((p->rear + 1) % N == p->front) {
		return 1;
	}
	else {
		return 0;
	}
}

void enQ(PmyQ p, datatype newdata) {
	if (isfull(p) == 1) {
		return;
	}
	else {
		p->data[p->rear] = newdata;							//插入一个
		p->rear = (p->rear + 1) % N;
	}
}


void main() {


	system("pause");
}