#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 0;

//互斥量，只能让一个线程运行，其他线程休眠
//信号量，多个线程运行，其他线程休眠
//临界区,只能让一个线程运行休眠
//原子操作，操作速度最快
//事件也可以

DWORD WINAPI add(void *p) {
	HANDLE myhsem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "xiaobin");				//打开一个信号

	if (myhsem) {

		if (WaitForSingleObject(myhsem, INFINITE) == WAIT_OBJECT_0) {			     //等到了信号
			for (int i = 0; i < 10000; i++) {
				num++;
			}
			//ReleaseSemaphore(myhsem,1,NULL);
			CloseHandle(myhsem);
		}

	}
	else {
		printf("信号量获取失败!\n");
	}
}

void main() {

	//创建信号对象	0
	HANDLE hSEM = CreateSemaphore(NULL, 0, 1, "xiaobin");								//开辟一个信号，最大计数是5
	HANDLE hd[64] = { 0 };
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, add, NULL, 0, NULL);
	}

	Sleep(2000);
	printf("激活线程");
	ReleaseSemaphore(hSEM, 1, NULL);												//最多一次放过MAX个线程

	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	printf("%d", num);

	CloseHandle(hSEM);

	system("pause");
}