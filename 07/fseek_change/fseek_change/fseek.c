#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*
void showp(FILE *p) {
	printf("\n\n");
	printf("\n缓冲区有效数据%d", p->_cnt);
	printf("\n缓冲区指针%p,%c", p->_ptr, *(p->_ptr));
	printf("\n缓冲区开始地址%p", p->_base);
	printf("\n缓冲区的大小%d", p->_bufsiz);
	printf("\n缓冲区的文件描述%d", p->_file);
}

int main() {

	char x;
	showp(stdin);
	x = getchar();
	putchar(x);
	showp(stdin);
	x = getchar();
	showp(stdin);
	x = getchar();
	showp(stdin);
	fflush(stdin);
	showp(stdin);


	char path[150] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.txt";
	FILE *pf = fopen(path, "r");
	while (!feof(pf)) {
		char ch = fgetc(pf);
		showp(pf);
	}

	fclose(pf);


	system("pause");
	return 0;
}

*/

void main2() {

	char path[150] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.txt";
	//FILE *pf = fopen(path, "a+");					//尾部添加,文件指针在尾部
	//FILE *pf = fopen(path, "w+");					//文件指针在头部,清空内容
	FILE *pf = fopen(path, "r+");					//文件指针在头部,不清空内容
	
	fseek(pf, 0, SEEK_END);
	fputs("0000000", pf);

	fflush(pf);										//刷新文件

	//插入
	int length = 10;
	for (int i = 0; i < 10; i++) {

		fseek(pf, -7 - i - 1, SEEK_END);
		int ch = fgetc(pf);
		//#define SEEK_CUR	1	当前
		//#define SEEK_END	2	结束
		//#define SEEK_SET	0	开头

		fseek(pf, -i - 1, SEEK_END);
		fputc(ch,pf);

		fflush(pf);										//刷新文件

	}

	fseek(pf, -17, SEEK_END);						//a+ 文件指针移动无效
													//r+ 文件覆盖
	fputs("abcdefg",pf);

	fclose(pf);

	system("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.txt");
	system("pause");
}