#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\QQindex8848.txt";

struct {
	char *pfilestart;
	char *pfileend;
	char *pindexfilestart;
	char *pindexfileend;
}infoall = { 0 };

void map1() {
	HANDLE hfile = CreateFileA(path, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);						//打开一个文件
	
	if (hfile == INVALID_HANDLE_VALUE) {
		printf("打开文件失败");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));									//获取文件大小
	
	HANDLE hmap = CreateFileMappingA(hfile, NULL, PAGE_READWRITE | SEC_COMMIT,	//读写
		0,
		GetFileSize(hfile, NULL) + 1,											//大小
		NULL);

	if (hmap == NULL) {
		printf("映射失败");
		CloseHandle(hfile);
		system("pause");
	}

	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	//创建一个指针，存储映射以后的首地址
	if (pvfile == NULL) {
		printf("指针映射失败");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("映射成功");
	char *pstart = pvfile;														//首地址
	char *pend = pstart + GetFileSize(hfile, NULL);								//结束地址

	infoall.pfileend = pend;													//保存地址
	infoall.pfilestart = pstart;					

}

void map2() {
	HANDLE hfile = CreateFileA(indexpath, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);						//打开一个文件

	if (hfile == INVALID_HANDLE_VALUE) {
		printf("打开文件失败");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));									//获取文件大小

	HANDLE hmap = CreateFileMappingA(hfile, NULL, PAGE_READWRITE | SEC_COMMIT,	//读写
		0,
		GetFileSize(hfile, NULL) + 1,											//大小
		NULL);

	if (hmap == NULL) {
		printf("映射失败");
		CloseHandle(hfile);
		system("pause");
	}

	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	//创建一个指针，存储映射以后的首地址
	if (pvfile == NULL) {
		printf("指针映射失败");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("映射成功");
	char *pstart = pvfile;														//首地址
	char *pend = pstart + GetFileSize(hfile, NULL);								//结束地址

	infoall.pindexfileend = pend;													//保存地址
	infoall.pindexfilestart = pstart;
}

void main() {

	map1();
	map2();
	getchar();

}