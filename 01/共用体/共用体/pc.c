#define  _CRT_SECURE_NO_WARNINGS

struct MyStructX{
	double db;
};

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
union pc{
	struct MyStructX my;
	int num;				//3000
	char price[10];			//联想,戴尔
	char *p;				//分配内存,malloc
}pc2 = {.num=1000};

struct MyStruct{
	union pc pc1;
};


void main() {
	union pc pc1;
	pc1.p = malloc(100);
	strcpy(pc1.p, "海华装的电脑，价格未知");
	union pc pc2 = pc1;				//浅拷贝
	pc2.p = malloc(100);			//深拷贝
	strcpy(pc2.p, pc1.p);
	printf("%s\n%s\n", pc1.p, pc2.p);
	free(pc1.p);
	printf("%s\n%s\n", pc1.p, pc2.p);

	system("pause");
}


void main1() {
	union pc pc1;
	pc1.p = malloc(100);
	strcpy(pc1.p,"海华装的电脑，价格未知");
	pc1.num = 4000;			//改变一个变量,影响整个共用体	

	printf("%s", pc1.p);
	free(pc1.p);			//严重的错误
	system("pause");
}


void main2() {

	//数组初始化的一般形式，变量名和类型名可以重名
	union pc pc1 = { 1000 };
	union pc pc[3] = { { 1000 } ,{ 1000 } ,{ 1000 } };
	union pc *p =(union pc[]){ { 1000 } ,{ 1000 } ,{ 1000 } };

	//pc1++;
	//pc1==pc2;		//共用体可以引用成员不可以引用整体
	//pc1.num++;
	pc1.p = NULL;
	printf("%d", pc1.num);


	system("pause");
}