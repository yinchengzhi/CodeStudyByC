#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

void main() {

	HANDLE mutex = CreateMutexA(NULL, TRUE, name);
	printf("�����ɹ�");
	char ch = getch();

	ReleaseMutex(mutex);						
	printf("����������");
	CloseHandle(mutex);


}