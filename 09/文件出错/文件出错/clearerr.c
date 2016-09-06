#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//perror 提示文件错误信息
//ferror 检测文件异常的作用
//clearerr 清除异常

void main() {

	FILE *pf = fopen("G:\\51.txt", "w");
	if (pf == NULL) {
		perror("\n错误是：");									//提示文件出错信息
	}

	fputs("hello china", pf);
	rewind(pf);													//移动到文件开头

	if (fgetc(pf) == EOF) {										//EOF有两种可能，EOF结束，第二种出错
		if (feof(pf)) {
			printf("读到文件末尾\n");
			clearerr(pf);
		}
		if (ferror(pf)) {
			printf("异常\n");
			clearerr(pf);										//让文件指针回到开头
		}
	}
	
	//int ch = fgetc(pf);
	//if (ch == EOF) {
	//	printf("error");
	//}

	fclose(pf);

	//if (ferror(pf) == 0) {									//文件打开失败的情况下，不让你继续，提示异常
	//	printf("正常\n");
	//}
	//else {
	//	printf("异常\n");
	//}

	//fclose(pf);

	system("pause");
}