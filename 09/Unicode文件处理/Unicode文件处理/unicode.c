#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//fgetc   fgetwc
//fputc   fputwc
//fgets	  fgetws
//fputs	  fputws
//fprintf fwprintf
//fscanf  fwscanf

//fread	  fwrite

void main1() {

	FILE *pf = fopen("G:\\51.txt", "r");
	while (!feof(pf)) {
		char ch = fgetc(pf);
		putchar(ch);
	}

	fclose(pf);
	system("pause");
}


void main2() {

	setlocale(LC_ALL, "zh_CN.unicode");
	FILE *pfr = _wfopen(L"G:\\51.txt", L"rb");
	FILE *pfw = _wfopen(L"G:\\51copy1.txt", L"wb");
	while (!feof(pfr)) {
		wchar_t ch = fgetwc(pfr);							//»ñÈ¡¿í×Ö·û
		fputwc(ch, pfw);									//¿½±´¿í×Ö·û
		putwchar(ch);										//ÏÔÊ¾¿í×Ö·û
	}

	fclose(pfr);
	fclose(pfw);

	system("G:\\51copy1.txt");
	system("pause");
}



void main3() {

	setlocale(LC_ALL, "zh_CN");
	FILE *pfr = _wfopen(L"G:\\51.txt", L"rb");
	FILE *pfw = _wfopen(L"G:\\51copy.txt", L"wb");
	while (!feof(pfr)) {
		wchar_t wstr[256] = { 0 };
		fgetws(wstr, 256, pfr);
		wprintf(L"%ls", wstr);
		fputws(wstr, pfw);									//¿í×Ö·ûÐ´Èë
	}

	fclose(pfr);
	fclose(pfw);

	system("G:\\51copy.txt");

	system("pause");
}


void main() {

	setlocale(LC_ALL, "zh-CN");
	//wprintf(L"%ls", L"helloÌì³¯");
	wchar_t wstr[100] = { 0 };
	fwscanf(stdin, L"%s", wstr);
	fwprintf(stdout, L"%s%d%s", L"º£»ª", 100, wstr);

	system("pause");
}