#include<stdio.h>
#define 海华找到厕所 10

//	if else,两端编译，体积变大
//	代码编译,有选择的编译，让程序体积变小
void main() {

#if 海华找到厕所==1
	printf("拉");
#else
	printf("憋");

#endif
	getchar();
}