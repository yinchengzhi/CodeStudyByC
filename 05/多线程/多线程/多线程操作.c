#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

//���ᣬ�ⶳ.

void print(void *p) {
	int i = 0;
	while (1) {
		printf("%d\n", i++);
		Sleep(1000);
	}
}

void main0() {

	_beginthread(print, 0, NULL);

	system("pause");

	system("pause");

	system("pause");

	system("pause");
}