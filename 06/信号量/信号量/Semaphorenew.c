#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 0;

//��������ֻ����һ���߳����У������߳�����
//�ź���������߳����У������߳�����
//�ٽ���,ֻ����һ���߳���������
//ԭ�Ӳ����������ٶ����
//�¼�Ҳ����

DWORD WINAPI add(void *p) {
	HANDLE myhsem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "xiaobin");				//��һ���ź�

	if (myhsem) {

		if (WaitForSingleObject(myhsem, INFINITE) == WAIT_OBJECT_0) {			     //�ȵ����ź�
			for (int i = 0; i < 10000; i++) {
				num++;
			}
			//ReleaseSemaphore(myhsem,1,NULL);
			CloseHandle(myhsem);
		}

	}
	else {
		printf("�ź�����ȡʧ��!\n");
	}
}

void main() {

	//�����źŶ���	0
	HANDLE hSEM = CreateSemaphore(NULL, 0, 1, "xiaobin");								//����һ���źţ���������5
	HANDLE hd[64] = { 0 };
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, add, NULL, 0, NULL);
	}

	Sleep(2000);
	printf("�����߳�");
	ReleaseSemaphore(hSEM, 1, NULL);												//���һ�ηŹ�MAX���߳�

	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	printf("%d", num);

	CloseHandle(hSEM);

	system("pause");
}