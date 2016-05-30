#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//互斥解决线程冲突
//事件解决线程通信
//临界区解决线程冲突
//时间同步线程

HANDLE event[5] = { 0 };
HANDLE thread[5] = { 0 };

char str[256] = { 0 };														//全局变量

DWORD WINAPI fupo(void *p) {
	int i = 0;
	int k = 0;
	while (++i) {
		if (k == 0) {
			k = 1;
			WaitForSingleObject(event[1], INFINITE);						//无线等待一个信号
			printf("媒婆读取%d次,%s\n", i, str);
			Sleep(1000);
			SetEvent(event[2]);
		}
		else {
			k = 0;
			WaitForSingleObject(event[3], INFINITE);						//无线等待一个信号
			printf("媒婆读取%d次,%s\n", i, str);
			Sleep(1000);
			SetEvent(event[0]);
		}
	}
}

DWORD WINAPI haihua(void *p) {
	int i = 1;
	memset(str, '0', 256);
	sprintf(str, "海华%d次说: i love you fangfang ,please help me debug !", i);

	Sleep(1000);
	SetEvent(event[1]);
	while (++i) {
		WaitForSingleObject(event[0], INFINITE);						//无线等待一个信号
		memset(str, '0', 256);
		sprintf(str, "海华%d次说: i love you fangfang ,please help me debug !", i);

		Sleep(1000);
		//ResetEvent(event[0]);										//信号复位
		SetEvent(event[1]);
	}
	return 0;
}

DWORD WINAPI wangfang(void *p) {
	int i = 0;
	while (++i) {
		WaitForSingleObject(event[2], INFINITE);					//无线等待一个信号
		memset(str, '0', 256);
		sprintf(str, "wangfang第%d次说: sorry , but i love you !\n", i);
		Sleep(1000);
		//ResetEvent(event[1]);										//信号复位
		SetEvent(event[3]);
	}
	return 0;
}

void main() {

	//第二个参数FALSE代表自动，TRUE手动需要Reset
	//第三个参数代表信号的状态
	//第四个参数标记名称
	event[0] = CreateEventA(NULL, FALSE, FALSE, NULL);
	event[1] = CreateEventA(NULL, FALSE, FALSE, NULL);
	event[2] = CreateEventA(NULL, FALSE, FALSE, NULL);
	event[3] = CreateEventA(NULL, FALSE, FALSE, NULL);

	thread[0] = CreateThread(NULL, 0, haihua, NULL, 0, NULL);
	thread[1] = CreateThread(NULL, 0, wangfang, NULL, 0, NULL);
	thread[2] = CreateThread(NULL, 0, fupo, NULL, 0, NULL);

	WaitForMultipleObjects(3, thread, TRUE, INFINITE);

	system("pause");
}