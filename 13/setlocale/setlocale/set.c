
#pragma setlocale("chinese-simplified")					//���ñ����ļ�Ϊ���ı��룬�������ı���������

#include<Windows.h>
#include<stdio.h>
#include<locale.h>


void main() {

	//setlocale(LC_ALL, "zh-CN");
	wchar_t wstr[100] = L"hello����";
	wprintf(L"%ls", wstr);
	getchar();

}