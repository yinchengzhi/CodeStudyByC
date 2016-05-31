#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 6400000;
SRWLOCK g_lock;

//改变一个变量的时候，需要锁定

DWORD WINAPI go(void *p) {
	AcquireSRWLockExclusive(&g_lock);								//锁定写入
	for (int i = 0; i < 100000; i++) {
		num--;
	}
	ReleaseSRWLockExclusive(&g_lock);								//
}

void main1() {

	InitializeSRWLock(&g_lock);										//初始化
	HANDLE hd[64];
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, go, NULL,0,NULL);
	}
	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	printf("%d", num);
	system("pause");
}