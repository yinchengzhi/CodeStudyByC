#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>

HANDLE event[3] = { 0 };							//事件
HANDLE hthread[3] = { 0 };							//代表线程

DWORD WINAPI firstthread(void *p) {
	MessageBoxA(0,"1", "1", 0);
	printf("第1个线程执行完成");
	SetEvent(event[0]);
	return 0;
}

DWORD WINAPI secondthread(void *p) {
	WaitForSingleObject(event[0], INFINITE);		//等待event信号出现，执行下一步
	MessageBoxA(0, "2", "2", 0);
	printf("第2个线程执行完成");
	return 0;
}

void main1x() {
	//The lpSecurityDescriptor member of the structure specifies a security descriptor for the new event.
	//If lpEventAttributes is NULL, the event gets a default security descriptor
	event[0] = CreateEvent(NULL, TRUE, FALSE, NULL);
	event[1] = CreateEvent(NULL, TRUE, FALSE, NULL);

	hthread[0] = CreateThread(NULL, 0, firstthread, NULL, 0, NULL);
	hthread[1] = CreateThread(NULL, 0, secondthread, NULL, 0, NULL);

	WaitForMultipleObjects(2, hthread, TRUE, INFINITE);
	printf("全部完成!");

	system("pause");
}