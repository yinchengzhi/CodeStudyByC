#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


void main1() {

	FILE *pf = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\Q.txt", "r");

	//char ch = fgetc(pf);
	while (!feof(pf)) {
		char ch = fgetc(pf);										//��ȡ��
		putchar(ch);
	}

	fclose(pf);
	system("pause");
}


void main2() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\Q.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QW1.txt", "w");

	while (!feof(pfr)) {
		char ch = fgetc(pfr);										//��ȡ��
		fputc(ch, pfw);
	}

	fclose(pfr);
	//fclose(pfw);

	system("C:\\Users\\Ollydebug\\Desktop\\test1\\QW1.txt");

	system("pause");
}



void main3() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\Q.exe", "rb");				//��������Ҫ��b
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\fq.exe", "wb");

	while (!feof(pfr)) {
		char ch = fgetc(pfr);										//��ȡ��
		fputc(ch, pfw);
	}

	fclose(pfr);
																					
	fclose(pfw);

	system("C:\\Users\\Ollydebug\\Desktop\\test1\\fq.exe");

	system("pause");
}