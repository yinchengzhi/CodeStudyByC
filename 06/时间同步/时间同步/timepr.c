#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//�ص�����������ָ����Ե���

VOID CALLBACK timerun(void *parg,DWORD timearg,DWORD timehigh) {
	
	DWORD dwindex = *(DWORD*)parg;
	printf("\n��%d��", dwindex);
	//MessageBoxA(0, "1", "2", 0);
}


void main() {

	HANDLE time1 = CreateWaitableTimerA(NULL, TRUE, "haihua");
	if (time1 == NULL) {
		printf("����ʧ��");
	}

	LARGE_INTEGER mytime;
	mytime.QuadPart = -50000000;												//0.1΢����֮һ����

	DWORD dwparam = 1;															//���ö�ʱ��

	if (SetWaitableTimer(time1, &mytime, 1000, timerun, &dwparam, FALSE)) {		//1000���� ѭ��һ��
		printf("�ȴ�5��֮��ʼ�ɻ�");
		for (int i = 0; i < 15; i++,dwparam++) {								//ѭ�����ٴ�
			SleepEx(INFINITE, TRUE);
		}
	}

	if (WaitForSingleObject(time1, INFINITE) == WAIT_OBJECT_0) {
		printf("wait ok!");
	}
	else {
		printf("wait no!");
	}

	CancelWaitableTimer(time1);												  //ȡ����ʱ��
	CloseHandle(time1);

	system("pause");
}