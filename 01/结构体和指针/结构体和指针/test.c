#include<stdio.h>

//整除最宽成员基本成员
//成员地址-首地址整除当前成员

struct MyStruct{
	char num1;
	double num2;
	int num3;
	char ch1;
	short ch2;
	char newch;
	long long num4;
}s1;

int mainX() {

	printf("%d\n", sizeof(s1));
	printf("%d\n", sizeof(long long));
	system("pause");
}