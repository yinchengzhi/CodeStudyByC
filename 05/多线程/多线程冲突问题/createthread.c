#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>
#include<time.h>

CRITICAL_SECTION cs;										//�ٽ���,����Ϊȫ�ֱ���

int num = 0;												//���̷߳�����ͻ,

															//100����Ҫ1000s		10*100*100

DWORD WINAPI myfun(void *p) {
	for (int i = 0; i < 100; i++) {
		EnterCriticalSection(&cs);						//�����ٽ���
		num++;
		LeaveCriticalSection(&cs);						//��ٽ���
		//Sleep(10);
	}
}

void main() {

	time_t start, end;
	time(&start);

	HANDLE hd[100];											//�߳�����
	for (int i = 0; i < 100; i++) {
		hd[i] = CreateThread(NULL, 0, myfun, NULL, 0, NULL);
		//WaitForSingleObject(hd[i], INFINITE);				//ͬ��
	}

	WaitForMultipleObjects(100, hd, TRUE, INFINITE);		//�ȴ����е��߳��˳�

	time(&end);
	printf("\n%f", difftime(end, start));

	printf("\n%d", num);
	DeleteCriticalSection(&cs);
	system("pause");
}