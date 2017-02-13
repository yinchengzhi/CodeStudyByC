#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//满缓冲，满了再写
//行缓冲，一行就写
//无缓冲

//默认的情况，操作系统帮你管理缓冲区
//自己管


//#define _IOFBF 0x0000				full	缓冲区满了再干活
//#define _IOLBF 0x0040				line	行缓冲
//#define _IONBF 0x0004				No		无缓冲


void main() {

	char str[4096] = { 0 };
	setvbuf(stdout, str, _IOLBF, 4096);
	fprintf(stdout, "hello fang\n");
	char *p = strstr(str, "\n");
	if (p != NULL) {
		fflush(stdout);
	}

	//printf("Hello World");

	//fflush(stdout);
	
	system("pause");
}

void main2() {
	FILE *pf = fopen("G:\\缓冲区设置2.txt", "w");
	setvbuf(pf, NULL, _IONBF, 0);

	fputs("1234567890", pf);


	system("pause");
}
