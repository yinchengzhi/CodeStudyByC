#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 6400000;
SRWLOCK g_lock;

//�ı�һ��������ʱ����Ҫ����

DWORD WINAPI go(void *p) {
	AcquireSRWLockExclusive(&g_lock);								//����д��
	for (int i = 0; i < 100000; i++) {
		num--;
	}
	ReleaseSRWLockExclusive(&g_lock);								//
}

void main1() {

	InitializeSRWLock(&g_lock);										//��ʼ��
	HANDLE hd[64];
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, go, NULL,0,NULL);
	}
	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	printf("%d", num);
	system("pause");
}