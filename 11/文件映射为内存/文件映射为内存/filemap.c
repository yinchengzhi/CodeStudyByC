
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char path[256] = "G:\\BigDataSort.txt";

void main() {
	//路径，读写
	HANDLE hfile = CreateFileA(path,												//打开一个文件
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hfile == INVALID_HANDLE_VALUE) {
		printf("打开失败!");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));

	HANDLE hmap = CreateFileMappingA(hfile,
		NULL,
		PAGE_READWRITE | SEC_COMMIT,												//读写
		0,
		GetFileSize(hfile, NULL) + 1,												//获取文件大小
		NULL);

	if (hmap == NULL) {
		printf("映射失败");
		CloseHandle(hfile);
		system("pause");
	}

	//创建一个指针，存储映射以后的首地址
	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	if (pvfile == NULL) {
		printf("指针映射失败");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("映射成功");

	char *pstart = pvfile;															//首地址
	char *pend = pstart + GetFileSize(hfile, NULL);									//结束地址

	system("pause");
	//for (int i = 0; i < 1000; i++) {
	//	putchar(*(pstart + i));
	//}

	char str[100] = "haihua love fang";
	memcpy(pstart, str, strlen(str));

	system("pause");
	UnmapViewOfFile(pvfile);														//解除映射
	CloseHandle(hmap);

	system("pause");
}