#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>
#include<time.h>

CRITICAL_SECTION cs;									//临界区,定义为全局变量

//int num = 0;											//多线程发生冲突,

//100个需要1000s		10*100*100

void myfun(void *p) {
	for (int i = 0; i < 100; i++) {
		EnterCriticalSection(&cs);						//进入临界区
		num++;
		LeaveCriticalSection(&cs);						//李凯临界区
		//Sleep(10);
	}
}

void main1() {

	time_t start, end;
	time(&start);

	int hd[100];										//线程数组
	for (int i = 0; i < 100; i++) {
		hd[i] = _beginthread(myfun, 0, NULL);			//数组的每一个元素都是线程
		WaitForSingleObject(hd[i], INFINITE);			//同步
	}

	WaitForMultipleObjects(100, hd, TRUE,INFINITE);		//等待所有的线程退出

	time(&end);
	printf("\n%f", difftime(end,start));

	printf("\n%d", num);
	DeleteCriticalSection(&cs);
	system("pause");
}