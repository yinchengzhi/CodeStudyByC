#include<stdio.h>

#define f(x) printf("%s",#x);
//x #x "x"

void main1() {

	int num = 0;
	//f("1234");

	f(void);

	getchar();
}

#define a(x) a##x
//a(1)	a1	//胶水

void main2() {

	int a1 = 10;
	int a2 = 20;
	int a3 = 30;
	//a(1) = 39;
	//printf("%d,%d", a(1), a1);
	for (int i = 0; i < 3; i++) {
		//printf("%d\n", a(i));
	}

	getchar();
}

void p1() {
	puts("pp11");
}

void p2() {
	puts("pp22");
}

void p3() {
	puts("pp33");
}

#define p(x) p##x		//两边都有，缺一不可

//	p(1)	p1()
//#define f(x) ##x

#define N(x) #@x
//给x替换成'x'

void main3() {
	
	putchar(N(A));

	getchar();
}

//#define替换，宏函数，宏展开,
//##-链接		#-""		#@-''

void runall() {
	printf("%d", 1000);
}

//#define run(x)		run##x
#define fun(x,y)	   x##y
#define ff(x,y,z)  x##y##z

void main() {

	//run(all)();			//坑爹的胶水
	ff(run, a, ll)();

	getchar();
}
