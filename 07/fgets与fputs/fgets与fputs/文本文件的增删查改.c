#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main_search() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str,127,pfr);					//��ȡ
		char *p = strstr(str, "������");
		if (p != NULL) {
			printf("%s", str);
		}
	}

	fclose(pfr);
	fclose(pfw);

	system("pause");
}

void main_modification() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str, 127, pfr);					//��ȡ
		char *p = strstr(str, "������");
		if (p != NULL) {
			printf("%s", str);
			fputs("������ʮ����ѧ�Լ����. ������ǡ��һȺ�������¥. ������ֻ������\n",pfw);
		}
		else {
			fputs(str, pfw);
		}
	}


	fclose(pfr);
	fclose(pfw);

	remove("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt");					//ɾ��
	rename("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt");		//������

	system("pause");
}

void main_delete() {
	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str, 127, pfr);					//��ȡ
		char *p = strstr(str, "��ѧ��");
		if (p != NULL) {
												//ʲô����д��ζ��ɾ��
		}
		else {
			fputs(str, pfw);
		}
	}


	fclose(pfr);
	fclose(pfw);

	remove("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt");					//ɾ��
	rename("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt");		//������

	system("pause");
}


void main() {
	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str, 127, pfr);					//��ȡ
		char *p = strstr(str, "�����й������ж��");
		if (p != NULL) {
			//fputs("�����������������ж��. ����������һȺ��ͷ����¥. ����: ���ǲ���\n", pfw);
			fputs(str, pfw);
			fputs("�����������������ж��. ��������������������¥. ����: ���ǲ���\n", pfw);
		}
		else {
			fputs(str, pfw);
		}
	}


	fclose(pfr);
	fclose(pfw);

	remove("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt");					//ɾ��
	rename("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�²�����.txt");		//������

	system("pause");
}