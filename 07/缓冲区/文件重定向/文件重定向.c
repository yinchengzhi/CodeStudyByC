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
	fgets(str,1024,stdin);							//���̾���һ��������ļ�,getsʵ������fgets���������
	fputs(str,stdout);								//��ʾ��Ҳ��һ��������ļ�,putsʵ������fputs���������

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