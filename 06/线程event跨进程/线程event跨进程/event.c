#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

//mutex ���Ը�֪��ʧ,event�޷���֪

void main() {

	HANDLE event = CreateEventA(NULL, FALSE, FALSE, name);
	printf("�����ɹ�");
	char ch = getch();

	SetEvent(event);
	printf("����event");
	CloseHandle(event);

	system("pause");
}