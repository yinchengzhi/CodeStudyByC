#include<stdio.h>

//��������Ա������Ա
//��Ա��ַ-�׵�ַ������ǰ��Ա

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