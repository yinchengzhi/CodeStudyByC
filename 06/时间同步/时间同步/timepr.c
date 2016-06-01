#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//回调函数，函数指针可以调用

VOID CALLBACK timerun(void *parg,DWORD timearg,DWORD timehigh) {
	
	DWORD dwindex = *(DWORD*)parg;
	printf("\n第%d次", dwindex);
	//MessageBoxA(0, "1", "2", 0);
}


void main() {

	HANDLE time1 = CreateWaitableTimerA(NULL, TRUE, "haihua");
	if (time1 == NULL) {
		printf("创建失败");
	}

	LARGE_INTEGER mytime;
	mytime.QuadPart = -50000000;												//0.1微妙，万分之一毫秒

	DWORD dwparam = 1;															//设置定时器

	if (SetWaitableTimer(time1, &mytime, 1000, timerun, &dwparam, FALSE)) {		//1000毫秒 循环一次
		printf("等待5秒之后开始干活");
		for (int i = 0; i < 15; i++,dwparam++) {								//循环多少次
			SleepEx(INFINITE, TRUE);
		}
	}

	if (WaitForSingleObject(time1, INFINITE) == WAIT_OBJECT_0) {
		printf("wait ok!");
	}
	else {
		printf("wait no!");
	}

	CancelWaitableTimer(time1);												  //取消定时器
	CloseHandle(time1);

	system("pause");
}