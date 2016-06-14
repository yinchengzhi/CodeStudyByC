#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//非密码加密							txt
//根据密码加密						bin

void jia(char *path,char *newpath) {
	FILE *pfr = fopen(path, "r");
	FILE *pfw = fopen(newpath, "w");

	char ch = 0;

	while ((ch = fgetc(pfr))!=EOF) {								//遇到字符EOF就跳过
		ch += 1;
		fputc(ch, pfw);
	}

	fclose(pfr);
	fclose(pfw);

}

void jie(char *path, char *newpath) {
	FILE *pfr = fopen(path, "r");
	FILE *pfw = fopen(newpath, "w");

	char ch = 0;

	while ((ch = fgetc(pfr))!=EOF) {								//遇到字符EOF就跳过
		ch -= 1;
		fputc(ch, pfw);
	}

	fclose(pfr);
	fclose(pfw);

}

void main() {

	char *path = "C:\\Users\\Ollydebug\\Desktop\\test1\\Q.txt";
	char *pathjia = "C:\\Users\\Ollydebug\\Desktop\\test1\\Qjia.txt";
	char *pathjie = "C:\\Users\\Ollydebug\\Desktop\\test1\\Qjie.txt";
	jia(path, pathjia);
	jie(pathjia, pathjie);

	system("pause");
}



void main4() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\Q.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QTX.txt", "w");

	//最后一个字符EOF
	//while (!feof(pfr)) {
	//	char ch = fgetc(pfr);										//读取，
	//	fputc(ch, pfw);
	//}

	char ch = 0;
	while (ch != EOF) {												//EOF文件结束
		ch = fgetc(pfr);											//读取
		if (ch != EOF) {
			fputc(ch, pfw);
		}
	}

	//while ((ch = fgetc(pfr))!=EOF) {								//遇到字符EOF就跳过
	//	fputc(ch, pfw);
	//}

	fclose(pfr);
	fclose(pfw);

	system("C:\\Users\\Ollydebug\\Desktop\\test1\\QTX.txt");

	system("pause");
}