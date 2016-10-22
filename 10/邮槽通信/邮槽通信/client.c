#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAILSLOT "\\\\.\\mailslot\\yinchengzhi"

void main() {


	//第一个名称，第二个写入，第三个共享读，打开已经存在的

	HANDLE hmailslot = CreateFileA(MAILSLOT, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hmailslot == INVALID_HANDLE_VALUE) {
		printf("打开失败");
	}

	while (1) {

		system("pause");
		char str[10] = "123456789";
		scanf("%s", str);

		LPBYTE lpmsg = (LPBYTE)str;												//转化了指针类型
		int wok = 0;

		//写入信息，第一个句柄，第二个写入内存首地址，第三个长度，第四个写入成功保存wok里面
		WriteFile(hmailslot, lpmsg, 10, &wok, NULL);

	}

	CloseHandle(hmailslot);											//关闭
	system("pause");

}