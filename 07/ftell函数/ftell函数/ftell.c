#define _CRT_SECURE_NO_WARNINGS							//去掉安全检查

#include<stdio.h>
#include<stdlib.h>

//ftell函数获取文件指针当前位置相对文件首有多少个字节
//可以获取当前有多少个字节
//一般用于统计文件的大小

void main1() {

	char path[100] = "G:\\MaterialPowerMenu-master.zip";
	FILE *pf = fopen(path, "rb");					//按照二进制的方式进行读取文件，返回文件指针
	if (pf == NULL) {								//打开失败
		printf("文件打开失败!");
		perror("error");							//提示错误信息
	}
	else {
		//定位文件指针到尾部
		fseek(pf, 0, SEEK_END);						//定位到文件的末尾，偏移量为0
		int length = ftell(pf);						//获取文件的长度
		if (length == -1) {
			printf("计算文件长度失败！");
		}
		else {
			printf("当前文件有%d个字节", length);
		}

		fclose(pf);									//关闭文件
	}

	system("pause");
}


void main2() {

	char path[100] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\ftell.txt";

	//Windows下  换行解析为两个字符/r/n
	//Linux下    换行解析为一个字符
	//Windows下  文件不需要结束符,Linux会自动增加一个结束符,结束符占一个字节


	FILE *pf = fopen(path, "rb");					//按照二进制的方式进行读取文件，返回文件指针
	if (pf == NULL) {								//打开失败
		printf("文件打开失败!");
		perror("error");							//提示错误信息
	}
	else {
		//定位文件指针到尾部
		fseek(pf, 0, SEEK_END);						//定位到文件的末尾，偏移量为0
		int length = ftell(pf);						//获取文件的长度
		if (length == -1) {
			printf("计算文件长度失败！");
		}
		else {
			printf("当前文件有%d个字节", length);
		}

		fclose(pf);									//关闭文件
	}

	system("pause");
}



//Linux下的编程

#include<stdio.h>
void main() {

	int length = 0;
	char path[60] = "/home/yincheng/Desktop/1.txt";
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return;
	}
	else {
		fseek(pf, 0, SEEK_END);
		length = ftell(pf);
		if (length == -1) {
			printf("fail!");
		}
		else {
			printf("length=%d", length);
		}

		fclose(pf);
	}
}