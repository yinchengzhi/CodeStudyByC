#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 1024*1024*30
char pipename[128] = "\\\\.\\Pipe\\cloudpipeA";
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

	printf("Content-type:text/html\n\n");					//����

	system("ipconfig");										//���������ȶ����أ��ʵ��ж�

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

	int nwrite;
	int nread;
	run();
	char winfo[1024] = { 0 };
	sprintf(winfo, "%d %d", a, b);							    //��ӡ����
	WriteFile(m_pipe, winfo, strlen(winfo), &nwrite, NULL);     //д��ɹ�
	memset(winfo, 0, sizeof(winfo));							//����

	char *pmem = malloc(SIZE);
	memset(pmem, 0, SIZE);
	ReadFile(m_pipe, pmem, SIZE, &nread, NULL);					//��ȡ
	printf("%s", pmem);


	system("pause");
}