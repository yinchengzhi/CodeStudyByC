#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//批处理文件内容

//taskkill / f / im 自删除.exe
//del 自删除.exe
//del 1.bat

void main() {
	FILE *pf = fopen("1.bat", "w");
	fputs("taskkill /f /im 自删除.exe\n", pf);
	fputs("del 自删除.exe\n",pf);
	fputs("del 1.bat\n", pf);
	fclose(pf);
	system("1.bat");

	system("pause");
}