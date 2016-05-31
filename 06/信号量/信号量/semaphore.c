//�ؿ�������

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define id "haihua"
#define MAX 5

//0		���޵ȴ�

DWORD WINAPI myworker(void *p) {
	int *pint = p;
	printf("\nmyworker %d is running",*pint);

	HANDLE myhsem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE,id);					 //��һ���ź�

	if (myhsem) {																	 //myhsem!=NULL
		printf("\nmyworker %d is waitting", *pint);

		//��ʼ���ź�Ϊ0,Ϊ0������ͻ�����,0���ź�������ȥ
		//WaitForSingle��Ϊ0������£��ź���-1

		if (WaitForSingleObject(myhsem, INFINITE) == WAIT_OBJECT_0) {			     //�ȵ����ź�
			printf("\nmyworker %d is getting", *pint);
			Sleep(3000);

			printf("\nmyworker %d is leaving", *pint);

			ReleaseSemaphore(myhsem, 1, NULL);									     //�ͷ���Դ + 1
			CloseHandle(myhsem);
		}
	}

	return 1;
}

void main1() {

	//�����źŶ���	0
	HANDLE hSEM = CreateSemaphore(NULL, 0, MAX, id);								//����һ���źţ���������5
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	HANDLE hd[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		hd[i] = CreateThread(NULL, 0, myworker, a + i, 0, NULL);
	}

	Sleep(5000); 

	printf("�����߳�");

	ReleaseSemaphore(hSEM,MAX,NULL);												//���һ�ηŹ�MAX���߳�

	WaitForMultipleObjects(10, hd, TRUE, INFINITE);

	CloseHandle(hSEM);

	system("pause");
}