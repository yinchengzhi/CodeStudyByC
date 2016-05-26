#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<Windows.h>
void main1() {

	//release  优化
	//volatile 强制读内存
	for (volatile int i = 0; i < INT_MAX; i++) {

	}

	printf("over");
	system("pause");
}

volatile int num = 20;							//现代编译器都会优化,加不加都是一样

DWORD WINAPI msg(void *p) {						//读
	int *px = (int*)p;
	while (1) {
		//int data = *px;						//强制读内存
		printf("\n%d",num);
		Sleep(1000);
	}
}

DWORD WINAPI cmsg(void *p) {					//写入
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