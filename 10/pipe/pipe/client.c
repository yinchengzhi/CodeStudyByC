#include<stdio.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
char pipename[128] = "\\\\.\\Pipe\\yinchengzhiPipe";
HANDLE m_pipe = NULL;							//管道的句柄

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
	char str[128] = "扯淡，好好看书";
	int last = 0;
	BOOL res = WriteFile(m_pipe, str, sizeof(str), &last, NULL);
	if (!res)
	{
		printf("写入失败");
	}
}

void main() {

	//NMPWAIT_USE_DEFAULT_WAIT 无限等待
	if (!WaitNamedPipeA(pipename, NMPWAIT_USE_DEFAULT_WAIT)) {
		MessageBoxA(0, "connected No", "connected No", 0);
		return;
	}
	m_pipe = CreateFileA(pipename,				//名称
		GENERIC_WRITE | GENERIC_READ,			//读写
		0,										//共享属性，1独有
		NULL,									//安全属性
		OPEN_EXISTING,							//打开已经存在的
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	system("pause");
	read();
	system("pause");
	write();
	system("pause");
}