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
}myinfo[22];														//22个结构体保存了22个文件的信息


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
	else {

	}
	fclose(pf);
}

void runthreadsearch(void *p) {

}

void main() {

}