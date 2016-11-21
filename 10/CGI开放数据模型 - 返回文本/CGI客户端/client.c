#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 1024*1024*30
char pipename[128] = "\\\\.\\Pipe\\cloudpipeA";
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

	printf("Content-type:text/html\n\n");					//换行

	system("ipconfig");										//服务器不稳定因素，适当中断

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

	int nwrite;
	int nread;
	run();
	char winfo[1024] = { 0 };
	sprintf(winfo, "%d %d", a, b);							    //打印数据
	WriteFile(m_pipe, winfo, strlen(winfo), &nwrite, NULL);     //写入成功
	memset(winfo, 0, sizeof(winfo));							//清零

	char *pmem = malloc(SIZE);
	memset(pmem, 0, SIZE);
	ReadFile(m_pipe, pmem, SIZE, &nread, NULL);					//读取
	printf("%s", pmem);


	system("pause");
}