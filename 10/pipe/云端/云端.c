#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
#define MAX_CONNECT 128
int startthreadnum = 10;												//一开始有0哥线程存在
char pipename[128] = "\\\\.\\Pipe\\cloudpipe";

typedef struct info
{
	HANDLE hthread;
	HANDLE hpipe;
	HANDLE hevent;
}PIPE_ST;

PIPE_ST pipeinst[MAX_CONNECT];										//128个结构体

void start() {
	for (int i = 0; i < startthreadnum; i++) {
		pipeinst[i].hpipe = CreateNamedPipeA(
			pipename,												//管道名称
			PIPE_ACCESS_DUPLEX|FILE_FLAG_OVERLAPPED,				//管道读写属性
			PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,	    //消息模式，读模式，等待模式阻塞
			PIPE_UNLIMITED_INSTANCES,								//最大个数
			0,													//输出缓冲区的大小
			0,													//输入缓冲区的大小
			0,														//超时，无限等待
			NULL);

	}
	printf("server start");
}

void end() {

}

void main() {


	system("pause");
}