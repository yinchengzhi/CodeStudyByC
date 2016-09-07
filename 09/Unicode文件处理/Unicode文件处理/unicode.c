#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main1() {

	FILE *pf = fopen("G:\\51.txt", "r");
	while (!feof(pf)) {
		char ch = fgetc(pf);
		putchar(ch);
	}

	fclose(pf);
	system("pause");
}


void main() {

	setlocale(LC_ALL, "zh_CN.unicode");
	FILE *pf = _wfopen(L"G:\\51.txt", L"rb");
	while (!feof(pf)) {
		wchar_t ch = fgetwc(pf);							//»ñÈ¡¿í×Ö·û
		putwchar(ch);										//ÏÔÊ¾¿í×Ö·û
	}

	system("pause");
}