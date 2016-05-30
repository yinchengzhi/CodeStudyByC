
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

////互斥解决线程冲突
////事件解决线程通信
////临界区解决线程冲突
////时间同步线程

HANDLE event[5] = { 0 };
HANDLE thread[10] = { 0 };

char ch[10] = { 'A','B','C','D','E','F','G','H','I','J' };
char str[256] = { 0 };

DWORD WINAPI haihuagirlfiend(void *p) {
	char *pch = p;
	printf("\n i am %c haihua girlfriend", *pch);

	if (*pch == 'C') {
		MessageBoxA(0, "1", "1", 0);
		sprintf(str, "海华女友 %c speak xiaohuahua lovely", *pch);
		SetEvent(event[0]);
	}

	int i = 0;
	while (++i) {
		WaitForSingleObject(event[0], INFINITE);
		printf("\nhaihuagirlfriend %c read %s", *pch, str);
		Sleep(1000);
		ResetEvent(event[0]);
	}

	return 1;
}

void main() {

	//第二个参数代表，自动，收到一次自动清空事件，TRUE手动需要Reset  
	//第二个参数FALSE代表自动，TRUE手动需要Reset
	//第三个参数代表信号的状态
	//第四个参数标记名称
	event[0] = CreateEventA(NULL, TRUE, FALSE, "msg");							//一直等待消息

	for (int i = 0; i < 10; i++) {
		thread[i] = CreateThread(NULL, 0, haihuagirlfiend, &ch[i], 0, NULL);
	}

	WaitForMultipleObjects(10, thread, TRUE, INFINITE);

	system("pause");
}