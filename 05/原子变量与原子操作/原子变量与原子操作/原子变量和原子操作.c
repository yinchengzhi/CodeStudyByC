#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 0;											//����߳�ͬʱ����һ������,ͬʱд��,���ͻ
//һ���������̰߳�ȫ�����߳�ͬʱ��дû�����
//�ٽ���,event,����
//ԭ�Ӳ������ٶȣ��ٽ�����event������

//ԭ�Ӳ���������������̰߳�ȫ

DWORD WINAPI runX(void *p) {
	for (int i = 0; i < 10000; i++) {
		//num++;												//++ �������
		//InterlockedIncrement(&num);						//num++,���Ǳ�֤�����������Ҳ�������ˣ��������ܼ���
		//InterlockedExchange()
		//InterlockedAnd(&num, 1)							1 + num
		InterlockedExchangeAdd(&num,1);						//num = num + 1
	}
}

void main() {
	HANDLE hd[50];
	for (int i = 0; i < 50; i++) {
		hd[i] = CreateThread(NULL, 0, runX, NULL,0, NULL);
	}

	WaitForMultipleObjects(50, hd, TRUE, INFINITE);
	printf("%d", num);

	system("pause");
}