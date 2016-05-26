#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

void run(void *p) {
	MessageBoxA(0, "1", "1", 0);
}

void main1() {

	MessageBoxA(0, "1", "1", 0);

	_beginthread(run, 0, NULL);
	_beginthread(run, 0, NULL);
	_beginthread(run, 0, NULL);

	system("pause");
}