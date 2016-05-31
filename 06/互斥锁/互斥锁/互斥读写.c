#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 6400000;
SRWLOCK g_lock;

//ע��

DWORD WINAPI read(void *p) {

	AcquireSRWLockShared(&g_lock);									//��ȡ�ڼ䣬�������ݣ������޷����޸�
	int i = 0;
	while (1) {
		Sleep(1000);
		printf("\n��%d��num=%d",i,num);
		if (i == 20) {
			break;
		}
		i++;
	}
	ReleaseSRWLockShared(&g_lock);
}


//�ı�һ��������ʱ����Ҫ����

DWORD WINAPI go(void *p) {

	AcquireSRWLockExclusive(&g_lock);								//����д��

	printf("\n��ʼд��");

	for (int i = 0; i < 100000; i++) {
		num--;
		//Sleep(10);
	}
	ReleaseSRWLockExclusive(&g_lock);								//Releases a slim reader/writer (SRW) lock that was acquired in exclusive mode.
	printf("\n����д��");

}

void main() {

	InitializeSRWLock(&g_lock);										//��ʼ��

	CreateThread(NULL, 0, read, NULL, 0, NULL);

	HANDLE hd[64];
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, go, NULL, 0, NULL);
	}


	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	
	printf("\nlast = %d", num);

	system("pause");
}