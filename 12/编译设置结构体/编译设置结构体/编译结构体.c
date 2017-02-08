#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)						//1,2,4,8,16 字节对齐，设置一个字节对齐，节约内存

//节约内存大小

struct MyStruct{
	char ch;
	double db;
};

void main() {

	printf("%d", sizeof(struct MyStruct));



	system("pause");
}