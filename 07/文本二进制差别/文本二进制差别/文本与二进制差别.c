#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*
文本文件与二进制文件的区别所在（Windows）
写入的时候文本会将换行符10\n,ASII码解析为回车符 13\r，换行符10\n
读取的时候，会将连在一起的回车符13\r，换行符10\n解析为换行符10

文本文件与二进制文件读写无差别(Linux)
*/


void readfile(char *path) {
	FILE *pf = fopen(path, "rb");					//二进制读取方式读取，原封不动
	char ch;
	fread(&ch, 1, 1, pf);							//读取一个元素
	while (!feof(pf)) {
		printf("%d ", ch);							//打印ASCII码
		fread(&ch, 1, 1, pf);						//读取一个元素
	}

	fclose(pf);										//关闭文件指针
}


void main() {
	char buf[5] = { 10,10,10,10,10 };				//初始化字符数组,每个元素都是换行符10
	FILE *pfa;										//代表文本，ASCII的文本
	FILE *pfb;										//代表bin，二进制的文件
	char patha[40] = "F:\\a.c";						//文本的路径
	char pathb[40] = "F:\\b.c";						//二进制的路径

	pfa = fopen(patha, "w");						//按照二进制文本写入的方式打开文件
	if (pfa == NULL) {
		printf("二进制文件打开失败");
	}
	else {
		fwrite(buf, 1, 5, pfa);
		//写入数组，传入数组首地址,元素大小为1，5个元素以及文件指针
		fclose(pfa);								//关闭文件指针
	}
	pfb = fopen(pathb, "wb");						//按照二进制文本写入的方式打开文件
	if (pfb == NULL) {
		printf("二进制文件打开失败");
	}
	else {
		fwrite(buf, 1, 5, pfa);
		//写入数组，传入数组首地址,元素大小为1，5个元素以及文件指针
		fclose(pfb);								//关闭文件指针
	}

	printf("\n");
	printf("文本写入读取的内容!");
	printf("\n");
	readfile(patha);

	printf("\n");
	printf("二进制写入读取的内容!");
	printf("\n");
	readfile(pathb);

	system("pause");
}