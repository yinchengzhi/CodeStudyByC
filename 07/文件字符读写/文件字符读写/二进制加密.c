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

		//EOF不适用于二进制
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

void main() {

	run(path, pathjia);
	run(pathjia, pathjie);

	system("pause");
}