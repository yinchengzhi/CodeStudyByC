#include<stdio.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 4096
char pipename[128] = "\\\\.\\Pipe\\cloudpipe";
HANDLE m_pipe = NULL;							//�ܵ��ľ��

void main() {
	m_pipe = CreateFileA(pipename,				//����
		GENERIC_WRITE | GENERIC_READ,			//��д
		0,										//�������� 1������
		NULL,									//��ȫ����
		OPEN_EXISTING,							//���Ѿ����ڵ�
		FILE_ATTRIBUTE_NORMAL,
		NULL);



	system("pause");
}