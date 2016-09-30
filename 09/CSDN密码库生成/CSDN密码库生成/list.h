#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct passinfo{
	char password[20];
	int ci;
	struct passinfo *pNext;
}INFO, *PINFO;


PINFO addback(PINFO phead, char password[20]);						//尾部插入
PINFO sortByci(PINFO phead);										//排序
PINFO sortBypass(PINFO phead);										//排序
PINFO show(PINFO phead);											//显示
int isin(PINFO phead, char password[20]);							//判断存在与否
void writetofile(PINFO phead,char path[100]);						//写入到文件