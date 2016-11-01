#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 4096
char pipename[128] = "\\\\.\\Pipe\\cloudpipe";
HANDLE m_pipe = NULL;										//�ܵ��ľ��

int a;
int b;
void run() {
	time_t ts;
	unsigned int num = time(&ts);
	srand(num);
	a = rand() % 1000;
	b = rand() % 1000;
}

void main() {
	m_pipe = CreateFileA(pipename,							//����
		GENERIC_WRITE | GENERIC_READ,						//��д
		0,													//�������� 1������
		NULL,												//��ȫ����
		OPEN_EXISTING,										//���Ѿ����ڵ�
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (m_pipe == INVALID_HANDLE_VALUE) {
		printf("ʧ��");
		return;
	}

	run();
	char winfo[1024] = { 0 };
	sprintf(winfo, "%d %d", a, b);						   //��ӡ����
	WriteFile(m_pipe, winfo, strlen(winfo), NULL, NULL);   //д��ɹ�
	memset(winfo, 0, sizeof(winfo));					   //����
	ReadFile(m_pipe, winfo, 1024, NULL, NULL);			   //��ȡ

	int res;
	sscanf(winfo, "%d", &res);
	printf("%d+%d=%d", a, b, res);


	system("pause");
}