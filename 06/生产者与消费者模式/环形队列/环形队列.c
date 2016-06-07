#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<Windows.h>

#define datatype int
#define N 10


//环形队列，删除一个元素以后无需移动
//N,顺序队列使用N，环形队列N-1个

typedef struct queue {
	datatype data[N];
	int front;
	int rear;
}myQ, *pQ;

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
	for (int i = p->front; i%N < p->rear; i++) {
		printf("%4d", p->data[i]);							//遍历每一个元素
	}
}


void enQ(pQ p, int newdata) {
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
		return -1;
	}
	else {
		datatype tempdata = p->data[p->front];
		p->front = (p->front + 1) % N;
		return tempdata;
	}
}



myQ my;																//全局变量

struct node *phead = NULL;

DWORD WINAPI builder(void *p) {

	int j = 0;
	while (isfull(&my) == 0) {										//1

		int data = j++;
		enQ(&my, data);												//i++	+j ,i++优先级比较高
		printf("\n生产者生产了 %4d", data);
	}

	HANDLE event2 = OpenEvent(EVENT_ALL_ACCESS, TRUE, "isno");
	SetEvent(event2);

	int i = 0;
	while (++i) {
		HANDLE event1 = OpenEvent(EVENT_ALL_ACCESS, TRUE, "isok");
		WaitForSingleObject(event1, INFINITE);

		int j = 0;
		while (isfull(&my) == 0) {									//1

			int data = i++ + j++;
			enQ(&my, data);											//i++	+j ,i++优先级比较高
			printf("\n生产者生产了 %4d", data);
		}

		Sleep(2000);

		HANDLE event2 = OpenEvent(EVENT_ALL_ACCESS, TRUE, "isno");
		SetEvent(event2);
	}
	return 1;
}

DWORD WINAPI player(void *p) {
	int i = 0;
	while (++i) {

		HANDLE event1 = OpenEvent(EVENT_ALL_ACCESS, TRUE, "isno");
		WaitForSingleObject(event1, INFINITE);
		int num = 5;
		//	scanf("%d", &num);											//scanf不是一个线程安全的函数
		printf("\n你要消费%d个", num);
		for (int i = 0; i < num; i++) {
			if (isempty(&my) != 1) {
				printf("\n消费者消费的是%d", deQ(&my));
			}
		}

		Sleep(2000);
		HANDLE event2 = OpenEvent(EVENT_ALL_ACCESS, TRUE, "isok");
		SetEvent(event2);
	}
	return 1;
}


void main() {

	HANDLE event1 = CreateEvent(NULL, FALSE, FALSE, "isok");
	HANDLE event2 = CreateEvent(NULL, FALSE, FALSE, "isno");

	CreateThread(NULL, 0, builder, NULL, 0, NULL);
	CreateThread(NULL, 0, player, NULL, 0, NULL);

	WaitForSingleObject(builder, INFINITE);

	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	//myQ my;
	//init(&my);

	//for (int i = 0; i < 9; i++) {
	//	enQ(&my, i);
	//	printall(&my);
	//}

	//while (!isempty(&my)) {
	//	printf("\n弹出的%d", deQ(&my));
	//	printall(&my);
	//}
	system("pause");

	CloseHandle(event1);
}