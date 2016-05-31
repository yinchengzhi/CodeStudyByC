//关卡的作用

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define id "haihua"
#define MAX 5

//0		无限等待

DWORD WINAPI myworker(void *p) {
	int *pint = p;
	printf("\nmyworker %d is running",*pint);

	HANDLE myhsem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE,id);					 //打开一个信号

	if (myhsem) {																	 //myhsem!=NULL
		printf("\nmyworker %d is waitting", *pint);

		//初始化信号为0,为0的情况就会死锁,0，信号量不减去
		//WaitForSingle不为0的情况下，信号量-1

		if (WaitForSingleObject(myhsem, INFINITE) == WAIT_OBJECT_0) {			     //等到了信号
			printf("\nmyworker %d is getting", *pint);
			Sleep(3000);

			printf("\nmyworker %d is leaving", *pint);

			ReleaseSemaphore(myhsem, 1, NULL);									     //释放资源 + 1
			CloseHandle(myhsem);
		}
	}

	return 1;
}

void main1() {

	//创建信号对象	0
	HANDLE hSEM = CreateSemaphore(NULL, 0, MAX, id);								//开辟一个信号，最大计数是5
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	HANDLE hd[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		hd[i] = CreateThread(NULL, 0, myworker, a + i, 0, NULL);
	}

	Sleep(5000); 

	printf("激活线程");

	ReleaseSemaphore(hSEM,MAX,NULL);												//最多一次放过MAX个线程

	WaitForMultipleObjects(10, hd, TRUE, INFINITE);

	CloseHandle(hSEM);

	system("pause");
}