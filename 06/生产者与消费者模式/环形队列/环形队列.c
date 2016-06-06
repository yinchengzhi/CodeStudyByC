#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define datatype int
#define N 10


//环形队列，删除一个元素以后无需移动
//N,顺序队列使用N，环形队列N-1个

typedef struct queue{
	datatype data[N];
	int front;
	int rear;
}myQ,*pQ;

void init(pQ p) {
	memset(p->data, 0, sizeof(datatype)*N);
	p->front = p->rear = 0;									//初始化
}

int isempty(pQ p) {
	if (p->front == p->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

//0 1 2 3 4 5 6 7 8 9 

int isfull(pQ p) {
	if ((p->rear + 1) % N == p->front) {
		return 1;
	}
	else {
		return 0;
	}
}


void clear(pQ p) {											//和init代码等价
	memset(p->data, 0, sizeof(datatype)*N);
	p->front = p->rear = 0;									//初始化
}


void printall(pQ p) {
	printf("\n");
	for (int i = p->front;i%N<p->rear;i++) {
		printf("%4d", p->data[i]);							//遍历每一个元素
	}
}


void enQ(pQ p,int newdata) {
	if (isfull(p) == 1) {
		return;
	}
	else {
		p->data[p->rear] = newdata;
		p->rear = (p->rear + 1) % N;						//循环

	}
}

datatype deQ(pQ p) {
	if (isempty(p) == 1) {
		abort();
		return;
	}
	else {
		datatype tempdata = p->data[p->front];
		p->front = (p->front + 1) % N;
		return tempdata;
	}
}

void main() {
	myQ my;
	init(&my);

	for (int i = 0; i < 9; i++) {
		enQ(&my, i);
		printall(&my);
	}

	while (!isempty(&my)) {
		printf("\n弹出的%d", deQ(&my));
		printall(&my);
	}
	system("pause");
}