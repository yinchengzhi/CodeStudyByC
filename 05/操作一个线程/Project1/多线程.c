#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

//_beginthread	CreateThread  �����߳�
//_endthread	ExitThread,�ڲ�����,teminate�ⲿ	
//SuspendThread(hd);		//����
//ResumeThread(hd);			//�ⶳ

DWORD WINAPI fun(void *p) {
	int i = 0;
	while (++i) {
		printf("\n%d", i);
		if (i > 8000) {
			//_endthread();									//�����߳��ڲ��˳�
			//ExitThread(0);									//�����߳�
		}
	}
	return 0;
}

//���̣߳��������ã�������������߳�

void main() {
	HANDLE hd = CreateThread(NULL, 0, fun, NULL, 0, NULL);

	system("pause");
	SuspendThread(hd);										//����
	system("pause");
	ResumeThread(hd);										//�ⶳ
	system("pause");

	//�ⲿǿ�н����߳�
	TerminateThread(hd,0);
	system("pause");
}