#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//..��һ�� Ŀ¼
//"cmd1=123&cmd2=456&go=%BD%F8%C8%E8"

void main() {
	printf("Content-type:text/html\n\n");			//����
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
	printf("Content-type:text/html\n\n");			//����
	char szpost[256] = { 0 };
	gets_s(szpost, sizeof(szpost));
	printf("%s", szpost);
}


//�ض������
//����

void main1() {
	printf("Content-type:text/html\n\n");			//����

	for (int i = 0; i < 100; i++) {
		printf("�����յ���<br>");
	}
	//system("pause");
}