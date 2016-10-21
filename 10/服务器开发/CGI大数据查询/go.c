#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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

void search(char *path, char *searchstr) {
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		printf("<br>打开失败");
	}
	else {
		while (!feof(pf)) {
			char str[512] = { 0 };
			fgets(str, 512, pf);
			char *p = strstr(str, searchstr);

			if (p != NULL) {
				puts(str);
				puts("<br>");
			}

		}

		fclose(pf);
	}
}


void main() {
	printf("Content-type:text/html\n\n");		//换行

	char szpost[256] = { 0 };
	gets_s(szpost, sizeof(szpost));

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

	char path[256] = "G:\\BigData.txt";
	search(path, change(szpost + 5));						//搜索解码之后的

}

void main123() {

	printf("Content-type:text/html\n\n");		//换行
	char path[256] = "G:\\BigData.txt";
	search(path, "1424543");

}
