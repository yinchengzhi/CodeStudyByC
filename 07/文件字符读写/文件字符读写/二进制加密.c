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
			i++;												//读取一个字符前进一次
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
		fseek(pfr, 0, SEEK_END);								//文件指针移动到末尾
		int length = ftell(pfr);								//获取当前文件指针距离开头的长度
	}
}


void main() {

	//run(path, pathjia);
	//run(pathjia, pathjie);
	printf("%d", getfilesizeseek(path));

	system("pause");
}