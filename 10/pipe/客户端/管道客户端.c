#include<stdio.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
char pipename[128] = "\\\\.\\Pipe\\cloudpipe";
HANDLE m_pipe = NULL;							//管道的句柄

void main() {
	m_pipe = CreateFileA(pipename,				//名称
		GENERIC_WRITE | GENERIC_READ,			//读写
		0,										//共享属性 1，独有
		NULL,									//安全属性
		OPEN_EXISTING,							//打开已经存在的
		FILE_ATTRIBUTE_NORMAL,
		NULL);



	system("pause");
}