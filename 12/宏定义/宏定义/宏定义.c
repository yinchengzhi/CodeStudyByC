#include<stdio.h>
#include<stdlib.h>

void show() {
	printf("代码在%d行\n", __LINE__);
	printf("代码编译时间%s %s\n", __DATE__, __TIME__);
	printf("文件名%s\n", __FILE__);
	printf("函数名%s\n", __FUNCTION__);
}


void main() {

	//C语言编译器内置，方便调试

	printf("代码在%d行\n", __LINE__);
	printf("代码编译时间%s %s\n", __DATE__, __TIME__);
	printf("文件名%s\n", __FILE__);
	printf("函数名%s\n", __FUNCTION__);

	show();
	showit();

	getchar();
}