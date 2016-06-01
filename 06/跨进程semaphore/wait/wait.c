#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

void main() {

	HANDLE hsem = OpenSemaphoreA(SEMAPHORE_ALL_ACCESS, TRUE, name);
	if (hsem == NULL) {
		printf("\n打开失败");
		system("pause");
		return;
	}
	printf("\n等待-----------");

	DWORD res = WaitForSingleObject(hsem, 20000);

	switch (res) {
	case WAIT_OBJECT_0:
		printf("\n收到信号---------");
		break;

	case WAIT_TIMEOUT:
		printf("\n超时没有收到---------");
		break;

	case WAIT_ABANDONED:
		printf("\n另外一个进程意外终止---------");
		break;

	default:
		break;

	}

	CloseHandle(hsem);

	system("pause");
}