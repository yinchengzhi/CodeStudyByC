#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//..上一层 目录
//"cmd1=123&cmd2=456&go=%BD%F8%C8%E8"

void main() {
	printf("Content-type:text/html\n\n");			//换行
	char szpost[256] = { 0 };
	gets_s(szpost, sizeof(szpost));
	printf("%s", szpost);

	char *p1 = strchr(szpost, '&');

	if (*p1 != NULL) {
		*p1 = '\0';
	}

	printf("<br>%s", szpost + 5);

	//system(szpost + 5);

	char cmd[256] = { 0 };
	sprintf(cmd, "%s> 1.txt", szpost + 5);
	system(cmd);

	FILE *pf = fopen("1.txt", "r");
	while (!feof(pf)) {
		char ch = fgetc(pf);
		if (ch == '\n') {
			printf("<br>");
		}
		else {
			putchar(ch);
		}
	}

	fclose(pf);
}

void main2() {
	printf("Content-type:text/html\n\n");			//换行
	char szpost[256] = { 0 };
	gets_s(szpost, sizeof(szpost));
	printf("%s", szpost);
}


//重定向输出
//输入

void main1() {
	printf("Content-type:text/html\n\n");			//换行

	for (int i = 0; i < 100; i++) {
		printf("锄禾日当午<br>");
	}
	//system("pause");
}