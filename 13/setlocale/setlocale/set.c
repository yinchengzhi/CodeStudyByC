
#pragma setlocale("chinese-simplified")					//设置本个文件为中文编码，按照中文编码来编译

#include<Windows.h>
#include<stdio.h>
#include<locale.h>


void main() {

	//setlocale(LC_ALL, "zh-CN");
	wchar_t wstr[100] = L"hello海华";
	wprintf(L"%ls", wstr);
	getchar();

}