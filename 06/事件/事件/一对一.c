#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//�������̳߳�ͻ
//�¼�����߳�ͨ��
//�ٽ�������̳߳�ͻ
//ʱ��ͬ���߳�

HANDLE event[5] = { 0 };
HANDLE thread[5] = { 0 };

DWORD WINAPI haihua(void *p) {
	int i = 1;
	printf("\n����%d��˵: i love you fangfang ,please help me debug !", i);
	Sleep(1000);
	SetEvent(event[1]);
	while (++i) {
		WaitForSingleObject(event[0],INFINITE);						//���ߵȴ�һ���ź�
		printf("\n����%d��˵: i love you fangfang ,please help me debug !",i);
		Sleep(1000);
	  //ResetEvent(event[0]);										//�źŸ�λ
		SetEvent(event[1]);
	}
	return 0;
}

DWORD WINAPI wangfang(void *p) {
	int i = 0;
	while (++i) {
		WaitForSingleObject(event[1], INFINITE);					//���ߵȴ�һ���ź�
		printf("\nwangfang%d��˵: sorry , but i love you !",i);
		Sleep(1000);
	  //ResetEvent(event[1]);										//�źŸ�λ
		SetEvent(event[0]);
	}
	return 0;
}

void main() {
	
	//�ڶ�������FALSE�����Զ���TRUE�ֶ���ҪReset
	//���������������źŵ�״̬
	//���ĸ������������
	event[0] = CreateEventA(NULL, FALSE, FALSE, "Hello");
	event[1] = CreateEventA(NULL, FALSE, FALSE, "World");

	thread[0] = CreateThread(NULL, 0, haihua, NULL, 0, NULL);
	thread[1] = CreateThread(NULL, 0, wangfang, NULL, 0, NULL);

	WaitForMultipleObjects(2, thread,TRUE,INFINITE);

	system("pause");
}