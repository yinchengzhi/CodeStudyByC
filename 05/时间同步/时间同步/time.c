#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//������ʱ����ֻ������ͬ��ͨ��

void main1() {
	while (1) {
		printf("fang fang!\n");
		Sleep(2000);
	}
	system("pause");
}

void main2() {

	HANDLE timer = CreateWaitableTimer(NULL, TRUE,NULL);			//����һ����ʱ��
	if (timer == NULL) {
		return;
	}
	else {
		LARGE_INTEGER time;
		time.QuadPart = -50000000;									//2��
		//10^-7��				0.1΢��
		SetWaitableTimer(timer, &time, 0, NULL,0,NULL);				//���ö�ʱ���ȴ�2��
		if (WaitForSingleObject(timer, INFINITE) == WAIT_OBJECT_0) {
			printf("�ȴ��ɹ���");
		}
		else {
			printf("�ȴ�ʧ�ܣ�");
		}
	}
	system("pause");
}

HANDLE timer;

DWORD WINAPI go1(void *p) {
	MessageBoxA(0, "1", "1", 0);
	timer = CreateWaitableTimer(NULL, TRUE, NULL);					//����һ����ʱ��
	LARGE_INTEGER time;
	time.QuadPart = -50000000;										//2��
																	//10^-7��				0.1΢��
	SetWaitableTimer(timer, &time, 0, NULL, 0, NULL);				//���ö�ʱ���ȴ�2��
}

DWORD WINAPI go2(void *p) {
	MessageBoxA(0, "2", "2", 0);
	printf("�ȴ��ɹ���");
}

void main() {
	HANDLE hd = CreateThread(NULL, 0, go1, NULL, 0,NULL);
	WaitForSingleObject(hd, INFINITE);
	if (WaitForSingleObject(timer, INFINITE) == WAIT_OBJECT_0) {
		CreateThread(NULL, 0, go2, NULL, 0, NULL);
		printf("�ȴ��ɹ���");
	}
	else {
		printf("�ȴ�ʧ�ܣ�");
	}

	system("pause");
}