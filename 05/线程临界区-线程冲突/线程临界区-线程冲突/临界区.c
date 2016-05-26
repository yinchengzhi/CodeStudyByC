#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define N 64													//�ٽ�������߳���64
int num = 0;

CRITICAL_SECTION cs1;
CRITICAL_SECTION cs2;												//�����ٽ���,�ṹ�����

DWORD WINAPI add(void *p) {
	EnterCriticalSection(&cs1);
	for (int i = 0; i < 100000; i++) {
		num++;
	}
	LeaveCriticalSection(&cs1);
	return 0;
}

DWORD WINAPI sub(void *p) {
	EnterCriticalSection(&cs2);
	for (int i = 0; i < 100000; i++) {
		num--;
	}
	LeaveCriticalSection(&cs2);
	return 0;
}

void main() {
	InitializeCriticalSection(&cs1);								//����ó�ʼ��
	InitializeCriticalSection(&cs2);								//����ó�ʼ��
	{
		HANDLE hd[N];
		for (int i = 0; i < N; i++) {
			hd[i] = CreateThread(NULL, 0, add, NULL, 0, NULL);		//�����߳�
																	//WaitForSingleObject(hd[i], INFINITE);
		}

		WaitForMultipleObjects(N, hd, TRUE, INFINITE);				//�ȴ�ȫ���˳� 
		printf("num = %d", num);
	}

	{
		HANDLE hd[N];
		for (int i = 0; i < N; i++) {
			hd[i] = CreateThread(NULL, 0, sub, NULL, 0, NULL);		//�����߳�
																	//WaitForSingleObject(hd[i], INFINITE);
		}

		WaitForMultipleObjects(N, hd, TRUE, INFINITE);				//�ȴ�ȫ���˳� 
		printf("num = %d", num);
	}

	DeleteCriticalSection(&cs1);									//�ͷ�
	DeleteCriticalSection(&cs2);									//�ͷ�
	system("pause");
}