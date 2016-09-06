#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main1() {

	FILE *pf = fopen("G:\\SmallData.txt", "w");
	if (pf == NULL) {
		perror("\n错误是：");									//提示文件出错信息
	}

	fputs("haihua", pf);
	fclose(pf);
	system("pause");
}

