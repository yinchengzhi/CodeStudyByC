#include<stdio.h>
#include<stdlib.h>
union MyUnion {
	int num;
	float f1;
}my2,myX[4],*p1;	//第二种

union{
	int num;
	float f1;
}my3, myX3[5], *px;			//第三种

union {
	int num;
	float f1;
};

void main() {

	printf("%d\n", sizeof(my3));

	union MyUnion my1, my[3], *p2;			//第一种
	//共用体适合，体内变量时时刻刻只有一个存在

	my1.num = 100;
	printf("%d,%f\n", my1.num, my1.f1);
	my1.f1 = 34.897;
	printf("%d,%f", my1.num, my1.f1);

	system("pause");
}