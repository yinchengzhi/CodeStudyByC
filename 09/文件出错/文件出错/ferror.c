#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//ferror检测程序异常或者正常
//每读写一次,就产生一个ferror
//0 代表正常，1代表异常

void main2() {
	FILE *pf = fopen("G:\\SmallData.txt", "r");
	if (pf == NULL) {
		printf("open fail!\n");
	}
	else {
		printf("open success!\n");
	}


	if (ferror(pf) == 0) {									//文件打开失败的情况下，不让你继续，提示异常
		printf("正常\n");
	}
	else {
		printf("异常\n");
	}

	fputs("1234", pf);

	if (ferror(pf)==0) {									//文件打开失败的情况下，不让你继续，提示异常
		printf("正常\n");
	}
	else {
		printf("异常\n");
	}


	system("pause");
}