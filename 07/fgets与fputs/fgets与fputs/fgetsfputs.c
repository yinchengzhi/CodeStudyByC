#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


void main1() {

	FILE *pf = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QQpass\\QQpass.txt", "r");
	while (!feof(pf)) {
		char str[256] = { 0 };
		fgets(str, 255, pf);							//读取，读取字符串的首地址,255最大长度，pf文件指针
		printf("%s", str);
	}

	fclose(pf);

	system("pause");
}

void main2() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QQpass\\QQpass.txt", "r");
	FILE *pfw = fopen("f:\\QQpassA.txt", "w");

	//while (!feof(pfr)) {
	//	char str[256] = { 0 };
	//	fgets(str, 255, pfr);							//读取，读取字符串的首地址,255最大长度，pf文件指针
	//	fputs(str, pfw);
	//	printf("%s", str);
	//}

	char str[256] = { 0 };
	while (fgets(str, 255, pfr) != NULL) {				//读取成功. str,读取失败NULL
		//fputs(str, pfw);
		int length = fputs(str, pfw);					//返回值是最后一个字符，出错是EOF
		printf("\n%d", length);
	}

	fclose(pfr);
	fclose(pfw);

	system("f:\\QQpassA.txt");
	system("pause");
}