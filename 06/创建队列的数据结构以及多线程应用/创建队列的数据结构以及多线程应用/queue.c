#include "queue.h"


void init(myQ *p) {
	p->front = p->rear = 0;										//ͷβ�غϣ�����Ϊ��
	memset(p->data, 0, sizeof(mytype)*N);						//����ڴ�
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
	if (p->front == p->rear) {									//Ϊ��
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
		p->data[p->rear] = insertdata;				     		//����
		p->rear += 1;
	}
}

void deQ(myQ *p) {
	if (isEmpty(p) == 1) {
		printf("û��ʺ");
		return 0;
	}
	else {
		int index = p->rear - p->front;							//��ȡ����
		if (index == 1) {
			p->rear = 0;										//���һ�������ƶ�
		}
		else {
			for (int i = 0; i < index - 1; i++) {
				p->data[i] = p->data[i + 1];					//�󳦵��䶯
			}
			p->rear -= 1;
		}
	}
}

mytype getlast(myQ *p) {
	if (isEmpty(p) == 1) {
		printf("û��ʺ");
		return 0;
	}
	else {
		return p->data[p->front];								//����Ҫ����
	}
}

void print(myQ *p) {
	printf("\n");
	if (isEmpty(p) == 1) {
		printf("��Ϊ��\n");
		return 0;
	}
	else {
		for (int i = p->front; i < p->rear; i++) {
			printf("%p  ", p->data[i]);							//��ӡ
		}
	}
}