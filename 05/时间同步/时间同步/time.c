#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//单独定时器，只能用于同步通信

void main1() {
	while (1) {
		printf("fang fang!\n");
		Sleep(2000);
	}
	system("pause");
}

void main2() {

	HANDLE timer = CreateWaitableTimer(NULL, TRUE,NULL);			//创建一个定时器
	if (timer == NULL) {
		return;
	}
	else {
		LARGE_INTEGER time;
		time.QuadPart = -50000000;									//2秒
		//10^-7秒				0.1微秒
		SetWaitableTimer(timer, &time, 0, NULL,0,NULL);				//设置定时器等待2秒
		if (WaitForSingleObject(timer, INFINITE) == WAIT_OBJECT_0) {
			printf("等待成功！");
		}
		else {
			printf("等待失败！");
		}
	}
	system("pause");
}

HANDLE timer;

DWORD WINAPI go1(void *p) {
	MessageBoxA(0, "1", "1", 0);
	timer = CreateWaitableTimer(NULL, TRUE, NULL);					//创建一个定时器
	LARGE_INTEGER time;
	time.QuadPart = -50000000;										//2秒
																	//10^-7秒				0.1微秒
	SetWaitableTimer(timer, &time, 0, NULL, 0, NULL);				//设置定时器等待2秒
}

DWORD WINAPI go2(void *p) {
	MessageBoxA(0, "2", "2", 0);
	printf("等待成功！");
}

void main() {
	HANDLE hd = CreateThread(NULL, 0, go1, NULL, 0,NULL);
	WaitForSingleObject(hd, INFINITE);
	if (WaitForSingleObject(timer, INFINITE) == WAIT_OBJECT_0) {
		CreateThread(NULL, 0, go2, NULL, 0, NULL);
		printf("等待成功！");
	}
	else {
		printf("等待失败！");
	}

	system("pause");
}