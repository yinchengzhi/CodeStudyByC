#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//�������̳߳�ͻ
//�¼�����߳�ͨ��
//�ٽ�������̳߳�ͻ
//ʱ��ͬ���߳�

HANDLE event[5] = { 0 };
HANDLE thread[5] = { 0 };

char str[256] = { 0 };														//ȫ�ֱ���

DWORD WINAPI fupo(void *p) {
	int i = 0;
	int k = 0;
	while (++i) {
		if (k == 0) {
			k = 1;
			WaitForSingleObject(event[1], INFINITE);						//���ߵȴ�һ���ź�
			printf("ý�Ŷ�ȡ%d��,%s\n", i, str);
			Sleep(1000);
			SetEvent(event[2]);
		}
		else {
			k = 0;
			WaitForSingleObject(event[3], INFINITE);						//���ߵȴ�һ���ź�
			printf("ý�Ŷ�ȡ%d��,%s\n", i, str);
			Sleep(1000);
			SetEvent(event[0]);
		}
	}
}

DWORD WINAPI haihua(void *p) {
	int i = 1;
	memset(str, '0', 256);
	sprintf(str, "����%d��˵: i love you fangfang ,please help me debug !", i);

	Sleep(1000);
	SetEvent(event[1]);
	while (++i) {
		WaitForSingleObject(event[0], INFINITE);						//���ߵȴ�һ���ź�
		memset(str, '0', 256);
		sprintf(str, "����%d��˵: i love you fangfang ,please help me debug !", i);

		Sleep(1000);
		//ResetEvent(event[0]);										//�źŸ�λ
		SetEvent(event[1]);
	}
	return 0;
}

DWORD WINAPI wangfang(void *p) {
	int i = 0;
	while (++i) {
		WaitForSingleObject(event[2], INFINITE);					//���ߵȴ�һ���ź�
		memset(str, '0', 256);
		sprintf(str, "wangfang��%d��˵: sorry , but i love you !\n", i);
		Sleep(1000);
		//ResetEvent(event[1]);										//�źŸ�λ
		SetEvent(event[3]);
	}
	return 0;
}

void main() {

	//�ڶ�������FALSE�����Զ���TRUE�ֶ���ҪReset
	//���������������źŵ�״̬
	//���ĸ������������
	event[0] = CreateEventA(NULL, FALSE, FALSE, NULL);
	event[1] = CreateEventA(NULL, FALSE, FALSE, NULL);
	event[2] = CreateEventA(NULL, FALSE, FALSE, NULL);
	event[3] = CreateEventA(NULL, FALSE, FALSE, NULL);

	thread[0] = CreateThread(NULL, 0, haihua, NULL, 0, NULL);
	thread[1] = CreateThread(NULL, 0, wangfang, NULL, 0, NULL);
	thread[2] = CreateThread(NULL, 0, fupo, NULL, 0, NULL);

	WaitForMultipleObjects(3, thread, TRUE, INFINITE);

	system("pause");
}