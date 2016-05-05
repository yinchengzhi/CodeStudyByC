#include<stdio.h>
#include<stdlib.h>

//位域，限定数据的位数，节约内存
struct MyStruct{
	unsigned int a:5;		//0-31 2^5
	unsigned int b:5;		//1-12 2^4
	unsigned int c:16;		//2^16
};

void main1() {
	struct MyStruct my1,*p;
	p = &my1;
	my1.a = 8;				//节约内存 
	my1.b = 11;
	my1.c = 1999;

	printf("%d\n",sizeof(struct MyStruct));
	printf("%d	%d	%d\n", my1.a, my1.b, my1.c);
	printf("%d	%d	%d\n", p->a, p->b, p->c);
	system("pause");
}

//多个数据，重合，按照类型重合
struct data{
	unsigned short num1 : 1;		//1 7
	unsigned short num2 : 1;
};


void main2() {
	printf("%d\n", sizeof(struct data));
	struct data data1;
	data1.num1 = 2;			//10 数据不可以越界
	printf("%d\n", data1.num1);
	system("pause");
}

struct datas {
	unsigned int num1 : 32;		//1 7
	unsigned short num2 : 1;
};


void main3() {

	//类型不一致遵循结构体的对齐原则
	printf("%d\n", sizeof(struct datas));
	system("pause");
}

int isit() {
	unsigned short num = 1;			//0000	0000  0000	0001
	return (1 == *((char*)&num));
}


void main() {
	short num = 1;
	printf("%p\n", &num);			//低位在低字节
	printf("%d\n", isit());
	//0000	0000  0000  0001

	//0000	0000
	//0000	0001
	
	//0000	0000
	//0000	0001

	system("pause");
}