#include<stdio.h>

#define N 2+8
#define f(x) x*x
#define go(y) printf("%d",y);
#define run() {puts("锄禾日当午1");\
			   puts("锄禾日当午2");\
			   puts("锄禾日当午3");}

#define getmax(x,y) x>y?x:y

//内联函数，#define，提升代码运行速度，节约函数的等待返回的执行时间
//可以多个参数，一行写不下，可以\链接,没有块语句

void main() {

	printf("%d", getmax(10, 20));
	printf("\n%f", getmax(10.1, 20.2));
	//go(1000);
	run();
	//printf("%d", f(N));

	system("pause");
}