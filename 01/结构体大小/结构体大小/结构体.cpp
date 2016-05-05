#include<stdio.h>
#include<stdlib.h>

//结构体大小大于等于所有成员的大小之和
//char int double float //基本类型 double最宽基本成员

//结构体的大小必须可以整除最宽基本成员
//结构体成员的地址-结构体的首地址 = 偏移量，必须是当前成员的整数倍
//结构体尾部不足的部分，就会被填充


//结构体对齐，注意，节约内存

struct MyStruct{
	char num1;
	double num2;
	int num3;
	char num4;
	double num5;
};


struct MyStructX {
	char num1;
	double num2;			//只有一个元素不存在对齐
};


int main() {
	struct MyStruct my1;
	printf("%d\n", sizeof(struct MyStructX));
	printf("%d\n", sizeof(short));
	printf("%d\n", &my1);
	printf("%d\n", &my1.num1);        //取出结构体成员的地址
	printf("%d\n", &my1.num2);
	printf("%d\n", &my1.num3);
	printf("%d\n", &my1.num4);
	system("pause");
}