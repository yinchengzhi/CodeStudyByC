#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define N 64													//临界区最大线程是64
int num = 0;

CRITICAL_SECTION cs1;
CRITICAL_SECTION cs2;												//定义临界区,结构体变量

DWORD WINAPI add(void *p) {
	EnterCriticalSection(&cs1);
	for (int i = 0; i < 100000; i++) {
		num++;
	}
	LeaveCriticalSection(&cs1);
	return 0;
}

DWORD WINAPI sub(void *p) {
	EnterCriticalSection(&cs2);
	for (int i = 0; i < 100000; i++) {
		num--;
	}
	LeaveCriticalSection(&cs2);
	return 0;
}

void main() {
	InitializeCriticalSection(&cs1);								//必须得初始化
	InitializeCriticalSection(&cs2);								//必须得初始化
	{
		HANDLE hd[N];
		for (int i = 0; i < N; i++) {
			hd[i] = CreateThread(NULL, 0, add, NULL, 0, NULL);		//创建线程
																	//WaitForSingleObject(hd[i], INFINITE);
		}

		WaitForMultipleObjects(N, hd, TRUE, INFINITE);				//等待全部退出 
		printf("num = %d", num);
	}

	{
		HANDLE hd[N];
		for (int i = 0; i < N; i++) {
			hd[i] = CreateThread(NULL, 0, sub, NULL, 0, NULL);		//创建线程
																	//WaitForSingleObject(hd[i], INFINITE);
		}

		WaitForMultipleObjects(N, hd, TRUE, INFINITE);				//等待全部退出 
		printf("num = %d", num);
	}

	DeleteCriticalSection(&cs1);									//释放
	DeleteCriticalSection(&cs2);									//释放
	system("pause");
}