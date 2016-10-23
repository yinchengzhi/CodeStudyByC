#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define SIZE 4096
LPVOID lpdata = NULL;												//指针标识内存的首地址

void main() {

	if (lpdata != NULL) {
		puts("共享内存存在");
	}

	HANDLE hmap = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL,
		PAGE_READWRITE | SEC_COMMIT, 0, SIZE, "yinchengzhimem");

	if (hmap == NULL) {
		puts("创建失败");
	}
	else {
		//映射文件到指针
		lpdata = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
		
		//char str[100] = "Hello World,hello China";
		//memcpy(lpdata, str, strlen(str) + 1);						//拷贝内存

		int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
		memcpy(lpdata, a, 40);

	}

	system("pause");

	UnmapViewOfFile(lpdata);								    	//解除
	CloseHandle(hmap);

	system("pause");
}