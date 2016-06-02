#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void main1() {

	for (volatile int i = 0; i < INT_MAX; i++) {			//优化,强制读内存

	}
}


void main() {

	volatile int i = 10;								  //数据被意外改变的时候,强制读内存
	int a = i;
	printf("\ni = %d", a);

	//偷偷改变i的值
	_asm {
		mov dword ptr[ebp - 4],20h						   //16进制20h就是32
	}
	int b = i;
	printf("\ni = %d", b);

	getchar();
}