#include<stdio.h>
#include<stdlib.h>

typedef struct MyStruct{
	int num;
	double db;
}myx,mys;

typedef union MyUnion {
	int num;
	double db;
}myy;


typedef struct MyStruct my;			//就是类型的别名
typedef union MyUnion myu;

typedef unsigned long int num1, num2, num3;			//都是类型



void main1() {
	my my1 = { .num = 10,10.9 };
	myx my2 = { 11,11.99 };				//同时初始化
	myu myu1 = { 10 };					//共用体只能对一个变量初始化
	myy myu2 = { .db = 11.9 };			//指定成员赋值
	mys my3 = { 12,12.9 };

	system("pause");
}