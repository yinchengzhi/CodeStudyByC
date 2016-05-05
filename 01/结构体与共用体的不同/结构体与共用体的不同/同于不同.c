#include<stdio.h>
#include<stdlib.h>

struct MyStruct{
	int num;
	double db;
};

union MyUnion{
	int num;
	double db;
};

void main() {
	
	struct MyStruct mys,*ps;
	union MyUnion myu,*pu;
	printf("%p,%p\n", &mys.num,&mys.db);			//结构体地址不同
	printf("%p,%p\n", &myu.num,&myu.db);			//共用体地址相同

	ps = &mys;
	pu = &myu;
	mys.num;
	(&mys)->num;
	(*(&mys)).num;		//*(&mys)=mys
	ps->num;
	(*ps).num;

	myu.num;
	(&myu)->num;
	(*(&myu)).num;		//	(*&*&*&*&(*(&myu))).num
	system("pause");
}