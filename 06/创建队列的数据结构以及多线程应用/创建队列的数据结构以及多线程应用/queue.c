#include "queue.h"


void init(myQ *p) {
	p->front = p->rear = 0;										//头尾重合，队列为空
	memset(p->data, 0, sizeof(mytype)*N);						//清空内存
}

int isfull(myQ *p) {
	if (p->rear == N) {
		return 1;
	}
	else {
		return 0;
	}
}

int isEmpty(myQ *p) {
	if (p->front == p->rear) {									//为空
		return 1;
	}
	else {
		return 0;
	}
}

void enQ(myQ *p, mytype insertdata) {
	if (isfull(p) == 1) {
		return;
	}
	else {
		p->data[p->rear] = insertdata;				     		//插入
		p->rear += 1;
	}
}

void deQ(myQ *p) {
	if (isEmpty(p) == 1) {
		printf("没有屎");
		return 0;
	}
	else {
		int index = p->rear - p->front;							//获取长度
		if (index == 1) {
			p->rear = 0;										//清空一个无需移动
		}
		else {
			for (int i = 0; i < index - 1; i++) {
				p->data[i] = p->data[i + 1];					//大肠的蠕动
			}
			p->rear -= 1;
		}
	}
}

mytype getlast(myQ *p) {
	if (isEmpty(p) == 1) {
		printf("没有屎");
		return 0;
	}
	else {
		return p->data[p->front];								//返回要拉的
	}
}

void print(myQ *p) {
	printf("\n");
	if (isEmpty(p) == 1) {
		printf("大肠为空\n");
		return 0;
	}
	else {
		for (int i = p->front; i < p->rear; i++) {
			printf("%p  ", p->data[i]);							//打印
		}
	}
}