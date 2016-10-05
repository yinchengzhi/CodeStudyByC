#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<fcntl.h>			//文件打开
#include<sys\stat.h>		//系统底层

//银行数据安全 要求严格
//键盘，鼠标，显卡设备

char path[128] = "G:\\BigDataSort.txt";
char newpath[128] = "G:\\renren.txt";

void main12() {

	int fhdr = _open(path, O_RDONLY);
	int fhdw = _open(newpath, _O_CREAT | O_WRONLY);
	
	if (fhdr == -1 || fhdw == -1) {
		return -1;									//操作失败
	}
	else {
		while (!_eof(fhdr)) {
			char str[256] = { 0 };
			int length = _read(fhdr, str, 256);		//读取
			_write(fhdw, str, length);				//写入
		}

		_close(fhdr);								//文件不可以关闭两次
		_close(fhdw);								//
	}

	system("pause");
}

//fgets
void main() {

	int fhdr = _open(path, O_RDONLY);
	int fhdw = _open(newpath, _O_CREAT | O_WRONLY);

	if (fhdr == -1 || fhdw == -1) {
		return -1;									//操作失败
	}
	else {
		while (!_eof(fhdr)) {
			char str[1024] = { 0 };
			int length = _read(fhdr, str, 1024);	//读取
			char *p = strstr(str, "曾斌");

			if (p) {
				printf("%s\n", str);
			}
		}

		_close(fhdr);								//文件不可以关闭两次
	}

	system("pause");
}