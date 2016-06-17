#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static char *path = "C:\\Users\\Ollydebug\\Desktop\\test1\\Q.exe";
static char *pathjia = "C:\\Users\\Ollydebug\\Desktop\\test1\\Q改jia.exe";
static char *pathjie = "C:\\Users\\Ollydebug\\Desktop\\test1\\Q改jie.exe";

int getbinsize(char *path) {
	FILE *pfr = fopen(path, "rb");
	if (pfr == NULL) {
		return -1;
	}
	else {
		int length = 0;
		int ch;
		while ((ch = fgetc(pfr))!=EOF) {							//fffffff
			length++;
		}
		return length;
	}
}

void binwithpassword(char *path, char *newpath, char *password) {
	FILE *pfr = fopen(path, "rb");
	FILE *pfw = fopen(newpath, "wb");

	if (pfr == NULL || pfw == NULL) {
		return;
	}
	else {

		int passlength = strlen(password);							//获取密码长度

		int ch;														//ff 55
		int i = 0;													//length - 1

		// 0 1 2 3 
		// 4 5 6 7
		//

		while ((ch = fgetc(pfr)) != EOF) {							//遍历每一个字符
			int newch = ch^password[i%passlength];
			i++;
			//if (i == passlength) {
			//	i = 0;
			//}

			fputc(newch, pfw);

		}

		fclose(pfr);
		fclose(pfw);

	}
}

void main() {

	//printf("%d", getbinsize(path));

	//binwithpassword(path, pathjia, "huahua");
	//binwithpassword(pathjia, pathjie, "huahua");
	char *pathjia = "C:\\Users\\Ollydebug\\Desktop\\test1\\Q改jia.txt";
	binwithpassword(pathjia, "F:\\huahua.exe", "huahua");

	system("pause");
}