#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//�������ļ�����

//taskkill / f / im ��ɾ��.exe
//del ��ɾ��.exe
//del 1.bat

void main() {
	FILE *pf = fopen("1.bat", "w");
	fputs("taskkill /f /im ��ɾ��.exe\n", pf);
	fputs("del ��ɾ��.exe\n",pf);
	fputs("del 1.bat\n", pf);
	fclose(pf);
	system("1.bat");

	system("pause");
}