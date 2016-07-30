#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

char *path = "G:\\BigData.txt";				//路径

#define allN 15186998-1
#define Max 37

char **pp = NULL;

int getN() {
	int i = 0;
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			i++;
		}

		fclose(pf);
		return i;
	}
}

int GetMax() {
	int i = -1;
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 37, pf);
			int length = strlen(str);										//获取字符串长度
			if (length > i) {
				i = length;
			}
		}

		fclose(pf);
		return i;
	}
}




void init() {

	pp = (char **)malloc(sizeof(char*)*allN);								//分配一个指针数组

	memset(pp, 0, sizeof(char*)*allN);										//清空内存,清除垃圾内存

	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < allN; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			pp[i] = calloc(strlen(str) + 1, sizeof(char));					//为每一个指针分配内存
			if (pp[i] != NULL) {											//避免内存分配失败
				strcpy(pp[i], str);											//拷贝内存
			}
			else {
				printf("内存失败!");
			}
		}

		printf("内存加载完成!\n");
		fclose(pf);															//关闭文件指针
	}
}

void search(char *searchstr) {
	for (int i = 0; i < allN; i++) {
		if (pp[i] != NULL) {												//为空不必查找

			char *p = strstr(pp[i], searchstr);								//查找
			if (p != NULL) {
				printf("%s\n", pp[i]);										//打印结果
			}
		}
	}
}


void main() {
	//printf("%d", GetMax());

	init();
	int i = 0;
	while (1) {
		char searchstr[100] = { 0 };
		scanf("%s", searchstr);
		search(searchstr);
		i += 1;
		printf("第%d次检索完成",i);
		getchar();

	}


	system("pause");

}