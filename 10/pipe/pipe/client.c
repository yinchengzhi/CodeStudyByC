#include<stdio.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 4096
char pipename[128] = "\\\\.\\Pipe\\yinchengzhiPipe";
HANDLE m_pipe = NULL;							//�ܵ��ľ��

void read() {
	char buf[SIZE] = { 0 };
	int last;
	if (!ReadFile(m_pipe, buf, SIZE, &last, NULL)) {
		printf("��ȡʧ��");
		return;
	}

	//buf[last] = '\0';

	printf("\nread=%s", buf);
}

void write() {
	char str[128] = "�������úÿ���";
	int last = 0;
	BOOL res = WriteFile(m_pipe, str, sizeof(str), &last, NULL);
	if (!res)
	{
		printf("д��ʧ��");
	}
}

void main() {

	//NMPWAIT_USE_DEFAULT_WAIT ���޵ȴ�
	if (!WaitNamedPipeA(pipename, NMPWAIT_USE_DEFAULT_WAIT)) {
		MessageBoxA(0, "connected No", "connected No", 0);
		return;
	}
	m_pipe = CreateFileA(pipename,				//����
		GENERIC_WRITE | GENERIC_READ,			//��д
		0,										//�������ԣ�1����
		NULL,									//��ȫ����
		OPEN_EXISTING,							//���Ѿ����ڵ�
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	system("pause");
	read();
	system("pause");
	write();
	system("pause");
}