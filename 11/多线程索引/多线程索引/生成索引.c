#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\IndexBigData.txt";

#define N 20161124

struct index {
	int *pindex;											//索引内存首地址
	int length;												//长度
}allindex = { 0 };

void init(char *path) {

	printf("\n开始分配");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));				//初始化分配
	printf("\n结束分配");

	printf("\n开始生成");

	FILE *pf = fopen(path, "rb");
	if (pf == NULL) {
		puts("file open fail");
	}
	else {
		int all_length = 0;
		for (int i = 0; i < N; i++) {
			char str[1500] = { 0 };
			fgets(str, 1500, pf);							//获取字符串
			allindex.pindex[i] = all_length;
			int length = strlen(str);
			all_length += length;							//索引位置

		}
		fclose(pf);
	}

	printf("\n结束生成");

	//写入索引
	printf("\n开始写入");
	FILE *pfw = fopen(indexpath, "wb");
	fwrite(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
	printf("\n结束写入");
}

void quick() {
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));				//初始化分配

	FILE *pfw = fopen(indexpath, "rb");
	fread(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
}

struct info{
	int *pstart;											//开始位置
	int length;												//长度
	char findstr[20];										//要查找
	int id;													//

};

void runmem(void *p) {
	FILE *pf = fopen(path, "rb");
	struct info *pi = p;									//指针类型转换
	for (int i = 0; i < pi->length; i++) {
		int tempnum = pi->pstart[i];						//分段
		fseek(pf, allindex.pindex[tempnum], SEEK_SET);		//根据偏移读文件
		char str[512] = { 0 };
		fgets(str, 512, pf);
		char *px = strstr(str, pi->findstr);				//查找

		if (px != NULL) {
			printf("\n%d线程找到%s", pi->id, pi->findstr);	//打印找到的数据
		}

	}

	fclose(pf);
}

void main() {
	quick();												//载入内存
	printf("请输入查询的");
	char str[100] = { 0 };
	scanf("%s", str);

#define nthread 100
	struct info pthread[nthread];							//创建线程使用信息数组

	//100 10*10 9 8*12+4
	if (N%nthread == 0) {
		for (int i = 0; i < nthread; i++) {
			pthread[i].id = i;
			strcpy(pthread[i].findstr, str);
			pthread[i].length = N / nthread;
		}
	}
	else {

	}

	system("pause");
}


void main() {

	quick();

	//init(path);

	FILE *pf = fopen(path, "rb");
	while (1) {
		puts("input\n");
		int num = 0;
		scanf("%d", &num);

		fseek(pf, allindex.pindex[num], SEEK_SET);
		char str[512] = { 0 };
		fgets(str, 512, pf);
		puts(str);										//显示
		//printf("\n%s",str);
	}

	system("pause");
}