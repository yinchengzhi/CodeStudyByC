#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 4096
#define MAX_CONNECT 128
int startthreadnum = 10;												//һ��ʼ��0���̴߳���
char pipename[128] = "\\\\.\\Pipe\\cloudpipe";

typedef struct info
{
	HANDLE hthread;
	HANDLE hpipe;
	HANDLE hevent;
}PIPE_ST;

PIPE_ST pipeinst[MAX_CONNECT];										//128���ṹ��

void start() {
	for (int i = 0; i < startthreadnum; i++) {
		pipeinst[i].hpipe = CreateNamedPipeA(
			pipename,												//�ܵ�����
			PIPE_ACCESS_DUPLEX|FILE_FLAG_OVERLAPPED,				//�ܵ���д����
			PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,	    //��Ϣģʽ����ģʽ���ȴ�ģʽ����
			PIPE_UNLIMITED_INSTANCES,								//������
			0,													//����������Ĵ�С
			0,													//���뻺�����Ĵ�С
			0,														//��ʱ�����޵ȴ�
			NULL);

	}
	printf("server start");
}

void end() {

}

void main() {


	system("pause");
}