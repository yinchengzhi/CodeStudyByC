#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<fcntl.h>			//文件打开
#include<sys\stat.h>		//系统底层

//银行数据安全 要求严格
//键盘，鼠标，显卡设备

void main1() {

	char str[256] = { 0 };
	scanf("%s", str);

	int fhd = _open("G:\\mem.txt", O_WRONLY | O_CREAT);				//O_CREATE O_WRONLY
	if (fhd == -1) {
		printf("打不开");
	}
	else {
		_write(fhd, str, sizeof(str));								//即刻生效
		_close(fhd);												//关闭文件
	}

	system("pause");
}

void main2() {

	char str[256] = { 0 };
	int fhd = _open("G:\\mem.txt", O_RDONLY | O_TEXT);

	if (fhd == -1) {
		printf("打不开");
	}
	else {
		_read(fhd, str, 256);
		puts(str);
		_close(fhd);												//关闭文件
	}

	system("pause");
}