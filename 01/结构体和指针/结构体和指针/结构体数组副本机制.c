#include<stdio.h>
#include<stdlib.h>
struct MyStruct
{
	int a[10];
	int length;
};
void change(struct MyStruct s1) {	//副本机制，对于结构体生效(结构体内部有数组，数组生效)
	printf("\nchange %p",s1.a);
	for (int i = 0; i < s1.length; i++) {
		s1.a[i] = i * 3;
		printf("%d ", s1.a[i]);
	}
}

void main1() {
	struct MyStruct s1 = { {1,2,3,4,5,6,7,8,9,10},10 };
	change(s1);
	printf("\nmain %p",s1.a);
	for (int i = 0; i < s1.length; i++) {
		printf("%d ", s1.a[i]);
	}
	system("pause");
}

struct MyStruct testReturn(){				//结构体的返回值也有副本机制
	struct MyStruct s1 = { { 1,2,3,4,5,6,7,8,9,10 },10 };
	printf("%p,%p\n", s1.a,s1.a+1);		    //int *
	printf("%p,%p\n", &s1.a,&s1.a+1);		//int (*) 10

	return s1;
};

typedef int *P;
typedef int A[10];      //先定义变量，再加typedef,变量名就是新类型名

//A returnint() {		//error 函数返回数组
//
//}

void main2X() {
	struct MyStruct s1 = testReturn();
	for (int i = 0; i < s1.length; i++) {
		printf("%d ", s1.a[i]);
	}
	printf("\n\n\n");

	system("pause");
}

struct info{
	char name[10];
	int age;
};


//struct info infos[3]
//struct info infos[]
//struct info *infos

void changeinfo(struct info *infos) {		//数组名作为参数退化为指针可以修改
	//infos = infos + 3;
	infos[1].age = 88;			//修改的是原本
}

//返回数组的话

struct data{
	struct info*p;
	int length;
};

void main3x() {
	struct info infos[3] = { {"fang",18},{"hua",19},{"lin",19} };
	changeinfo(infos);
	for (int i = 0; i < 3; i++) {
		printf("%s,%d\n", infos[i].name, infos[i].age);
	}

	system("pause");
}