#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

void main() {

	HANDLE hSem = CreateSemaphoreA(NULL, 0, 1, name);
	printf("�����ɹ�");
	char ch = getch();

	ReleaseSemaphore(hSem,1,NULL);

	printf("�����ź���");

	CloseHandle(hSem);


}