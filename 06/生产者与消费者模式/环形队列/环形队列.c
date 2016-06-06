#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define datatype int
#define N 10


//���ζ��У�ɾ��һ��Ԫ���Ժ������ƶ�
//N,˳�����ʹ��N�����ζ���N-1��

typedef struct queue{
	datatype data[N];
	int front;
	int rear;
}myQ,*pQ;

void init(pQ p) {
	memset(p->data, 0, sizeof(datatype)*N);
	p->front = p->rear = 0;									//��ʼ��
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


void clear(pQ p) {											//��init����ȼ�
	memset(p->data, 0, sizeof(datatype)*N);
	p->front = p->rear = 0;									//��ʼ��
}


void printall(pQ p) {
	printf("\n");
	for (int i = p->front;i%N<p->rear;i++) {
		printf("%4d", p->data[i]);							//����ÿһ��Ԫ��
	}
}


void enQ(pQ p,int newdata) {
	if (isfull(p) == 1) {
		return;
	}
	else {
		p->data[p->rear] = newdata;
		p->rear = (p->rear + 1) % N;						//ѭ��

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
		printf("\n������%d", deQ(&my));
		printall(&my);
	}
	system("pause");
}