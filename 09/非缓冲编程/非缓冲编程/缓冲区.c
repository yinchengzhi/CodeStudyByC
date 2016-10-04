#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//fgetc fputc fgets fputs fgetwc fputwc fgetws fputws fread fwrite //缓冲区编程

void main1() {
	FILE *pf = fopen("G:\\5555.txt", "w");

	fputs("Hello Google", pf);						//没有实时的写入

	system("pause");
	fclose(pf);
}


void main() {
	FILE *pf = fopen("G:\\6.txt", "w+");			//w 模式不可写
	fputs("Hello Google", pf);						//没有实时的写入 没有生效
	
	fflush(pf);										//fclose,fflush 缓冲区 生效
	//rewind(pf);
	
	int ch = fgetc(pf);
	if (ch == EOF) {								// EOF 结束，异常
		if (feof(pf)) {
			printf("end");
			clearerr(pf);							//重置文件流状态,文件指针不再前进
		}

		if (ferror(pf)) {
			printf("ferror");
			clearerr(pf);							//ferror重置文件流状态
		}
	}

	//ch = fgetc(pf);
	//putchar(ch);		

	//if (ferror(pf)) {
	//	printf("ferror");
	//}


	printf("\n");

	while (!feof(pf)) {
		ch = fgetc(pf);
		putchar(ch);
	}

	fclose(pf);

	system("pause");
}