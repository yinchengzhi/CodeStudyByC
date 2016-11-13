#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strpath[256] = "kaifang.txt";

char *change(char *str) {
	char *tempstr = malloc(strlen(str) + 1);				//strlen
															//memset(tempstr, 0, sizeof(str) + 1);
	int x = 0, y = 0;
	char assii_1, assii_2;

	while (tempstr[x]) {
		if ((tempstr[x] = str[y]) == '%') {

			//y+1,y+2
			if (str[y + 1] >= 'A') {
				assii_1 = str[y + 1] - 55;
			}
			else {
				assii_1 = str[y + 1] - 48;
			}

			if (str[y + 2] >= 'A') {
				assii_2 = str[y + 2] - 55;
			}
			else {
				assii_2 = str[y + 2] - 48;
			}

			tempstr[x] = assii_1 * 16 + assii_2;
			y += 2;

		}
		x++;
		y++;
	}
	tempstr[x] = '\0';
	return tempstr;
}

void showlist(char str[256]) {
	FILE *pf;												//文件指针
	pf = fopen(strpath, "r");								//读取
	if (pf == NULL) {
		printf("文件打开失败!");
	}
	else {
		//feof(pf)到了文件末尾返回1，否则返回0
		while (!feof(pf)) {									//没有到文件末尾就继续
			char readstr[1024] = { 0 };
			fgets(readstr, 1024, pf);						//读取一行
			char *p = strstr(readstr, str);					//字符串查找
			if (p != NULL) {
				puts(readstr);								//打印
				puts("<br>");
				// fputs(readstr,pfw);						//写入
			}
		}
		fclose(pf);
	}

}

void main() {

	printf("Content-type:text/html\n\n");					//换行
	
	//system("ipconfig");
	system("mkdir 1");
	char szpost[256] = { 0 };
	gets(szpost);
	printf("%s", szpost);

	char *p1 = strchr(szpost, '&');
	if (p1 != NULL) {
		*p1 = '\0';
	}

	printf("<br>%s", szpost + 5);
	printf("<br>%s", change(szpost + 5));

	char *p2 = strchr(p1 + 1, '&');
	if (p2 != NULL) {
		*p2 = '\0';
	}
	printf("<br>%s", p1 + 6);
	printf("<br>%s", change(p1 + 6));

	showlist(change(szpost + 5));


}