
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct index {
	int *pindex;
	int length;
};

#define N 10000000

char **g_pp;														//保存指针数组
char filepath[256];
char sortpath[256];
char indexpath[256];
struct index allindex;												//索引

int getN();															//函数声明
void eatg(char *str);												
void eatN(char *str);