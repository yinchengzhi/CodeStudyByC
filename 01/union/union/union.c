#include<stdio.h>
#include<stdlib.h>

//要求一个结构或联合至少有一个成员
union MyUnion{
	int num;
	double db;
};

void main() {

	//printf("%d", sizeof(union MyUnion));	  //长度取最长的
	union MyUnion my1;

	my1.db = 1111111111123.988776;		//穿一条裤子

	printf("%8d %f\n", my1.num, my1.db);	//一个变量的变化会影响另外一个变量
	
	my1.num = -10;
	
	printf("%8d %f\n", my1.num,my1.db);
	system("pause");
}