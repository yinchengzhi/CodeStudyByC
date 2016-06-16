#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *path = "C:\\Users\\Ollydebug\\Desktop\\test1\\吐槽足球.txt";
char *pathjia = "C:\\Users\\Ollydebug\\Desktop\\test1\\吐槽足球jia.txt";
char *pathjie = "C:\\Users\\Ollydebug\\Desktop\\test1\\吐槽足球jie.txt";


//文本文件		读取	    \r\n -->  \n   写入	\n->\r\n				//获取文件二进制的大小，理论上都用rb
//二进制的方式				 -->\r\n
//读取文件大小,理论上都是rb，如果一定要用r,如果字符等于\n.需要额外++
//int ch = fgetc(pf).	避免字符误操作,溢出
//文本文件加密，所有的字符单一加密方式，可以读写文本进行加密，
//文本文件按照密码加密，不能用文本.	读取	    \r\n -->  \n   写入	\n->\r\n


int getfilesize(char *path) {
	FILE *pf = fopen(path, "rb");									//获取文件二进制的大小，理论上都用rb
	if (pf == NULL) {
		return -1;
	}
	else {
		//fseek(pf, 0, SEEK_END);									//文件指针移动到末尾
		//int length = ftell(pf);
		int length = 0;						
		
		//fgetc会跳过回车
		int ch;
		while ((ch = fgetc(pf))!=EOF) {								//-1 ,'-','1'
			//if (ch == '\n') {
			//	puts("回车");
			//}
			//putchar(ch);
			length++;
		}

		fclose(pf);

		return length;
	}
}

void tbw() {
	FILE *pf = fopen("d:\\1.txt","wb");
	for (int i = 0; i < 5; i++) {
		fputc('A', pf);
	}
	fclose(pf);
}

void tbr() {
	FILE *pf = fopen("d:\\1.txt", "rb");
	char ch;
	while ((ch = fgetc(pf))!=EOF) {
		printf("\n%d", ch);
	}
	fclose(pf);
}


//文本加密
void runjiajie(char *path,char *newpath) {
	FILE *pfr = fopen(path, "r");
	FILE *pfw = fopen(newpath, "w");

	if (pfr == NULL || pfw == NULL) {
		return;
	}
	else {
		int ch;		//避免溢出产生异常
		//-1	char ch^3	
		//100	用char类型来存储可能会产生溢出，所以导致失败
		//99
		while ((ch = fgetc(pfr)) != EOF) {
			fputc(ch ^ 3, pfw);									// ‘A’	\n --> \r\n
		}

		fclose(pfr);
		fclose(pfw);

	}
}


void runjiajiewithpassword(char *path, char *newpath,char *password) {
	FILE *pfr = fopen(path, "rb");
	FILE *pfw = fopen(newpath, "wb");

	if (pfr == NULL || pfw == NULL) {
		return;
	}
	else {

		//110	15	7*15+5

		int alllength = getfilesize(path);						//整体长度
		int passlength = strlen(password);						//密码长度

		printf("\n%d,%d", alllength, passlength);

		for (int i = 0; i < alllength / passlength; i++) {
			for (int k = 0; k < passlength; k++) {
				int ch = fgetc(pfr);
				fputc(ch^password[k], pfw);
			}
		}

		for (int j = 0; j < alllength%passlength; j++) {
			int ch = fgetc(pfr);
			fputc(ch^password[j], pfw);
		}

		fclose(pfr);
		fclose(pfw);

	}
}



int getfilesizet(char *path) {
	FILE *pf = fopen(path, "rb");									//获取文件二进制的大小，理论上都用rb
	if (pf == NULL) {
		return -1;
	}
	else {
		//fseek(pf, 0, SEEK_END);									//文件指针移动到末尾
		//int length = ftell(pf);
		int length = 0;

		//fgetc会跳过回车
		char ch;
		while ((ch = fgetc(pf)) != EOF) {								//-1 ,'-','1'
			if (ch == '\n') {
				puts("回车");
			}
			putchar(ch);
			length++;
		}

		fclose(pf);

		return length;
	}
}


void main() {


	//printf("%d,%d\n", '\r', '\n');

	//tbw();
	//tbr();
	//printf("%d", getfilesize(path));

	runjiajiewithpassword(path, pathjia,"wuwei");
	runjiajiewithpassword(pathjia, pathjie,"wuwei");


	system("pause");
}