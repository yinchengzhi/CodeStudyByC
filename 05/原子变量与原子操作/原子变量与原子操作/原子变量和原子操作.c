#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 0;											//多个线程同时访问一个变量,同时写入,会冲突
//一个变量是线程安全，多线程同时读写没有误差
//临界区,event,互斥
//原子操作的速度，临界区，event，互斥

//原子操作函数，解决多线程安全

DWORD WINAPI runX(void *p) {
	for (int i = 0; i < 10000; i++) {
		//num++;												//++ 复合语句
		//InterlockedIncrement(&num);						//num++,但是保证完整操作，我操作完成了，后续才能继续
		//InterlockedExchange()
		//InterlockedAnd(&num, 1)							1 + num
		InterlockedExchangeAdd(&num,1);						//num = num + 1
	}
}

void main() {
	HANDLE hd[50];
	for (int i = 0; i < 50; i++) {
		hd[i] = CreateThread(NULL, 0, runX, NULL,0, NULL);
	}

	WaitForMultipleObjects(50, hd, TRUE, INFINITE);
	printf("%d", num);

	system("pause");
}