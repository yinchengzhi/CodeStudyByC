#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

struct info{
	char name[100];
	int money;

};

void main() {
	struct info infx[5] = { {"wuwei",1000000},{"zhourifu",1000009} ,{"haihua",9999999},{"fangfang",8888},{"zengbin",99999999} };
	//for (int i = 0; i < 5; i++) {
	//	char money[40] = { 0 };
	//	_itoa(infx[i].money, money, 10);
	//	WritePrivateProfileStringA("hello money", infx[i].name, money,"G:\\1.ini");
		//不指定路径，会写入系统目录
    //}
	for (int i = 0; i < 5; i++) {
		char money[40] = { 0 };												//按照字符串

		//GetPrivateProfileStringA(
		//	_In_opt_ LPCSTR lpAppName,
		//	_In_opt_ LPCSTR lpKeyName,
		//	_In_opt_ LPCSTR lpDefault,
		//	_Out_writes_to_opt_(nSize, return +1) LPSTR lpReturnedString,
		//	_In_     DWORD nSize,
		//	_In_opt_ LPCSTR lpFileName
		//);

		//GetPrivateProfileStringA("hello money", infx[i].name, "NULL", money, 40, "1.ini");

		//printf("\n%s", money);

		//GetPrivateProfileIntA(
		//	_In_     LPCSTR lpAppName,
		//	_In_     LPCSTR lpKeyName,
		//	_In_     INT nDefault,
		//	_In_opt_ LPCSTR lpFileName
		//);

		int num = 0;
		num = GetPrivateProfileIntA("hello money", infx[i].name, num, "G:\\1.ini");			//结果在返回值
		printf("%d\n", num);

	}

	system("pause");
}