#include<stdio.h>
#include<stdlib.h>

//�ṹ���С���ڵ������г�Ա�Ĵ�С֮��
//char int double float //�������� double��������Ա

//�ṹ��Ĵ�С�������������������Ա
//�ṹ���Ա�ĵ�ַ-�ṹ����׵�ַ = ƫ�����������ǵ�ǰ��Ա��������
//�ṹ��β������Ĳ��֣��ͻᱻ���


//�ṹ����룬ע�⣬��Լ�ڴ�

struct MyStruct{
	char num1;
	double num2;
	int num3;
	char num4;
	double num5;
};


struct MyStructX {
	char num1;
	double num2;			//ֻ��һ��Ԫ�ز����ڶ���
};


int main() {
	struct MyStruct my1;
	printf("%d\n", sizeof(struct MyStructX));
	printf("%d\n", sizeof(short));
	printf("%d\n", &my1);
	printf("%d\n", &my1.num1);        //ȡ���ṹ���Ա�ĵ�ַ
	printf("%d\n", &my1.num2);
	printf("%d\n", &my1.num3);
	printf("%d\n", &my1.num4);
	system("pause");
}