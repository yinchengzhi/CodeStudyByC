#include<stdio.h>
#include<Windows.h>

HANDLE mutex = NULL;											//ָ��
int num = 0;

DWORD WINAPI add(void *p) {
	WaitForSingleObject(mutex, INFINITE);
	for (int i = 0; i < 100000; i++) {
		num++;
	}
	ReleaseMutex(mutex);
}

void main() {

	mutex = CreateMutex(NULL, FALSE, NULL);						//��������
	if (mutex == NULL) {
			//����ʧ��
	}

	HANDLE hd[64];												//�̻߳���,ͬһ����������ֻ�ܽ��64�������õ������ƣ�
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, add, NULL, 0, NULL);
		if (hd[i] == NULL) {
			//����ʧ��
		}
	}

	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	printf("%d\n", num);

	for (int i = 0; i < 64; i++) {
		CloseHandle(hd[i]);										//�ر�ÿһ���߳���Դ
	}

	system("pause");
}