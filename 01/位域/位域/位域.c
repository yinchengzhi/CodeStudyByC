#include<stdio.h>
#include<stdlib.h>

//λ���޶����ݵ�λ������Լ�ڴ�
struct MyStruct{
	unsigned int a:5;		//0-31 2^5
	unsigned int b:5;		//1-12 2^4
	unsigned int c:16;		//2^16
};

void main1() {
	struct MyStruct my1,*p;
	p = &my1;
	my1.a = 8;				//��Լ�ڴ� 
	my1.b = 11;
	my1.c = 1999;

	printf("%d\n",sizeof(struct MyStruct));
	printf("%d	%d	%d\n", my1.a, my1.b, my1.c);
	printf("%d	%d	%d\n", p->a, p->b, p->c);
	system("pause");
}

//������ݣ��غϣ����������غ�
struct data{
	unsigned short num1 : 1;		//1 7
	unsigned short num2 : 1;
};


void main2() {
	printf("%d\n", sizeof(struct data));
	struct data data1;
	data1.num1 = 2;			//10 ���ݲ�����Խ��
	printf("%d\n", data1.num1);
	system("pause");
}

struct datas {
	unsigned int num1 : 32;		//1 7
	unsigned short num2 : 1;
};


void main3() {

	//���Ͳ�һ����ѭ�ṹ��Ķ���ԭ��
	printf("%d\n", sizeof(struct datas));
	system("pause");
}

int isit() {
	unsigned short num = 1;			//0000	0000  0000	0001
	return (1 == *((char*)&num));
}


void main() {
	short num = 1;
	printf("%p\n", &num);			//��λ�ڵ��ֽ�
	printf("%d\n", isit());
	//0000	0000  0000  0001

	//0000	0000
	//0000	0001
	
	//0000	0000
	//0000	0001

	system("pause");
}