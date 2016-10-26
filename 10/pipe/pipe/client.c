#include<stdio.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
char pipename[128] = "yinchengpipe";
HANDLE m_pipe = NULL;							//管道的句柄

void start() {
	m_pipe = CreateNamedPipeA(pipename,							//管道名称
		PIPE_ACCESS_DUPLEX,										//管道读写属性
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,	//消息模式，读模式，等待模式阻塞
		PIPE_UNLIMITED_INSTANCES,								//最大个数
		SIZE,													//输出缓冲区的大小
		SIZE,													//输入缓冲区的大小
		0,														//超时，无限等待
		NULL);

}

void test() {
	HANDLE mutex = OpenMutexA(MUTEX_ALL_ACCESS, TRUE, "yinchengzhiserver");
	if (mutex == NULL) {
		mutex = CreateMutexA(NULL, TRUE, "yinchengzhiserver");

	}
	else {
		MessageBoxA(0, "only one", "only one", 0);
		exit(0);
	}

}


void main() {

	test();
	start();

	system("pause");
}