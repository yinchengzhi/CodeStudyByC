#include<stdio.h>
#include<stdlib.h>

#define N 100										//�����������ж��ٸ���
#define datatype char								//������������

//�ṹ�����
struct queue{
	datatype data[N];								//������ݵ�����
	int front;										//����ɾ����һ�˳�Ϊ��ͷ
	int rear;										//��������һ�˳�Ϊ��β 
};

//���еĽӿ�
typedef struct queue QUEUE;									//��struct queue
void initQUE(QUEUE *sq);									//��ʼ��˳�����
int isempty(QUEUE *sq);										//�ж϶����Ƿ�Ϊ��
datatype gethead(QUEUE *sq);								//��ȡ���е�һ��Ԫ��
void enQUEUE(QUEUE *sq, datatype data);						//�������
datatype deQUEUE(QUEUE *sq);					//���г��ӣ�����ֵΪ���ӵ�����
void showQUEUE(QUEUE *sq);									//	



void initQUE(QUEUE *sq) {			
	sq->front = sq->rear = 0;								//ʵ�ֶ��еĳ�ʼ��,�ȼ������

}

int isempty(QUEUE *sq) {									//����Ϊ�շ���1�����򷵻�0
	if (sq->front == sq->rear) {							//��ζ�Ŷ�ͷ�Ͷ�β�غ�Ϊ��
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
		return sq->data[sq->front];							//���ص�һ���ڵ������
	}
}


void enQUEUE(QUEUE *sq, datatype data) {
	if (sq->rear == N) {									//n-1 . N���������ж��ٸ�Ԫ��,��ζ���Ѿ�����
		printf("�����Ѿ�����!");
		return;
	}

	sq->data[sq->rear] = data;								//���
	sq->rear++;												//�±��ƶ�һ��
}	

datatype deQUEUE(QUEUE *sq) {
	if (sq->front == sq->rear) {							//��ζ�Ŷ�ͷ�Ͷ�β�غ�Ϊ��
		return -1;
	}
	sq->front++;											//ɾ��һ��Ԫ��,��ǰ�ƶ�һ��
	return sq->data[sq->front - 1];							//����ǰһ��Ԫ�أ���ɾ����Ԫ��
}

void showQUEUE(QUEUE *sq) {
	if (sq->front == sq->rear) {							//��ζ�Ŷ�ͷ�Ͷ�β�غ�Ϊ��
		return;
	}
	else {
		printf("\nfront = %d,rear = %d\n",sq->front,sq->rear);
		for (int i = sq->front; i < sq->rear; i++) {		//��ӡ���ж���Ԫ��
			printf("%c ", sq->data[i]);
		}
	}
}

void main() {
	QUEUE q1;												//�������еĽṹ�� 
	initQUE(&q1);											//��ʼ������
	char *str = "abcdefg";
	char *p = str;											//�洢��ַ

	while (*p != '\0') {
		enQUEUE(&q1, *p);									//�ַ��������
		showQUEUE(&q1);										//��ʾ��������Ԫ��
		p++;
	}

	while (isempty(&q1) != 1) {								//ֻҪ���в��գ���һֱѭ����ȥ
		printf("\n���ӵ��ַ�%c", deQUEUE(&q1));				//��ӡ���ӵ��ַ�
		showQUEUE(&q1);										//��ʾ��������Ԫ��
	}

	system("pause");
}