#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

void main() {

	HANDLE mutex = CreateMutexA(NULL, TRUE, name);
	printf("创建成功");
	char ch = getch();

	ReleaseMutex(mutex);						
	printf("触发互斥量");
	CloseHandle(mutex);


}