#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<Windows.h>
void main1() {

	//release  �Ż�
	//volatile ǿ�ƶ��ڴ�
	for (volatile int i = 0; i < INT_MAX; i++) {

	}

	printf("over");
	system("pause");
}

volatile int num = 20;							//�ִ������������Ż�,�Ӳ��Ӷ���һ��

DWORD WINAPI msg(void *p) {						//��
	int *px = (int*)p;
	while (1) {
		//int data = *px;						//ǿ�ƶ��ڴ�
		printf("\n%d",num);
		Sleep(1000);
	}
}

DWORD WINAPI cmsg(void *p) {					//д��
	int *px = (int*)p;
	while (1) {
		*px += 1;
		Sleep(10000);
	}
}

void main() {

	CreateThread(NULL, 0, msg, &num, 0, NULL);
	CreateThread(NULL, 0, msg, &num, 0, NULL);
	CreateThread(NULL, 0, msg, &num, 0, NULL);
	CreateThread(NULL, 0, cmsg, &num, 0, NULL);
	system("pause");
}