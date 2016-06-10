#include<stdio.h>
#include<stdlib.h>

#define N 100										//定义队列最大有多少个人
#define datatype char								//定义数据类型

//结构体队列
struct queue{
	datatype data[N];								//存放数据的数组
	int front;										//允许删除的一端称为队头
	int rear;										//允许插入的一端称为队尾 
};

//队列的接口
typedef struct queue QUEUE;									//简化struct queue
void initQUE(QUEUE *sq);									//初始化顺序队列
int isempty(QUEUE *sq);										//判断队列是否为空
datatype gethead(QUEUE *sq);								//获取队列第一个元素
void enQUEUE(QUEUE *sq, datatype data);						//队列入队
datatype deQUEUE(QUEUE *sq);					//队列出队，返回值为出队的数据
void showQUEUE(QUEUE *sq);									//	



void initQUE(QUEUE *sq) {			
	sq->front = sq->rear = 0;								//实现队列的初始化,等价于清空

}

int isempty(QUEUE *sq) {									//队列为空返回1，否则返回0
	if (sq->front == sq->rear) {							//意味着队头和队尾重合为空
		return 1;
	}
	else {
		return 0;
	}
}

datatype gethead(QUEUE *sq) {
	if (sq->front == sq->rear) {
		return -1;
	}
	else {
		return sq->data[sq->front];							//返回第一个节点的数据
	}
}


void enQUEUE(QUEUE *sq, datatype data) {
	if (sq->rear == N) {									//n-1 . N就是数组有多少个元素,意味着已经满了
		printf("队列已经满了!");
		return;
	}

	sq->data[sq->rear] = data;								//入队
	sq->rear++;												//下标移动一个
}	

datatype deQUEUE(QUEUE *sq) {
	if (sq->front == sq->rear) {							//意味着队头和队尾重合为空
		return -1;
	}
	sq->front++;											//删除一个元素,向前移动一个
	return sq->data[sq->front - 1];							//返回前一个元素，即删除的元素
}

void showQUEUE(QUEUE *sq) {
	if (sq->front == sq->rear) {							//意味着队头和队尾重合为空
		return;
	}
	else {
		printf("\nfront = %d,rear = %d\n",sq->front,sq->rear);
		for (int i = sq->front; i < sq->rear; i++) {		//打印所有队列元素
			printf("%c ", sq->data[i]);
		}
	}
}

void main() {
	QUEUE q1;												//创建队列的结构体 
	initQUE(&q1);											//初始化队列
	char *str = "abcdefg";
	char *p = str;											//存储地址

	while (*p != '\0') {
		enQUEUE(&q1, *p);									//字符挨个入队
		showQUEUE(&q1);										//显示队列所有元素
		p++;
	}

	while (isempty(&q1) != 1) {								//只要队列不空，就一直循环下去
		printf("\n出队的字符%c", deQUEUE(&q1));				//打印出队的字符
		showQUEUE(&q1);										//显示队列所有元素
	}

	system("pause");
}