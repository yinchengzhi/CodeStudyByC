#include<stdio.h>
#include<stdlib.h>

//直接替换，不管37二十一
//一般大写
//经常改变的常量用define

#define N 2+8
//define N (2+8)
#define 四大皆空 void
#define _______ main
#define PI 3.1415
#define A 10;									//连带替换

四大皆空 _______() {

	printf("A=%d\n", 1000);

	//printf("%d\n", A);
	printf("%d\n", N*N);						//2+8*2+8
	printf("%f,%f,%f\n", PI, PI, PI);

	const int num = 10;
	*(int*)&num = 3;							//伪常量
	printf("%d", num);

	system("pause");

}