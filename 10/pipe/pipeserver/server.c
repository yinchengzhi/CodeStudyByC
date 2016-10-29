#include<stdio.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
char pipename[128] = "\\\\.\\Pipe\\yinchengzhiPipe";
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

	if (m_pipe == NULL) {
		printf("创建失败!");
		return;
	}

	BOOL isconnect = ConnectNamedPipe(m_pipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);		//是否连上
	if (isconnect) {
		MessageBoxA(0, "connected ok", "connected ok", 0);
	}
	else {
		printf("连接失败");
	}

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

void read() {
	char buf[SIZE] = { 0 };
	int last;
	if (!ReadFile(m_pipe, buf, SIZE, &last, NULL)) {
		printf("读取失败");
		return;
	}

	//buf[last] = '\0';

	printf("\nread=%s", buf);
}

void write() {
	char str[128] = "锄禾日当午，管道不好学";
	int last = 0;
	BOOL res = WriteFile(m_pipe, str, sizeof(str), &last, NULL);
	if (!res)
	{
		printf("写入失败");
	}
}

void main() {

	//test();
	start();
	printf("服务器启动\n");

	system("pause");
	write();
	system("pause");
	read();
	system("pause");
}