#include<stdio.h>
#include<stdlib.h>

#define X 10
#define Y 20

#define Y 80								//下面屏蔽上面

void main() {

	printf("%d", Y);
	getchar();
}

#pragma push_macro("Y")						//Y的宏进栈,保存原来的宏，仍然生效

#define Y 80								//Y=80生效

#pragma pop_macro("Y")						//Y的宏出栈,取消Y的生效，让原来的Y生效

void main21() {

	printf("\nX=%d", X);					//10
	printf("\nY=%d", Y);					//20

#pragma push_macro("Y")

#define Y 40								//内部屏蔽外部,一直屏蔽
	printf("\nY=%d", Y);

#pragma push_macro("X")						//进栈
	printf("\nX=%d", X);
#define X 80
	printf("\nX=%d", X);
#pragma pop_macro("X");						//出栈
	printf("\nX=%d", X);

#pragma pop_macro("Y");
	printf("\nY=%d", Y);

	system("pause");
}