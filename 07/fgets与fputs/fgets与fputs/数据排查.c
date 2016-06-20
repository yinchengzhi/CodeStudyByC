#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main3() {

	FILE *pf = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QQpass\\QQpass.txt", "r");
	FILE *pfwgood = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QQpass\\QQpassok.txt", "w");
	FILE *pfwbad = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QQpass\\QQpassno.txt", "w");
	while (!feof(pf)) {
		char str[256] = { 0 };
		fgets(str, 255, pf);							//读取，读取字符串的首地址,255最大长度，pf文件指针
		int length = strlen(str);
		if (length >= 50) {
			fputs(str, pfwbad);
		}
		else {
			fputs(str, pfwgood);
		}
	}

	fclose(pf);

	system("pause");
}
