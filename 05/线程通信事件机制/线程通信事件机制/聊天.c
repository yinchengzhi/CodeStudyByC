#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

HANDLE event[4] = { 0 };							//�¼�
HANDLE hthread[3] = { 0 };							//�����߳�
char str[1024] = { 0 };								//�����������ݵĻ�����

CRITICAL_SECTION cs;								//�����ٽ���

// 0 ��������ý�ţ� 0
// 1 ý�ŷ��������� 1
// 2 ����֪ͨý�ţ� 2
// 3 ý�ŷ��������� 3

DWORD WINAPI zhouruifu(void *p) {
	int i = 0;
	while (i++) {
		WaitForSingleObject(event[0], INFINITE);
		
		EnterCriticalSection(&cs);
		printf("\ný�Ŵ��ݣ�%s", str);
		LeaveCriticalSection(&cs);
		
		Sleep(1000);
		SetEvent(event[1]);

		WaitForSingleObject(event[2], INFINITE);

		EnterCriticalSection(&cs);
		printf("\ný�Ŵ��ݣ�%s", str);
		LeaveCriticalSection(&cs);

		Sleep(1000);
		SetEvent(event[3]);
	}
	return 0;
}

DWORD WINAPI haihua(void *p) {
	int i = 1;
	
	EnterCriticalSection(&cs);
	memset(str, '\0', 1024);
	sprintf(str,"\n������%d˵��i love your fang fang!", i);
	LeaveCriticalSection(&cs);

	Sleep(1000);
	SetEvent(event[0]);

	while (++i) {
		WaitForSingleObject(event[3], INFINITE);

		EnterCriticalSection(&cs);
		memset(str, '\0', 1024);
		sprintf(str, "\n������%d˵��i love your fang fang!", i);
		LeaveCriticalSection(&cs);

		Sleep(1000);
		SetEvent(event[0]);
	}
	return 0;
}


DWORD WINAPI fangfang(void *p) {
	int i = 0;
	while (++i) {
		WaitForSingleObject(event[1], INFINITE);

		EnterCriticalSection(&cs);
		memset(str, '\0', 1024);
		sprintf(str,"\n�����%d��˵��i love your too!", i);
		LeaveCriticalSection(&cs);

		Sleep(1000);
		SetEvent(event[2]);
	}
	return 0;
}

void main() {
	InitializeCriticalSection(&cs);
	event[0] = CreateEvent(NULL, TRUE, FALSE, NULL);
	event[1] = CreateEvent(NULL, TRUE, FALSE, NULL);
	event[2] = CreateEvent(NULL, TRUE, FALSE, NULL);
	event[3] = CreateEvent(NULL, TRUE, FALSE, NULL);

	hthread[0] = CreateThread(NULL, 0, haihua, NULL, 0, NULL);
	hthread[1] = CreateThread(NULL, 0, fangfang, NULL, 0, NULL);
	hthread[2] = CreateThread(NULL, 0, zhouruifu, NULL, 0, NULL);

	WaitForMultipleObjects(2, hthread, TRUE, INFINITE);
	printf("over!");

	DeleteCriticalSection(&cs);
	system("pause");
}