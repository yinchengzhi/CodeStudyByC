#include<stdio.h>
#include<stdlib.h>

//#define N
//
//#ifdef  N
//#error	老板去死，你他妈混蛋
//#endif 

//#error 锄禾日当午学C真他妈苦

//处理变量，宏变量的一些错误

int num = 0;
#define M 10
#define N 0

#if num==1
#error 小伙子你的除数不要写为0，写了哥会溢出的
#endif // N==0


void main() {

	//printf("%d", M / N);

	system("pause");
}