#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<process.h>
#include<Windows.h>

struct infos{
	char path[256];													//原始
	int id;

	char **g_pp;													//把文件的内容，载入这个地址
	int length;

	char findstr[100];												//查询
}myinfo[22] = { 0 };												//22个结构体保存了22个文件的信息

HANDLE inithd[22] = { 0 };											//22个初始化线程地址
HANDLE findhd[22] = { 0 };											//22个查找线程地址
void runthreadinit(void *p) {
	struct infos *pinfo = p;
	FILE *pf = fopen(pinfo->path, "r");
	if (pf != NULL) {
		int i = 0;													//测试多少行
		while (!feof(pf)) {
			char str[256] = { 0 };
			fgets(str, 256, pf);									//读取
			i++;
		}
		//i 记录行数
		rewind(pf);													//回到行数		fseek(pf,0,SEEK_SET);
		pinfo->g_pp = calloc(i, sizeof(char*));						//分配内存初始化
		pinfo->length = i;											//记录长度

		for (int j = 0; j < i; j++) {
			char str[256] = { 0 };
			fgets(str, 256, pf);									//读取

			int length = strlen(str);
			pinfo->g_pp[j] = calloc(length + 1, sizeof(char));		//分配内存并且初始化

			if (pinfo->g_pp[j] != NULL) {
				strcpy(pinfo->g_pp[j], str);						//拷贝内存
			}
		}

	}
	fclose(pf);

	printf("线程%d init over\n", pinfo->id);
}

void runthreadsearch(void *p) {
	struct infos *pinfo = p;
	for (int i = 0; i < pinfo->length; i++) {
		if (pinfo->g_pp[i] != NULL) {
			char *px = strstr(pinfo->g_pp[i], pinfo->findstr);
			if (px != NULL) {
				printf("\n%s", pinfo->g_pp[i]);
			}
		}
	}

	printf("线程%d find over\n", pinfo->id);
}

void main1x() {

	myinfo[0].id = 1;
	strcpy(myinfo[0].path, "G:\\BigData.txt");
	HANDLE pd1 = _beginthread(runthreadinit, 0, &myinfo[0]);
	WaitForSingleObject(pd1, INFINITE);												//等待
	strcpy(myinfo[0].findstr, "34243524");											//随便检索一个数据

	HANDLE pd2 = _beginthread(runthreadsearch, 0, &myinfo[0]);
	WaitForSingleObject(pd2, INFINITE);

	system("pause");
}

void main() {
	for (int i = 0; i < 22; i++) {
		myinfo[i].id = i + 1;
		sprintf(myinfo[i].path, "G:\\BigData.txt", i + 1);
		strcpy(myinfo[i].findstr, "34243524");
	}

	for (int i = 0; i < 15; i++) {
		inithd[i] = _beginthread(runthreadinit, 0, &myinfo[i]);
	}

	WaitForMultipleObjects(15, inithd, TRUE, INFINITE);					//等待
	system("pause");
	
	for (int i = 0; i < 15; i++) {
		findhd[i] = _beginthread(runthreadsearch, 0, &myinfo[i]);
	}


	system("pause");
}