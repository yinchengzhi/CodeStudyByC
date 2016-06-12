#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main1() {

	char str[1024] = { 0 };
	gets(str);
	puts(str);

	system(str);
}

void main2() {

	char str[1024] = { 0 };
	fgets(str,1024,stdin);							//键盘就是一个特殊的文件,gets实际上是fgets的特殊情况
	fputs(str,stdout);								//显示器也是一个特殊的文件,puts实际上是fputs的特殊情况

	system(str);
}

void main() {
	char str[1024] = { 0 };
	//scanf("%s", str);
	//printf("%s", str);

	fscanf(stdin, "%s", str);
	fprintf(stdout, "%s", str);
	fprintf(stderr, "\nerror = %s", str);
	system(str);
}