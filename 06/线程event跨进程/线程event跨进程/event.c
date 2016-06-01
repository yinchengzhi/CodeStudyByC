#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

//mutex 可以感知丢失,event无法感知

void main() {

	HANDLE event = CreateEventA(NULL, FALSE, FALSE, name);
	printf("创建成功");
	char ch = getch();

	SetEvent(event);
	printf("触发event");
	CloseHandle(event);

	system("pause");
}