#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>


#define runfollowme main

void add(int a, int b);				//载入函数的实体

void runfollowme() {

	int num;						//传递地址,不保留
	//01 0x300500
	//putitout(num);
	//"num"
	printf("hello world");
	add(10, 20);					//呼叫某一个函数
	system("pause");
}