#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)						//1,2,4,8,16 �ֽڶ��룬����һ���ֽڶ��룬��Լ�ڴ�

//��Լ�ڴ��С

struct MyStruct{
	char ch;
	double db;
};

void main() {

	printf("%d", sizeof(struct MyStruct));



	system("pause");
}