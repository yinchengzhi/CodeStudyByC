#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

char *path = "C:\\Users\\Ollydebug\\Desktop\\test1\\Q.exe";
char *pathjia = "C:\\Users\\Ollydebug\\Desktop\\test1\\Qjia.exe";
char *pathjie = "C:\\Users\\Ollydebug\\Desktop\\test1\\Qjie.exe";

void run(char *path, char *newpath) {
	FILE *pfr = fopen(path, "rb");
	FILE *pfw = fopen(newpath, "wb");

	if (pfr == NULL || pfw == NULL) {
		return;
	}
	else {
		char ch;

		//EOF�������ڶ�����
		//while ((ch = fgetc(pfr)) != EOF) {
		//	char newch = ch;
		//	fputc(newch, pfw);
		//}

		while (!feof(pfr)) {
			char ch = fgetc(pfr);
			char newch = ch ^ 3;
			fputc(newch, pfw);
		}

		fclose(pfr);
		fclose(pfw);
	}

}

void runwithpassword(char *path, char *newpath,char *password) {

}

int getfilesize(char *path) {

	int i = -1;
	FILE *pfr = fopen(path, "rb");
	if (pfr == NULL) {
		return -1;
	}
	else {
		while (!feof(pfr)) {
			char ch = fgetc(pfr);
			//if (ch == EOF) {
			//	puts("EOF");
			//}
			i++;												//��ȡһ���ַ�ǰ��һ��
		}
		fclose(pfr);
		return i;
	}

}

int getfilesizeseek(char *path) {
	int i = -1;
	FILE *pfr = fopen(path, "rb");
	if (pfr == NULL) {
		return -1;
	}
	else {
		fseek(pfr, 0, SEEK_END);								//�ļ�ָ���ƶ���ĩβ
		int length = ftell(pfr);								//��ȡ��ǰ�ļ�ָ����뿪ͷ�ĳ���
	}
}


void main() {

	//run(path, pathjia);
	//run(pathjia, pathjie);
	printf("%d", getfilesizeseek(path));

	system("pause");
}