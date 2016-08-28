#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//读取大数据多少行
//int a[N],堆上
//写入到文件
//索引文件载入内存
//随机读

#define N 15186998

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\BigData_Index.txt";

struct index {
	int *pindex;				//地址
	int length;					//长度
}allindex;

void init(char *path) {

	printf("索引数组开始分配\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));						//分配内存
	printf("索引数组完成分配\n");

	printf("开始读取\n");

	FILE *pf = fopen(path, "rb");									// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {

		int alllength = 0;

		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);

			allindex.pindex[i] = alllength;							//错位 , 从0开始
			int length = strlen(str);
			alllength += length;
			allindex.pindex[i] = alllength;
		}
		fclose(pf);
	}

	printf("结束读取\n");

	printf("开始写入\n");
	FILE *pfw = fopen(indexpath, "wb");								//写入索引
	fwrite(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
	printf("结束写入\n");

	free(allindex.pindex);

	printf("开始读取\n");
	FILE *pfr1 = fopen(indexpath, "rb");							//写入索引
	fread(allindex.pindex, sizeof(int), allindex.length, pfr1);
	fclose(pfr1);
	printf("结束读取\n");

}

void quick() {
	printf("索引数组开始分配\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));						//分配内存
	printf("索引数组完成分配\n");

	printf("开始读取\n");
	FILE *pfr = fopen(indexpath, "rb");								//写入索引
	fread(allindex.pindex, sizeof(int), allindex.length, pfr);
	fclose(pfr);
	printf("结束读取\n");

}

int getN(char *path) {
	int i = -1;
	FILE *pf = fopen(path, "rb");									// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {
		i = 0;
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			i++;
		}
		fclose(pf);
		return i;
	}
}

void main1x() {

	//printf("%d", getN(path));
	//init(path);

	quick();

	FILE *pf = fopen(path, "rb");
	while (1) {
		printf("\n请输入要读取的行数:");
		int num = 0;
		scanf("%d", &num);
		fseek(pf, allindex.pindex[num], SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf);										//读取
		printf("%s", str);
	}

	fclose(pf);


	system("pause");
}

void main() {

	FILE *pf1 = fopen(indexpath, "rb");
	FILE *pf2 = fopen(path, "rb");

	while (1) {
		printf("\n请输入要读取的行数:");
		int num = 0;
		scanf("%d", &num);

		int indexnum = 0;
		fseek(pf1, num * sizeof(int), SEEK_SET);
		fread(&indexnum, sizeof(int), 1, pf1);						//读索引到indexnum

		fseek(pf2, indexnum, SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf2);										//读取
		printf("\n%s", str);
	}

	fclose(pf1);
	fclose(pf2);

	system("pause");
}

