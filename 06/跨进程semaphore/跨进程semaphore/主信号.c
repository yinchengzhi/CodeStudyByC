#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

void main() {

	HANDLE hSem = CreateSemaphoreA(NULL, 0, 1, name);
	printf("创建成功");
	char ch = getch();

	ReleaseSemaphore(hSem,1,NULL);

	printf("触发信号量");

	CloseHandle(hSem);


}