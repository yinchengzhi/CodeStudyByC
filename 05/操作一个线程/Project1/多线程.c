#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

//_beginthread	CreateThread  创建线程
//_endthread	ExitThread,内部结束,teminate外部	
//SuspendThread(hd);		//冻结
//ResumeThread(hd);			//解冻

DWORD WINAPI fun(void *p) {
	int i = 0;
	while (++i) {
		printf("\n%d", i);
		if (i > 8000) {
			//_endthread();									//用于线程内部退出
			//ExitThread(0);									//结束线程
		}
	}
	return 0;
}

//主线程，主导作用，管理调用其他线程

void main() {
	HANDLE hd = CreateThread(NULL, 0, fun, NULL, 0, NULL);

	system("pause");
	SuspendThread(hd);										//冻结
	system("pause");
	ResumeThread(hd);										//解冻
	system("pause");

	//外部强行结束线程
	TerminateThread(hd,0);
	system("pause");
}