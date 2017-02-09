#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//创建数据段
#pragma data_seg("fangfangdata")
int fang = 0;
#pragma data_seg()

#pragma comment(linker,"/SECTION:fangfangdata,RWS")

void main() {

	if (fang>0) {
		printf("程序只能启动一个");
		//system("pause");
		MessageBoxA(0, "no", "no", 0);
		return;
	}

	fang++;


	system("pause");
}