#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
char pipename[128] = "\\\\.\\Pipe\\cloudpipe";
HANDLE m_pipe = NULL;										//管道的句柄

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
	m_pipe = CreateFileA(pipename,							//名称
		GENERIC_WRITE | GENERIC_READ,						//读写
		0,													//共享属性 1，独有
		NULL,												//安全属性
		OPEN_EXISTING,										//打开已经存在的
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (m_pipe == INVALID_HANDLE_VALUE) {
		printf("失败");
		return;
	}

	run();
	char winfo[1024] = { 0 };
	sprintf(winfo, "%d %d", a, b);						   //打印数据
	WriteFile(m_pipe, winfo, strlen(winfo), NULL, NULL);   //写入成功
	memset(winfo, 0, sizeof(winfo));					   //清零
	ReadFile(m_pipe, winfo, 1024, NULL, NULL);			   //读取

	int res;
	sscanf(winfo, "%d", &res);
	printf("%d+%d=%d", a, b, res);


	system("pause");
}