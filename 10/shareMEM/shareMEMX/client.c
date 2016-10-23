#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void main() {

	HANDLE hmapfile = OpenFileMappingA(FILE_MAP_READ, FALSE, "yinchengzhimem");
	if (hmapfile == NULL) {
		printf("开辟失败");
	}

	//创建指针，指向这片内存
	LPVOID lpbase = MapViewOfFile(hmapfile, FILE_MAP_READ, 0, 0, 0);
	if (lpbase == NULL) {
		printf("open失败");
	}

	//printf("%s", (char*)lpbase);								//读取字符串

	int *p = lpbase;
	for (int i = 0; i < 10; i++) {
		printf("%d\n", p[i]);
	}

	UnmapViewOfFile(lpbase);									//解除
	CloseHandle(hmapfile);

	system("pause");
}