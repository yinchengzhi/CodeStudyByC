#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 6400000;
SRWLOCK g_lock;

//注意

DWORD WINAPI read(void *p) {

	AcquireSRWLockShared(&g_lock);									//读取期间，锁定数据，数据无法被修改
	int i = 0;
	while (1) {
		Sleep(1000);
		printf("\n第%d秒num=%d",i,num);
		if (i == 20) {
			break;
		}
		i++;
	}
	ReleaseSRWLockShared(&g_lock);
}


//改变一个变量的时候，需要锁定

DWORD WINAPI go(void *p) {

	AcquireSRWLockExclusive(&g_lock);								//锁定写入

	printf("\n开始写入");

	for (int i = 0; i < 100000; i++) {
		num--;
		//Sleep(10);
	}
	ReleaseSRWLockExclusive(&g_lock);								//Releases a slim reader/writer (SRW) lock that was acquired in exclusive mode.
	printf("\n结束写入");

}

void main() {

	InitializeSRWLock(&g_lock);										//初始化

	CreateThread(NULL, 0, read, NULL, 0, NULL);

	HANDLE hd[64];
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, go, NULL, 0, NULL);
	}


	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	
	printf("\nlast = %d", num);

	system("pause");
}