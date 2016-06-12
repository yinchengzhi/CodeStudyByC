#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>



void main1() {

	FILE *pf = fopen("D:\\11.txt", "w");
	fputs("你好，世界", pf);							//缓冲区

	fclose(pf);										//关闭文件的时候，将缓冲区内容写入到文本

	system("pause");
}