#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main1() {

	//printf("Hello");
	//fprintf(stdout, "hello");								//printfֻ��fprintf������
	char str[100] = { 0 };
	//scanf("%s", str);
	fscanf(stdin, "a=%s", str);								//���ַ�����ȡ�������̵Ļ�����
	fprintf(stdout, "%s", str);								// int string ӳ�䵽һ���ַ���	��ʾ��������
	getchar();
	system("pause");
}

// 1 mndadmin@yahoo.com.cn		xijiafdjkslafmdlasf

void main2() {

	char str[256] = { 0 };
	{
		int i = 1;
		char email[100] = "mndadmin@yahoo.com.cn";
		char password[100] = "xijiafdjkslafmdlasf";

		sprintf(str, "%d %s %s", i, email, password);
		fprintf(stdout, "\n%s", str);
	}
	{
		int j;
		char emailX[100] = { 0 };
		char passmd5[100] = { 0 };
		sscanf(str, "%d %s %s", &j, emailX, passmd5);
		fprintf(stdout, "\nj = %d emailx = %s passmd5 = %s", j, emailX, passmd5);
	}

	system("pause");
}