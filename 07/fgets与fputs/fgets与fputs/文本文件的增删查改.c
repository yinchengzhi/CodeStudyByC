#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main_search() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str,127,pfr);					//读取
		char *p = strstr(str, "王鹏飞");
		if (p != NULL) {
			printf("%s", str);
		}
	}

	fclose(pfr);
	fclose(pfw);

	system("pause");
}

void main_modification() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str, 127, pfr);					//读取
		char *p = strstr(str, "王鹏飞");
		if (p != NULL) {
			printf("%s", str);
			fputs("上联：十问赵学辉几多愁. 下联：恰似一群凤姐上青楼. 横批：只能用手\n",pfw);
		}
		else {
			fputs(str, pfw);
		}
	}


	fclose(pfr);
	fclose(pfw);

	remove("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt");					//删除
	rename("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt");		//重命名

	system("pause");
}

void main_delete() {
	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str, 127, pfr);					//读取
		char *p = strstr(str, "赵学辉");
		if (p != NULL) {
												//什么都不写意味着删除
		}
		else {
			fputs(str, pfw);
		}
	}


	fclose(pfr);
	fclose(pfw);

	remove("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt");					//删除
	rename("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt");		//重命名

	system("pause");
}


void main() {
	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "w");

	while (!feof(pfr)) {
		char str[128] = { 0 };
		fgets(str, 127, pfr);					//读取
		char *p = strstr(str, "八问中国男足有多愁");
		if (p != NULL) {
			//fputs("上联：七问王鹏飞有多愁. 下联：好似一群老头逛青楼. 横联: 就是不射\n", pfw);
			fputs(str, pfw);
			fputs("上联：七问王鹏飞有多愁. 下联：好似王鹏飞守青楼. 横联: 就是不射\n", pfw);
		}
		else {
			fputs(str, pfw);
		}
	}


	fclose(pfr);
	fclose(pfw);

	remove("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt");					//删除
	rename("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\temp.txt", "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\吐槽足球.txt");		//重命名

	system("pause");
}