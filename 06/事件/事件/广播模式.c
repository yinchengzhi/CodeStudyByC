
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

////�������̳߳�ͻ
////�¼�����߳�ͨ��
////�ٽ�������̳߳�ͻ
////ʱ��ͬ���߳�

HANDLE event[5] = { 0 };
HANDLE thread[10] = { 0 };

char ch[10] = { 'A','B','C','D','E','F','G','H','I','J' };
char str[256] = { 0 };

DWORD WINAPI haihuagirlfiend(void *p) {
	char *pch = p;
	printf("\n i am %c haihua girlfriend", *pch);

	if (*pch == 'C') {
		MessageBoxA(0, "1", "1", 0);
		sprintf(str, "����Ů�� %c speak xiaohuahua lovely", *pch);
		SetEvent(event[0]);
	}

	int i = 0;
	while (++i) {
		WaitForSingleObject(event[0], INFINITE);
		printf("\nhaihuagirlfriend %c read %s", *pch, str);
		Sleep(1000);
		ResetEvent(event[0]);
	}

	return 1;
}

void main() {

	//�ڶ������������Զ����յ�һ���Զ�����¼���TRUE�ֶ���ҪReset  
	//�ڶ�������FALSE�����Զ���TRUE�ֶ���ҪReset
	//���������������źŵ�״̬
	//���ĸ������������
	event[0] = CreateEventA(NULL, TRUE, FALSE, "msg");							//һֱ�ȴ���Ϣ

	for (int i = 0; i < 10; i++) {
		thread[i] = CreateThread(NULL, 0, haihuagirlfiend, &ch[i], 0, NULL);
	}

	WaitForMultipleObjects(10, thread, TRUE, INFINITE);

	system("pause");
}