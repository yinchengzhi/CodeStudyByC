#include<stdio.h>
#include<stdlib.h>
#include<string.h>

													//内联函数，调用，浪费等待返回时间，代码体积小
void run1() {
	puts("123");
}

void run2() {
	puts("123456");
}


#pragma intrinsic(run1,run2)						//设置为内联函数
#pragma intrinsic(memset,strlen)					//设置自定义函数，系统函数为内联函数

void main() {

	run1();
	run2();

#pragma function(run1)								//取消内联函数

	getchar();
}