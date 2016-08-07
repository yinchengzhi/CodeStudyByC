#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<process.h>
#include<Windows.h>

char *path = "G:\\BigData.txt";
#define N 15186998
char ** g_pp;

struct threads *pthread;

void init(char *path) {

	printf("init start");
	g_pp = malloc(sizeof(char*)*N);

	memset(g_pp, '\0', sizeof(char*)*N);													//清空内容

	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		printf("init fail!");
	}
	else {
		for (int i = 0; i < N; i++) {
			char str[1024] = { 0 };
			fgets(str, 1024, pf);															//读取字符串
			int length = strlen(str);														//获取长度
			if (length >= 1) {
				g_pp[i] = malloc(sizeof(char)*(length + 1));								//分配内存
				memset(g_pp[i], '\0', length + 1);											//清空内容
				if (g_pp[i] != NULL) {
					strcpy(g_pp[i], str);													//拷贝
				}
			}
			else {

			}
		}
		fclose(pf);
	}
	printf("init end");
}

void search(char *str) {
	for (int i = 0; i < N; i++) {
		if (g_pp[i] != NULL) {
			char *p = strstr(g_pp[i], str);
			if (p != NULL) {
				printf("%s\n", g_pp[i]);													//找到打印
			}
		}
	}
}

struct threads {
	char **ppstart;																			//指针数组的起始地址
	int length;
	int id;
	int findnum;
	char *pstr;																				//查找的数据
};

void searchthread(void *p) {
	struct threads *pinfo = p;
	for (int i = 0; i < pinfo->length; i++) {
		if (pinfo->ppstart[i] != NULL) {
			char *p = strstr(pinfo->ppstart[i], pinfo->pstr);								//查找
			if (p != NULL) {
				printf("线程%d找到%s\n", pinfo->id, pinfo->ppstart[i]);						//找到
			}
		}
	}
}


void searchwiththread(char *str) {
	int num = 23;																			//线程是CPU核心的倍数
	pthread = malloc(sizeof(struct threads) * 23);											//堆上开辟内存
	memset(pthread, '\0', sizeof(struct threads) * 23);

	HANDLE *phd = malloc(sizeof(HANDLE) * 23);

	if (N%num == 0) {
		for (int i = 0; i < num; i++) {
			pthread[i].id = i;
			pthread[i].pstr = str;
			pthread[i].length = N/num;														//100 5
			pthread[i].ppstart = g_pp + i*(N / num);										//起始地址
			phd[i] = _beginthread(searchthread, 0, &pthread[i]);							//创建线程
		}
	}
	else {

		//100	9	8*12+4
		for (int i = 0; i < num - 1; i++) {
			pthread[i].id = i;
			pthread[i].pstr = str;
			pthread[i].length = N / (num - 1);												//100 5
			pthread[i].ppstart = g_pp + i*(N / (num - 1));									//起始地址
			phd[i] = _beginthread(searchthread, 0, &pthread[i]);							//创建线程
		}

		{
			int i = num - 1;
			pthread[i].id = i;
			pthread[i].pstr = str;
			pthread[i].length = N % (num - 1);												//100 5
			pthread[i].ppstart = g_pp + i*(N / (num - 1));									//起始地址
			phd[i] = _beginthread(searchthread, 0, &pthread[i]);							//创建线程
			//0 8*12
		}
	}

	WaitForMultipleObjects(num, phd, TRUE, INFINITE);										//等待所有线程退出
}


int getN(char *path) {
	FILE *pf = fopen(path, "r");

	if (pf == NULL) {
		return -1;
	}
	else {
		int i = 0;

		while (!feof(pf)) {
			char str[256] = { 0 };
			fgets(str, 256, pf);
			i++;
		}
		return i;
		fclose(pf);
	}
}

void main() {
	init(path);
	while (1) {
		char str[128] = { 0 };
		scanf("%s", str);
		//search(str);

		searchwiththread(str);

	}

	system("pause");
}