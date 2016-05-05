#include<stdio.h>

//必须整除最宽基本成员
//成员地址-首地址必须可以整除当前成员大小,结构体独有
//不足的填充

struct MyStruct{
	char str[23];	//24
	short db;		//4字节，2short 两者取最短的为最宽
};
struct MyStructX{
	struct MyStruct x;
	char y;					//结构体嵌套情况下，最宽基本成员不局限于当前结构体 
};


void main() {
	printf("%d", sizeof(struct MyStruct));
	system("pause");
}


union MyUnion {
	char str[13];	//13 14
	char db;
};

//共用体宽度就是最长的那个，但是必须整除最宽的那个

void main1() {
	printf("%d", sizeof(union MyUnion));
	system("pause");
}